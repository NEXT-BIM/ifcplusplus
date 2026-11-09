/* -*-c++-*- IfcQuery www.ifcquery.com
*
MIT License

Copyright (c) 2017 Fabian Gerold

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifdef __APPLE__
#include "pstld.h"
#endif

#include <algorithm>
#include <cstring>
#include <execution>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include <IfcBuilding.h>
#include <IfcBuildingStorey.h>
#include <IfcColour.h>
#include <IfcColourOrFactor.h>
#include <IfcColourRgb.h>
#include <IfcCurveStyle.h>
#include <IfcFillAreaStyle.h>
#include <IfcLabel.h>
#include <IfcNormalisedRatioMeasure.h>
#include <IfcPresentationStyle.h>
#include <IfcPresentationStyleAssignment.h>
#include <IfcProductRepresentation.h>
#include <IfcProject.h>
#include <IfcRelAggregates.h>
#include <IfcRelContainedInSpatialStructure.h>
#include <IfcRepresentation.h>
#include <IfcSite.h>
#include <IfcStyledItem.h>
#include <IfcSurfaceStyle.h>
#include <IfcSurfaceStyleElementSelect.h>
#include <IfcSurfaceStyleRendering.h>
#include <IfcTextStyle.h>
#include <ifcpp/IFC4X3/EntityFactory.h>
#include <ifcpp/model/BasicTypes.h>
#include <ifcpp/model/BuildingException.h>
#include <ifcpp/model/BuildingModel.h>
#include <ifcpp/model/UnknownEntityException.h>

#ifdef _MSC_VER
#include <tchar.h>
#include <windows.h>
#endif

#include <external/zippy/zippy.hpp>

#include "ReaderSTEP.h"
#include "ReaderUtil.h"

using namespace IFC4X3;

ReaderSTEP::ReaderSTEP() = default;
ReaderSTEP::~ReaderSTEP() = default;

void ReaderSTEP::loadModelFromFile(const std::string &filePath, shared_ptr<BuildingModel> &targetModel) {
    // if file content needs to be loaded into a plain model, call resetModel() before loadModelFromFile
    std::string ext = getFileExtension(filePath);
    std::string uncompressedFileName = "";
    std::string filePathRead = filePath;

    if (std_iequal(ext, ".ifc")) {
        // ok, nothing to do here
    } else if (std_iequal(ext, ".ifcXML")) {
        // TODO: implement xml reader
        messageCallback("ifcXML not yet implemented", StatusCallback::MESSAGE_TYPE_ERROR, __FUNC__);
        return;
    } else if (std_iequal(ext, ".ifcZIP") || std_iequal(ext, ".zip")) {
        std::stringstream buffer;
        buffer.seekp(0, std::ios::end);
        std::stringstream::pos_type buffer_size = buffer.tellp();

        uncompressedFileName = filePath + "_uncompressed77334.ifc";

        std::shared_ptr<Zippy::ZipArchive> archive(new Zippy::ZipArchive());
        archive->Open(filePath.c_str());

        std::vector<std::string> entryNames = archive->GetEntryNames();
        if (entryNames.size() == 0) {
            return;
        }

        std::string zipcontent = archive->GetEntry(entryNames[0]).GetDataAsString();
        std::ofstream zipFileUncompressed(uncompressedFileName, std::ofstream::out);
        zipFileUncompressed << zipcontent;
        zipFileUncompressed.close();

        std::ifstream infile;
        infile.open(uncompressedFileName.c_str(), std::ifstream::in);

        if (!infile.is_open()) {
            std::stringstream strs;
            strs << "Could not unzip file: " << filePath;
            messageCallback(strs.str(), StatusCallback::MESSAGE_TYPE_ERROR, __FUNC__);
            return;
        }


        filePathRead = uncompressedFileName;
    } else {
        std::stringstream strs;
        strs << "Unsupported file type: " << ext;
        messageCallback(strs.str(), StatusCallback::MESSAGE_TYPE_ERROR, __FUNC__);
        return;
    }

    // open file
    std::ifstream infile;
    infile.open(filePathRead.c_str(), std::ifstream::in);

    if (!infile.is_open()) {
        std::stringstream strs;
        strs << "Could not open file: " << filePathRead.c_str();
        messageCallback(strs.str().c_str(), StatusCallback::MESSAGE_TYPE_ERROR, __FUNC__);
        return;
    }

    // get length of file content
    infile.seekg(0, std::ios::end);
    std::streampos file_end_pos = infile.tellg();
    infile.seekg(0, std::ios::beg);

    loadModelFromStream(infile, file_end_pos, targetModel);
    infile.close();

    if (uncompressedFileName.size() > 0) {
        try {
            std::filesystem::remove(uncompressedFileName);
        } catch (std::exception &e) {
            std::cout << __FUNCTION__ << ": " << __LINE__ << ": exception: " << e.what()
                      << ", input file: " << uncompressedFileName << std::endl;
        }
    }
}

void ReaderSTEP::loadModelFromStream(std::istream &content, std::streampos file_end_pos,
                                     shared_ptr<BuildingModel> &targetModel) {
    int millisecs_begin = clock();

    readHeader(content, targetModel);

    // currently generated IFC classes are IFC4X3, files with older versions are converted. So after loading, the schema
    // is always IFC4X3
    targetModel->setIfcSchemaVersionEnumCurrent(BuildingModel::IFC4X3);
    readData(content, file_end_pos, targetModel);
    targetModel->resolveInverseAttributes();
    targetModel->updateCache();

    int millisecs_end = clock();
    double seconds = (millisecs_end - millisecs_begin) * 0.001;
    double progress = 1.0;
    progressValueCallback(progress, "parse");
}

static void removeComments(std::string &line) {
    for (size_t ii = 0; ii < line.size(); ++ii) {
        size_t found_comment_start = line.find("/*");
        if (found_comment_start == std::string::npos) {
            break;
        }
        size_t found_comment_end = line.find("*/");
        if (found_comment_end != std::string::npos) {
            if (found_comment_end > found_comment_start) {
                line.erase(found_comment_start, found_comment_end - found_comment_start + 2);
            }
        } else {
            line.erase(found_comment_start);
        }
    }
}

