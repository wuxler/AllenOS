/* Copyright (c) 2018 Allen Wu. All rights reserved.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
// Created by allen on 18-5-13.

#ifndef ALLENOS_LIB_LIBSTD_INCLUDE_MACROS_HPP__
#define ALLENOS_LIB_LIBSTD_INCLUDE_MACROS_HPP__

#include "Types.hpp"

/** Binary 1 means true. */
#define TRUE        1
/** Binary 0 means false. */
#define FALSE       0

/** NULL means zero. */
#ifndef NULL
#define NULL        (void *)0
#endif

/** Zero value. */
#define ZERO        0

/** Stringfies the given input. */
#define QUOTE(x)    #x

/** Indirect quoting. */
#define IQUOTE(x)   QUOTE(x)

/** Convert kilobytes to bytes. */
#define KiloByte(v)     ((v) * 1024)

/** Convert megabytes to bytes. */
#define MegaByte(v)     ((v) * 1024 * 1024)

/** Convert gigabytes to bytes. */
#define GigaByte(v)     ((v) * 1024 * 1024 * 1024)

// TODO: #warning Integer range depends on the architecture. Here is x86_64.

/** Minimum value of an object of type long int. */
#define LONG_MIN   -9223372036854775808L

/** Maximum value of an object of type long int. */
#define LONG_MAX    9223372036854775807L

#define ULONG_MIN 0LU

#define ULONG_MAX 18446744073709551615LU

#define INT_MIN -2147483647

#define INT_MAX  2147483647

#define UINT_MIN 0U

#define UINT_MAX 4294967295U

/**
 * Calculate a division, and round to up any remaining.
 * @param number Input number.
 * @param divisor Divisor number.
 * @return Ceiled number.
 */
#define CEIL(number, divisor)   \
	((number) % (divisor) ?      \
	((number) / (divisor) ) + 1 : (number) / (divisor))

#ifdef __cplusplus

/**
 * Absolute value of a double.
 */
inline double doubleAbsolute(double number) {
	return number < 0 ? -number : number;
}

/**
 * Compare two doubles using a epsilon number as precision indicator.
 */
inline bool doubleEquals(double a, double b, double epsilon) {
	return doubleAbsolute(a - b) < epsilon;
}
#endif  // __cplusplus

/** Calculates offsets in data structures. */
#define offsetof(TYPE, MEMBER) \
    ((Size) &((TYPE *)0)->MEMBER)

/** Used to define external C functions. */
#ifdef __cplusplus
#define C "C"
#define CPP
#else
#define C
#endif  // __cplusplus

/**
 * Can be used to link a symbol inside a specific section.
 * @param s Section name.
 */
#define SECTION(s) \
    __attribute__((__section__(s)))

/**
 * Declares an symbol to be forcibly "used".
 */
#define USED \
    __attribute__((__used__))

/**
 * Ensures strict minimum memory requirements.
 * This option effectively disabled extra padding by the compiler.
 */
#define PACKED \
    __attribute__((__packed__))

/**
 * Aligns a symbol at the given boundary.
 * @param n Boundary to align.
 */
#define ALIGN(n) \
    __attribute__((aligned(n)))

#endif  // ALLENOS_LIB_LIBSTD_INCLUDE_MACROS_HPP__