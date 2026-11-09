cmake_minimum_required (VERSION 3.6...3.9)
project(IfcPlusPlus)

ADD_DEFINITIONS(-DIFCQUERY_STATIC_LIB)
ADD_DEFINITIONS(-D_HAS_AUTO_PTR_ETC=1)
ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)
# ADD_DEFINITIONS(-DENABLE_OPENMP)
ADD_DEFINITIONS(-DGLM_FORCE_CTOR_INIT)
ADD_DEFINITIONS(-DGLM_FORCE_XYZW_ONLY)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD C++23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
	# for vs2017
	set(VC_LIBS Bcrypt.lib)
else(WIN32)
	if(NOT CMAKE_BUILD_TYPE)
		set(CMAKE_BUILD_TYPE "Release")
	endif()

	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
endif(WIN32)

set(IFCPP_SOURCE_FILES
    src/ifcpp/IFC4X3/EntityFactory.cpp
    src/ifcpp/IFC4X3/TypeFactory.cpp
	src/ifcpp/model/BuildingGuid.cpp
    src/ifcpp/model/BuildingModel.cpp
    src/ifcpp/model/UnitConverter.cpp
    src/ifcpp/reader/ReaderSTEP.cpp
    src/ifcpp/reader/ReaderUtil.cpp
   #src/ifcpp/writer/WriterSTEP.cpp
    src/ifcpp/writer/WriterUtil.cpp
	src/ifcpp/geometry/CSG_Adapter.cpp
	src/ifcpp/geometry/CurveConverter.cpp
	src/ifcpp/geometry/GeometryInputData.cpp
	src/ifcpp/geometry/MeshOps.cpp
	src/ifcpp/geometry/MeshSimplifier.cpp
	src/ifcpp/geometry/SolidModelConverter.cpp
	src/external/Carve/src/lib/aabb.cpp
	src/external/Carve/src/lib/carve.cpp
	src/external/Carve/src/lib/convex_hull.cpp
	src/external/Carve/src/lib/csg.cpp
	src/external/Carve/src/lib/csg_collector.cpp
	src/external/Carve/src/lib/edge.cpp
	src/external/Carve/src/lib/face.cpp
	src/external/Carve/src/lib/geom.cpp
	src/external/Carve/src/lib/geom2d.cpp
	src/external/Carve/src/lib/geom3d.cpp
	src/external/Carve/src/lib/intersect.cpp
	src/external/Carve/src/lib/intersect_classify_edge.cpp
	src/external/Carve/src/lib/intersect_classify_group.cpp
	src/external/Carve/src/lib/intersect_debug.cpp
	src/external/Carve/src/lib/intersect_face_division.cpp
	src/external/Carve/src/lib/intersect_group.cpp
	src/external/Carve/src/lib/intersect_half_classify_group.cpp
	src/external/Carve/src/lib/intersection.cpp
	src/external/Carve/src/lib/math.cpp
	src/external/Carve/src/lib/mesh.cpp
	src/external/Carve/src/lib/octree.cpp
	src/external/Carve/src/lib/pointset.cpp
	src/external/Carve/src/lib/polyhedron.cpp
	src/external/Carve/src/lib/polyline.cpp
	src/external/Carve/src/lib/shewchuk_predicates.cpp
	src/external/Carve/src/lib/tag.cpp
	src/external/Carve/src/lib/timing.cpp
	src/external/Carve/src/lib/triangle_intersection.cpp
	src/external/Carve/src/lib/triangulator.cpp
	src/external/Carve/src/common/geometry.cpp
	src/external/zip-master/zip.c
)

if (MSVC)
	set_source_files_properties(src/ifcpp/IFC4X3/EntityFactory.cpp PROPERTIES COMPILE_FLAGS /bigobj)
	set_source_files_properties(src/ifcpp/IFC4X3/TypeFactory.cpp PROPERTIES COMPILE_FLAGS /bigobj)
endif()

# The debug geometry dump (GeomDebugDump.h, debug builds) constructs a WriterSTEP: Linux loads the app library with
# every symbol resolved, so the writer's vtable must exist there
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    list(APPEND IFCPP_SOURCE_FILES src/ifcpp/writer/WriterSTEP.cpp)
endif()
add_library(IfcPlusPlus STATIC ${IFCPP_SOURCE_FILES})
target_compile_definitions(IfcPlusPlus PUBLIC IFCQUERY_STATIC_LIB=1)