void ReaderSTEP::readHeader(std::istream &content, shared_ptr<BuildingModel> &target_model) {
    if (!target_model) {
        throw BuildingException("Model not set.", __FUNC__);
    }

    target_model->setFileHeader("");
    target_model->setFileDescription("");
    target_model->setFileName("");

    std::string line;
    std::string strHeader;
    size_t line_header_start = std::string::npos;
    size_t line_header_end = std::string::npos;
    size_t lineCount = 0;
    bool inComment = false;

    while (!bufferedGetline(content, line).eof()) {
        size_t found_comment_start = line.find("/*");
        if (found_comment_start != std::string::npos) {
            inComment = true;
        }

        if (inComment) {
            size_t found_comment_end = line.find("*/");
            if (found_comment_end != std::string::npos) {
                if (found_comment_start != std::string::npos) {
                    // comment start and end in same line
                    if (found_comment_end > found_comment_start) {
                        inComment = false;
                        line.erase(found_comment_start, found_comment_end - found_comment_start + 2);
                    }
                    // TODO: remove comment from line, and check rest of line
                } else {
                    inComment = false;
                    continue;
                }
            }
        }
        if (inComment) {
            continue;
        }

        if (line_header_start == std::string::npos) {
            size_t found = line.find("HEADER;");
            if (found != std::string::npos) {
                line_header_start = lineCount;
                strHeader += line + '\n';
            }
        } else {
            if (line_header_end == std::string::npos) {
                strHeader += line + '\n';
            }
        }

        if (line_header_end == std::string::npos) {
            size_t found = line.find("ENDSEC;");
            if (found != std::string::npos) {
                line_header_end = lineCount;
                break;
            }
        }

        ++lineCount;
    }

    removeComments(strHeader);
    // NEXT-BIM: upstream sets the current schema version here, which loadModelFromStream overwrites, and leaves the
    // loaded file's at its IFC4X3 default
    BuildingModel::SchemaVersionEnum &loaded_file_version = target_model->getIfcSchemaVersionEnumOfLoadedFile();
    loaded_file_version = BuildingModel::IFC_VERSION_UNDEFINED;
    std::vector<std::string> vec_header;
    std::vector<std::string> vec_header_str;
    vec_header.emplace_back(strHeader);
    decodeArgumentStrings(vec_header, vec_header_str);

    std::string file_header_str;
    if (!vec_header_str.empty()) {
        file_header_str = vec_header_str[0];
    }
    target_model->setFileHeader(file_header_str);

    std::vector<std::string> vec_header_lines;
    // split into lines
    const char *stream_pos = &file_header_str[0];
    const char *last_token = stream_pos;

    if (stream_pos == nullptr) {
        throw BuildingException("Invalid file content, couldn't find HEADER section", __FUNC__);
    }

    while (*stream_pos != '\0') {
        if (*stream_pos == '\'') {
            findEndOfString(stream_pos);
            continue;
        }

        if (*stream_pos == ';') {
            const char *begin_line = last_token;
            std::string single_step_line(begin_line, stream_pos - last_token);
            vec_header_lines.push_back(single_step_line);

            ++stream_pos;
            while (isspace(*stream_pos)) {
                ++stream_pos;
            }
            last_token = stream_pos;

            continue;
        }
        ++stream_pos;
    }

    for (auto header_line : vec_header_lines) {
        if (header_line.find("FILE_DESCRIPTION") != std::string::npos) {
            target_model->setFileDescription(header_line);
            continue;
        }

        if (header_line.find("FILE_NAME") != std::string::npos) {
            target_model->setFileName(header_line);
            continue;
        }

        if (header_line.find("FILE_SCHEMA") != std::string::npos) {
            size_t file_schema_begin = header_line.find("FILE_SCHEMA") + 11;

            std::string file_schema_args = header_line.substr(11);
            size_t find_whitespace = file_schema_args.find(' ');
            while (find_whitespace != std::string::npos) {
                file_schema_args.erase(find_whitespace, 1);
                find_whitespace = file_schema_args.find(L' ');
            }

            if (file_schema_args.empty()) {
                continue;
            }

            if (file_schema_args.at(0) == '(' && file_schema_args.at(file_schema_args.size() - 1) == ')') {
                file_schema_args = file_schema_args.substr(1, file_schema_args.size() - 2);
            }
            if (file_schema_args.at(0) == '(' && file_schema_args.at(file_schema_args.size() - 1) == ')') {
                file_schema_args = file_schema_args.substr(1, file_schema_args.size() - 2);
            }
            if (file_schema_args.at(0) == '\'' && file_schema_args.at(file_schema_args.size() - 1) == '\'') {
                file_schema_args = file_schema_args.substr(1, file_schema_args.size() - 2);
            }

            convertStringToUpperCase(file_schema_args);

            if (file_schema_args.compare("IFC4X3") == 0) {
                loaded_file_version = BuildingModel::IFC4X3;
            } else if (file_schema_args.compare("IFC4X1") == 0) {
                loaded_file_version = BuildingModel::IFC4X1;
            } else if (file_schema_args.compare("IFC4") == 0) {
                loaded_file_version = BuildingModel::IFC4;
            } else if (file_schema_args.substr(0, 6).compare("IFC2X4") == 0) {
                loaded_file_version = BuildingModel::IFC2X4;
            } else if (file_schema_args.substr(0, 6).compare("IFC2X3") == 0) {
                loaded_file_version = BuildingModel::IFC2X3;
            } else if (file_schema_args.substr(0, 6).compare("IFC2X2") == 0) {
                loaded_file_version = BuildingModel::IFC2X2;
            } else if (file_schema_args.substr(0, 5).compare("IFC2X") == 0) {
                loaded_file_version = BuildingModel::IFC2X;
            } else if (file_schema_args.substr(0, 5).compare("IFC20") == 0) {
                loaded_file_version = BuildingModel::IFC2X;
            } else {
                loaded_file_version = BuildingModel::IFC_VERSION_UNKNOWN;
            }
        }
    }
}

