// Copyright 2006-2015 Tobias Sargeant (tobias.sargeant@gmail.com).
//
// This file is part of the Carve CSG Library (http://carve-csg.com/)
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
// BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <carve/carve.hpp>
#ifdef _OPENMP
#include <omp.h>
#include <iostream>
#endif

#include <cstdint>
#include <cstddef>
#include <functional>
#include <utility>

namespace carve {
	// NEXT-BIM: a creation number for the mesh objects (vertices, edges, faces, meshes, mesh sets, face loops), so that the
	// containers keyed by their pointers hash and order them the same way on every run (by address they don't). The
	// numbers come from a counter per thread that serial_reset sets at the start of each product's conversion (and of
	// each task of a product run on another thread), so the same conversion numbers its objects the same way. Two objects
	// numbered by different conversions may share a number: comparisons then fall back on their addresses.
	struct serial_t {
		uint64_t __serial;

		static inline uint64_t& counter() {
			static thread_local uint64_t s_serial = 0;
			return s_serial;
		}
		serial_t() : __serial(++counter()) {}
		serial_t(const serial_t&) : __serial(++counter()) {}
		serial_t& operator=(const serial_t&) { return *this; }
	};

	inline void serial_reset(uint64_t base) { serial_t::counter() = base; }

	template <typename T>
	inline uint64_t serial_of(const T* p) { return p ? p->__serial : 0; }

	struct serial_hash {
		template <typename T>
		size_t operator()(const T* p) const noexcept {
			uint64_t x = serial_of(p) * 0x9E3779B97F4A7C15ull;
			return (size_t)(x ^ (x >> 29));
		}
	};

	struct serial_less {
		template <typename T>
		bool operator()(const T* a, const T* b) const noexcept {
			uint64_t sa = serial_of(a), sb = serial_of(b);
			return sa != sb ? sa < sb : std::less<const void*>()(a, b);
		}
	};

	// serial_less for pointers to numbered objects, std::less for anything else
	template <typename T, typename = void>
	struct key_less : std::less<T> {};
	template <typename T>
	struct key_less<T*, decltype((void)std::declval<const T*>()->__serial)> : serial_less {};

	// serial_less on the first pointers of two pairs, then on the second ones
	struct serial_pair_less {
		template <typename T, typename U>
		bool operator()(const std::pair<T*, U*>& a, const std::pair<T*, U*>& b) const noexcept {
			if (a.first != b.first) return serial_less()(a.first, b.first);
			return serial_less()(a.second, b.second);
		}
	};

	class tagable : public serial_t {
	private:
		static int s_count[48];

	protected:
		mutable int __tag;

		static inline int getCurrentThreadNum()
		{
			int threadNr = 0;
#ifdef _OPENMP
			threadNr = omp_get_thread_num();
#endif
			return threadNr;
		}

	public:
		tagable(const tagable&)
		{
			int threadNr = getCurrentThreadNum();
			__tag = s_count[threadNr] - 1;
		}
		tagable& operator=(const tagable&)
		{
			return *this;
		}

		tagable()
		{
			int threadNr = getCurrentThreadNum();
			__tag = s_count[threadNr] - 1;
		}

		void tag() const
		{
			int threadNr = getCurrentThreadNum();
			__tag = s_count[threadNr];
		}

		void untag() const
		{
			int threadNr = getCurrentThreadNum();
			__tag = s_count[threadNr] - 1;
		}

		bool is_tagged() const
		{
			int threadNr = getCurrentThreadNum();
			return __tag == s_count[threadNr];
		}

		bool tag_once() const
		{
			int threadNr = getCurrentThreadNum();

			if( __tag == s_count[threadNr] )
			{
				return false;
			}
			__tag = s_count[threadNr];
			return true;
		}

		static void tag_begin()
		{
			int threadNr = getCurrentThreadNum();
			s_count[threadNr]++;
		}
	};
}  // namespace carve