find_package(miniz CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE miniz::miniz)

if(APPLE)
target_compile_options(${PROJECT_NAME} PUBLIC "-fexperimental-library")
find_package(pstld CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC pstld::pstld)
endif()

TARGET_INCLUDE_DIRECTORIES(IfcPlusPlus
    PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
	$<BUILD_INTERFACE:${IFCPP_SOURCE_DIR}/IfcPlusPlus/src>
	$<BUILD_INTERFACE:${IFCPP_SOURCE_DIR}/IfcPlusPlus/src/ifcpp/IFC4X3/include>
	$<BUILD_INTERFACE:${IFCPP_SOURCE_DIR}/IfcPlusPlus/src/external>
	$<BUILD_INTERFACE:${IFCPP_SOURCE_DIR}/IfcPlusPlus/src/external/glm>
	$<BUILD_INTERFACE:${IFCPP_SOURCE_DIR}/IfcPlusPlus/src/external/Carve/include>
	$<BUILD_INTERFACE:${IFCPP_SOURCE_DIR}/IfcPlusPlus/src/external/Carve/src>
	$<BUILD_INTERFACE:${IFCPP_SOURCE_DIR}/IfcPlusPlus/src/external/Carve/src/include>
	$<BUILD_INTERFACE:${IFCPP_SOURCE_DIR}/IfcPlusPlus/src/external/Carve/src/common>
	$<BUILD_INTERFACE:${IFCPP_SOURCE_DIR}/IfcPlusPlus/src/external/Carve/build/src>
	$<BUILD_INTERFACE:${IFCPP_SOURCE_DIR}/IfcPlusPlus/src/external/glm>
	$<INSTALL_INTERFACE:include>
	$<INSTALL_INTERFACE:include/ifcpp/IFC4X3/include>
	$<INSTALL_INTERFACE:include/external>
	$<INSTALL_INTERFACE:include/external/glm>
	$<INSTALL_INTERFACE:include/external/Carve/src>
	$<INSTALL_INTERFACE:include/external/Carve/src/include>
	$<INSTALL_INTERFACE:include/external/Carve/src/common>
	$<INSTALL_INTERFACE:include/external/Carve>
)

# set_target_properties(IfcPlusPlus PROPERTIES DEBUG_POSTFIX "d")
set_target_properties(IfcPlusPlus PROPERTIES CXX_STANDARD 17)

if(WIN32)
    set_target_properties(IfcPlusPlus PROPERTIES LINK_FLAGS_DEBUG "/debug /INCREMENTAL:NO")
	add_definitions("/wd4018 /wd4305")
	target_compile_options(IfcPlusPlus PRIVATE /W2)
endif()

install(
    DIRECTORY   src/ifcpp
    DESTINATION include
    FILES_MATCHING
    PATTERN "*.h"
    PATTERN "*.hpp"
    PATTERN "*.inl"
)

install(
    DIRECTORY   src/external
    DESTINATION include
    FILES_MATCHING
    PATTERN "*.h"
    PATTERN "*.hpp"
    PATTERN "*.inl"
)


install(
    TARGETS IfcPlusPlus
    EXPORT IfcPlusPlus_target
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(
    EXPORT IfcPlusPlus_target
    NAMESPACE IfcPlusPlus::
    FILE IfcPlusPlusConfig.cmake
    DESTINATION share/IfcPlusPlus
)


# set(target_output_filename IfcPlusPlus-config.cmake)
# set(target_output "${CMAKE_BINARY_DIR}/cmake/${target_output_filename}")

# export(
#   EXPORT IfcPlusPlus
#   FILE ${target_output}
#   NAMESPACE IfcPlusPlus::)

# install(
#   EXPORT IfcPlusPlus
#   DESTINATION ${IFCPP_CONFIG_DIR}
#   FILE ${target_output_filename}
#   NAMESPACE IfcPlusPlus::)

# install(FILES ${CMAKE_CURRENT_BINARY_DIR}/imgui-config.cmake DESTINATION share/imgui)