void ReaderSTEP::readSingleStepLine(const std::string &line,
                                    std::pair<std::string, shared_ptr<BuildingEntity>> &target_read_object) {
    if (line.empty()) {
        return;
    }
    char *stream_pos = const_cast<char *>(line.c_str());
    while (isspace(*stream_pos)) {
        ++stream_pos;
    }

    if (*stream_pos != '#') {
        return;
    }

    // need at least one integer here
    ++stream_pos;
    if (*stream_pos == '\0') {
        return;
    }

    if (!isdigit(*stream_pos)) {
        return;
    }
    char *begin_id = stream_pos;

    // proceed until end of integer
    ++stream_pos;
    while (*stream_pos != '\0') {
        if (isdigit(*stream_pos)) {
            ++stream_pos;
        } else {
            break;
        }
    }

    const int tag = atoi(std::string(begin_id, stream_pos - begin_id).c_str());

    // skip whitespace
    while (isspace(*stream_pos)) {
        ++stream_pos;
    }

    // next char after whitespace needs to be an "="
    if (*stream_pos != '=') {
        // print error
        return;
    }
    ++stream_pos;

    // skip whitespaces
    while (isspace(*stream_pos)) {
        ++stream_pos;
    }

    // extract keyword
    const char *entity_name_begin = stream_pos;
    while (isalnum(*stream_pos)) {
        ++stream_pos;
    }

    std::string entity_name_upper(entity_name_begin, stream_pos - entity_name_begin);
    convertStringToUpperCase(entity_name_upper);

    // proceed to '('
    if (*stream_pos != '(') {
        while (*stream_pos != '\0') {
            if (*stream_pos == '(') {
                break;
            }
            ++stream_pos;
        }
    }

    if (entity_name_upper.empty()) {
        std::stringstream strs;
        strs << "Could not read STEP line: " << line.c_str();
        messageCallback(strs.str(), StatusCallback::MESSAGE_TYPE_ERROR, __FUNC__);
        return;
    }

    shared_ptr<BuildingEntity> obj(EntityFactory::createEntityObject(entity_name_upper));
    if (obj) {
        obj->m_tag = tag;
        target_read_object.second = obj;
        std::string_view entity_arg(stream_pos, line.size() - (stream_pos - line.c_str()));
        if (entity_arg.size() > 2) {
            if (entity_arg[0] == '(') {
                int end_char_index = (int)entity_arg.size() - 1;

                while (end_char_index > 0 && isspace(entity_arg[end_char_index]))
                    --end_char_index;

                if (entity_arg[end_char_index] == ')') {
                    // semicolon already removed
                    entity_arg = entity_arg.substr(1, end_char_index - 1);
                } else if (entity_arg[end_char_index] == ';') {
                    end_char_index -= 1;
                    while (end_char_index > 0 && isspace(entity_arg[end_char_index]))
                        --end_char_index;

                    if (entity_arg[end_char_index] == ')') {
                        entity_arg = entity_arg.substr(1, end_char_index - 1);
                    }
                }
            }
        }
        target_read_object.first.assign(entity_arg.begin(), entity_arg.end());
    } else {
        throw UnknownEntityException(entity_name_upper);
    }
}

void ReaderSTEP::readEntityArguments(std::vector<std::pair<std::string, shared_ptr<BuildingEntity>>> &vec_entities,
                                     const BuildingModelMapType<int, shared_ptr<BuildingEntity>> &map_entities,
                                     shared_ptr<BuildingModel> &model) {
    // second pass, now read arguments
    // every object can be initialized independently in parallel
    const int num_objects = static_cast<int>(vec_entities.size());
    std::stringstream err;
    std::string ifc_version = model->getIfcSchemaVersionOfLoadedFile();

    // set progress
    double progress = 0.3;
    progressValueCallback(progress, "parse");
    double last_progress = 0.3;
    const BuildingModelMapType<int, shared_ptr<BuildingEntity>> *map_entities_ptr = &map_entities;
    std::unordered_set<int> entityIdNotFoundAll;

    std::mutex mutexProgress;
    std::mutex mutexError;
    std::mutex mutexEntityIdNotFound;
    int i = 0;

#ifdef _DEBUG
    std::unordered_set<std::string> setClassesWithAdjustedArguments;
#endif
// #define _DEBUG_READ_SEQENTIAL
#ifdef _DEBUG_READ_SEQENTIAL
    std::for_each(
        std::execution::seq,
#else
    std::for_each(
        std::execution::par,
#endif
        vec_entities.begin(), vec_entities.end(),
        [&](std::pair<std::string, shared_ptr<BuildingEntity>> &entity_read_object) {
            if (model->isLoadingCancelled()) {
                return;
            }

            const shared_ptr<BuildingEntity> &entity = entity_read_object.second;
            if (!entity) {
                return;
            }
            // Constructing a stream takes MSVC's process-wide locale lock (std::_Lockit) several times, which serializes
            // this loop on Windows when done per entity: one stream per thread, emptied for each entity
            thread_local std::stringstream errorStream;
            errorStream.str({});
            errorStream.clear();
            std::string &argument_str = entity_read_object.first;
            // ids of the entities referenced but not in the file; MSVC allocates for each default constructed
            // unordered_set, so one set per thread, emptied for each entity
            thread_local std::unordered_set<int> entityIdNotFound;
            entityIdNotFound.clear();
            // character decoding happens per string value in readString, after nested lists and select values have
            // been tokenized
            thread_local std::vector<std::string> arguments_decoded;
            arguments_decoded.clear();
            tokenizeEntityArguments(argument_str, arguments_decoded);

            const size_t num_expected_arguments = entity->getNumAttributes();
            if (entity->classID() == IFCCOLOURRGB) {
                if (arguments_decoded.size() < num_expected_arguments) {
                    arguments_decoded.insert(arguments_decoded.begin(), "$");
                }
            } else if (entity->classID() == IFCPRESENTATIONSTYLEASSIGNMENT) {
                if (num_expected_arguments > arguments_decoded.size()) {
                    arguments_decoded.insert(arguments_decoded.begin(), "$");
                }
            } else if (entity->classID() == IFCTRIANGULATEDFACESET) {
                // IFC4: second argument: Closed : OPTIONAL IfcBoolean;
                // Coordinates : IfcCartesianPointList3D;
                // Normals : OPTIONAL LIST [1:?] OF LIST [3:3] OF IfcParameterValue;
                // Closed : OPTIONAL IfcBoolean;
                // CoordIndex : LIST [1:?] OF LIST [3:3] OF IfcPositiveInteger;
                // PnIndex : OPTIONAL LIST [1:?] OF IfcPositiveInteger;

                // IFC4X3 arguments:
                // Coordinates : IfcCartesianPointList3D;
                // Closed : OPTIONAL IfcBoolean;
                // Normals : OPTIONAL LIST [1:?] OF LIST [3:3] OF IfcParameterValue;
                // CoordIndex : LIST [1:?] OF LIST [3:3] OF IfcPositiveInteger;
                // PnIndex : OPTIONAL LIST [1:?] OF IfcPositiveInteger;

                if (arguments_decoded.size() > 2) {
                    if (arguments_decoded[2].compare(".T.") == 0 || arguments_decoded[2].compare(".F.") == 0) {
                        // std::swap(arguments_decoded[2], arguments_decoded[1]);
                    }
                }
            }
#ifdef _DEBUG
            if (entity->classID() == IFCRELVOIDSELEMENT) {
                int tag = entity->m_tag;
            }
            if (entity->m_tag == 5) {
                std::string className = EntityFactory::getStringForClassID(entity->classID());
            }
#endif

            if (num_expected_arguments != arguments_decoded.size()) {
                while (arguments_decoded.size() > num_expected_arguments) {
                    arguments_decoded.pop_back();
                }
                while (arguments_decoded.size() < num_expected_arguments) {
                    arguments_decoded.emplace_back("$");
                }
#ifdef _DEBUG
                std::string className = EntityFactory::getStringForClassID(entity->classID());
                if (setClassesWithAdjustedArguments.find(className) == setClassesWithAdjustedArguments.end()) {
                    // std::cout << "adjusted number of arguments for entity #" << entity->m_tag << "=" << className <<
                    // std::endl;
                    setClassesWithAdjustedArguments.insert(className);
                }
#endif
            }

            try {
                entity->readStepArguments(arguments_decoded, map_entities, errorStream, entityIdNotFound);
            } catch (std::exception &e) {

                const std::lock_guard<std::mutex> lock(mutexError);
                err << "#" << entity->m_tag << "=" << EntityFactory::getStringForClassID(entity->classID()) << ": "
                    << e.what();
            } catch (std::exception *e) {

                const std::lock_guard<std::mutex> lock(mutexError);
                err << "#" << entity->m_tag << "=" << EntityFactory::getStringForClassID(entity->classID()) << ": "
                    << e->what();
            } catch (...) {
                const std::lock_guard<std::mutex> lock(mutexError);
                err << "#" << entity->m_tag << "=" << EntityFactory::getStringForClassID(entity->classID())
                    << " readStepData: error occurred" << std::endl;
            }

            // in case there are unresolved references
            if (!entityIdNotFound.empty()) {
                const std::lock_guard<std::mutex> lock(mutexEntityIdNotFound);
                entityIdNotFoundAll.insert(entityIdNotFound.begin(), entityIdNotFound.end());
            }

            if (errorStream.tellp() > 0) {
                const std::lock_guard<std::mutex> lock(mutexError);
                err << errorStream.str();
            }

            // if (i % 10 == 0)
            {
                progress = 0.3 + 0.6 * double(i) / double(num_objects);
                if (progress - last_progress > 0.03) {
                    const std::lock_guard<std::mutex> lock(mutexProgress);
                    progressValueCallback(progress, "parse");
                    last_progress = progress;
                }
            }

            ++i;
        });

    for (auto it = vec_entities.begin(); it != vec_entities.end(); ++it) {
        if (model->isLoadingCancelled()) {
            vec_entities.clear();
            break;
        }

        std::pair<std::string, shared_ptr<BuildingEntity>> &entity_read_object = *it;
        const shared_ptr<BuildingEntity> &entity = entity_read_object.second;

        if (entity->classID() == IFCSTYLEDITEM) {
            int tag = entity->m_tag;
            shared_ptr<IfcStyledItem> styledItem = dynamic_pointer_cast<IfcStyledItem>(entity);
            if (styledItem) {
                std::vector<shared_ptr<IfcPresentationStyle>> vec_presentationStylesReplaced;
                for (shared_ptr<IfcPresentationStyle> &presentationStyle : styledItem->m_Styles) {
                    if (!presentationStyle) {
                        continue;
                    }

                    shared_ptr<IfcPresentationStyleAssignment> presentationStyleAssignment =
                        dynamic_pointer_cast<IfcPresentationStyleAssignment>(presentationStyle);
                    if (presentationStyleAssignment) {
                        // IFCPRESENTATIONSTYLEASSIGNMENT has been removed in IFC4X3
                        // old:    IfcRepresentationItem  <- IFCSTYLEDITEM ->  IFCPRESENTATIONSTYLEASSIGNMENT ->
                        // IFCSURFACESTYLE new      IfcRepresentationItem  <- IFCSTYLEDITEM ->     [x]   ->
                        // IFCSURFACESTYLE

                        for (shared_ptr<IfcPresentationStyle> &presentationStyle :
                             presentationStyleAssignment->m_Styles) {
                            if (!presentationStyle) {
                                continue;
                            }

                            // ENTITY IfcPresentationStyle ABSTRACT SUPERTYPE OF (ONEOF (IfcCurveStyle ,IfcFillAreaStyle
                            // ,IfcSurfaceStyle ,IfcTextStyle));

                            shared_ptr<IfcSurfaceStyle> surfaceStyle =
                                dynamic_pointer_cast<IfcSurfaceStyle>(presentationStyle);
                            if (surfaceStyle) {
                                vec_presentationStylesReplaced.push_back(surfaceStyle);
                                continue;
                            }

                            shared_ptr<IfcCurveStyle> curveStyle =
                                dynamic_pointer_cast<IfcCurveStyle>(presentationStyle);
                            if (curveStyle) {
                                vec_presentationStylesReplaced.push_back(curveStyle);
                                continue;
                            }

                            shared_ptr<IfcFillAreaStyle> fillAreaStyle =
                                dynamic_pointer_cast<IfcFillAreaStyle>(presentationStyle);
                            if (fillAreaStyle) {
                                vec_presentationStylesReplaced.push_back(fillAreaStyle);
                                continue;
                            }

                            shared_ptr<IfcTextStyle> textStyle = dynamic_pointer_cast<IfcTextStyle>(presentationStyle);
                            if (textStyle) {
                                vec_presentationStylesReplaced.push_back(textStyle);
                                continue;
                            }
                        }
                        continue;
                    }

                    vec_presentationStylesReplaced.push_back(presentationStyle);
                }

                styledItem->m_Styles = vec_presentationStylesReplaced;
            }
        }
    }

    if (!entityIdNotFoundAll.empty()) {
        // unresolved entity references
        err << "Entity with id # ";
        for (auto it = entityIdNotFoundAll.begin(); it != entityIdNotFoundAll.end(); ++it) {
            if (it != entityIdNotFoundAll.begin()) {
                err << ", ";
            }
            err << *it;
        }
        err << "  not found" << std::endl;
    }

    if (err.tellp() > 0) {
        messageCallback(err.str(), StatusCallback::MESSAGE_TYPE_ERROR, __FUNC__);
    }
}

namespace {

// A run of whole statements of the DATA section, read on its own
struct StepStatementRun {
    const char *Begin = nullptr;
    const char *End = nullptr;
    std::vector<std::pair<std::string, shared_ptr<BuildingEntity>>> Entities;
    std::string Errors;
    std::set<std::string> UnknownEntities;
};

// Reads the next statement of [pos, end) into `line` as bufferedGetStepLine (ReaderUtil.cpp) reads it from a stream,
// but appending whole spans instead of a character per streambuf call: up to a ';' out of strings, which ends it along
// with one whitespace character after it, without the line breaks, the spaces and tabs out of strings, and the /* */
// comments out of strings and the whitespace after them. Returns true where bufferedGetStepLine sets eofbit.
bool readStepStatement(const char *&pos, const char *end, std::string &line) {
    line.clear();
    bool in_string = false;
    while (true) {
        const char *span_begin = pos;
        while (pos < end) {
            const char c = *pos;
            if (c == '\'' || c == '\n' || c == '\r' || (!in_string && (c == ';' || c == '/' || c == ' ' || c == '\t')))
                break;
            ++pos;
        }
        line.append(span_begin, pos);
        if (pos == end)
            return line.empty();

        const char c = *pos++;
        switch (c) {
        case ' ':
        case '\t':
            // spaces and tabs between arguments and parentheses are left out, as bufferedGetStepLine does
            break;
        case ';':
            if (pos < end && isspace((unsigned char)*pos))
                ++pos;
            return false;
        case '\'':
            in_string = !in_string;
            line += c;
            break;
        case '/':
            if (pos == end || *pos != '*') {
                line += c;
                break;
            }
            ++pos;
            while (true) {
                if (pos == end)
                    return line.empty();
                if (*pos++ != '*' || pos == end || *pos != '/')
                    continue;
                ++pos;
                // bufferedGetStepLine reads these as char, a 0xFF byte being EOF to it
                while (pos < end && *pos != (char)EOF && isspace(*pos))
                    ++pos;
                if (pos == end || *pos == (char)EOF)
                    return line.empty();
                break;
            }
            break;
        default: // '\n', '\r'
            break;
        }
    }
}

// Where to split the DATA section into about `run_count` runs of whole statements. A statement ends where
// bufferedGetStepLine ends a line: at a ';' out of strings and /* */ comments, the whitespace character after it
// included. Each run then reads the same lines as one reading of the whole section, since bufferedGetStepLine starts
// every line out of strings and comments.
std::vector<const char *> findStepStatementRunStarts(const char *begin, const char *end, size_t run_count) {
    std::vector<const char *> run_starts{begin};
    const size_t run_size = (size_t)(end - begin) / run_count + 1;
    const char *next_split = begin + run_size;
    bool in_string = false;
    for (const char *c = begin; c < end; ++c) {
        if (*c == '\'') {
            in_string = !in_string;
        } else if (in_string) {
            continue;
        } else if (*c == '/' && c + 1 < end && c[1] == '*') {
            const char *comment_end = c + 2;
            while (comment_end + 1 < end && !(comment_end[0] == '*' && comment_end[1] == '/')) {
                ++comment_end;
            }
            if (comment_end + 1 >= end) {
                break;
            }
            c = comment_end + 1;
        } else if (*c == ';' && c >= next_split) {
            const char *run_start = c + 1;
            if (run_start < end && isspace((unsigned char)*run_start)) {
                ++run_start;
            }
            if (run_start < end) {
                run_starts.push_back(run_start);
            }
            next_split = run_start + run_size;
        }
    }
    return run_starts;
}

} // namespace

void ReaderSTEP::readData(std::istream &read_in, std::streampos file_size, shared_ptr<BuildingModel> &model) {
    if (read_in.peek() == EOF) {
        return;
    }
    std::string file_schema_version = model->getIfcSchemaVersionOfLoadedFile();
    messageCallback(std::string("Detected IFC version: ") + file_schema_version,
                    StatusCallback::MESSAGE_TYPE_GENERAL_MESSAGE, __FUNC__);

    std::stringstream err;
    std::set<std::string> unknown_entities;
    std::vector<std::pair<std::string, shared_ptr<BuildingEntity>>> vec_entities;
    try {
        // The DATA section in memory, so that runs of statements can be read in parallel
        std::string data;
        {
            std::streambuf *sb = read_in.rdbuf();
            data.reserve(std::max<std::streamoff>(file_size, 0));
            const size_t block_size = 1 << 20;
            while (true) {
                const size_t data_size = data.size();
                data.resize(data_size + block_size);
                const std::streamsize read_count = sb->sgetn(data.data() + data_size, block_size);
                data.resize(data_size + std::max<std::streamsize>(read_count, 0));
                if (read_count <= 0)
                    break;
            }
        }
        progressValueCallback(0.1, "parse");

        const size_t run_count =
            std::clamp<size_t>(data.size() / (1 << 20), 1, (std::max)(1u, std::thread::hardware_concurrency()) * 8);
        const std::vector<const char *> run_starts =
            findStepStatementRunStarts(data.data(), data.data() + data.size(), run_count);
        std::vector<StepStatementRun> runs(run_starts.size());
        for (size_t run_index = 0; run_index < runs.size(); ++run_index) {
            runs[run_index].Begin = run_starts[run_index];
            runs[run_index].End =
                run_index + 1 < run_starts.size() ? run_starts[run_index + 1] : data.data() + data.size();
        }

        std::for_each(std::execution::par, runs.begin(), runs.end(), [&](StepStatementRun &run) {
            std::stringstream run_err;
            try {
                const char *run_pos = run.Begin;
                std::string line;
                size_t lineCount = 0;
                bool hasMoreLines = true;
                while (hasMoreLines) {
                    if (readStepStatement(run_pos, run.End, line)) {
                        hasMoreLines = false;
                    }

                    std::pair<std::string, shared_ptr<BuildingEntity>> entity_read_obj;
                    try {
                        readSingleStepLine(line, entity_read_obj);
                        if (entity_read_obj.second) {
                            run.Entities.push_back(std::move(entity_read_obj));
                            line = "";
                        }
                    } catch (UnknownEntityException &e) {
                        std::string step_line_fix = line;
                        const std::string &unknown_keyword = e.m_keyword;

                        static const std::map<std::string, std::string> mapFindReplaceTypes = {
                            {"IFCBEAMSTANDARDCASE", "IFCBEAM"},
                            {"IFC2DCOMPOSITECURVE", "IFCCOMPOSITECURVE"},
                            // IfcElectricDistributionPoint	DELETED   ->  IfcFlowController
                            {"IFCELECTRICDISTRIBUTIONPOINT", "IFCFLOWCONTROLLER"},
                            // IFC4 subtypes removed in IFC4X3, with the same attributes as their supertype
                            {"IFCCOLUMNSTANDARDCASE", "IFCCOLUMN"},
                            {"IFCDOORSTANDARDCASE", "IFCDOOR"},
                            {"IFCMEMBERSTANDARDCASE", "IFCMEMBER"},
                            {"IFCOPENINGSTANDARDCASE", "IFCOPENINGELEMENT"},
                            {"IFCPLATESTANDARDCASE", "IFCPLATE"},
                            {"IFCSLABELEMENTEDCASE", "IFCSLAB"},
                            {"IFCSLABSTANDARDCASE", "IFCSLAB"},
                            {"IFCWALLELEMENTEDCASE", "IFCWALL"},
                            {"IFCWINDOWSTANDARDCASE", "IFCWINDOW"},
                        };

                        // replace only the entity keyword, not text inside its arguments
                        auto it_replace = mapFindReplaceTypes.find(unknown_keyword);
                        if (it_replace != mapFindReplaceTypes.end()) {
                            size_t pos1 = step_line_fix.find(it_replace->first);
                            if (pos1 != std::string::npos) {
                                step_line_fix.replace(pos1, it_replace->first.size(), it_replace->second);
                            }
                        }

                        if (step_line_fix.compare(line) != 0) {
                            try {
                                readSingleStepLine(step_line_fix, entity_read_obj);
                                if (entity_read_obj.second) {
                                    run.Entities.push_back(entity_read_obj);
                                    line = "";
                                }
                                continue;
                            } catch (UnknownEntityException &) {
                            }
                        }

                        run.UnknownEntities.insert(unknown_keyword);
                    } catch (std::exception &e) {
                        run_err << e.what();
                    }

                    if (lineCount % 100 == 0 && model->isLoadingCancelled()) {
                        return;
                    }
                    ++lineCount;
                }
            } catch (UnknownEntityException &e) {
                run_err << __FUNC__ << ": unknown entity: " << e.m_keyword.c_str() << std::endl;
            } catch (BuildingException &e) {
                run_err << e.what();
            } catch (std::exception &e) {
                run_err << e.what();
            } catch (...) {
                run_err << __FUNC__ << ": error occurred" << std::endl;
            }
            run.Errors = run_err.str();
        });

        if (model->isLoadingCancelled()) {
            return;
        }
        size_t entity_count = 0;
        for (const StepStatementRun &run : runs) {
            entity_count += run.Entities.size();
        }
        vec_entities.reserve(entity_count);
        for (StepStatementRun &run : runs) {
            std::move(run.Entities.begin(), run.Entities.end(), std::back_inserter(vec_entities));
            err << run.Errors;
            unknown_entities.insert(run.UnknownEntities.begin(), run.UnknownEntities.end());
        }
        progressValueCallback(0.25, "parse");
    } catch (BuildingException &e) {
        err << e.what();
    } catch (std::exception &e) {
        err << e.what();
    } catch (...) {
        err << __FUNC__ << ": error occurred" << std::endl;
    }

    if (!unknown_entities.empty()) {
        std::stringstream err_unknown_entity;
        for (const std::string &unknown_keyword : unknown_entities) {
            err_unknown_entity << "unknown IFC entity: " << unknown_keyword << std::endl;
        }
        messageCallback(err_unknown_entity.str(), StatusCallback::MESSAGE_TYPE_UNKNOWN_ENTITY, __FUNC__);
    }

    // copy entities into map so that they can be found during entity attribute initialization
    BuildingModelMapType<int, shared_ptr<BuildingEntity>> &map_entities = model->getMapIfcEntities();
    map_entities.reserve(map_entities.size() + vec_entities.size());
    for (auto &entity_read_object : vec_entities) {
        shared_ptr<BuildingEntity> entity = entity_read_object.second;

        if (entity) // skip aborted entities
        {
            model->insertEntity(entity);
        }
    }

    try {
        readEntityArguments(vec_entities, map_entities, model);
    } catch (BuildingException &e) {
        err << e.what();
    } catch (std::exception &e) {
        err << e.what();
    } catch (...) {
        err << __FUNC__ << ": error occurred" << std::endl;
    }

    if (err.tellp() > 0) {
        messageCallback(err.str(), StatusCallback::MESSAGE_TYPE_ERROR, __FUNC__);
    }
}
