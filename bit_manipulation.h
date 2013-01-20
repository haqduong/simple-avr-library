/*
  Copyright 2013 Duong Quang Ha

  This file is part of Simple AVR Library

  Simple AVR Library is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Simple AVR Library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Simple AVR Library.  If not, see <http://www.gnu.org/licenses/>.
*/

/*! \file bit_manipulation.h
 * \brief Provide convenient macros to manipulate bit
 */

#ifndef BIT_MANIPULATION
#define BIT_MANIPULATION

/*!
 * \def BIT(x)
 * Get the binary number with x-th bit is 1, other is 0
 */
#define BIT(x) (1 << (x))

/*!
 * \def SET_BITS(x, y)
 * Set y-th bit in x to 1 if coressponding bit in y is 1
 */
#define SET_BITS(x,y) ((x) |= (y))

/*!
 * \def CLEAR_BITS(x, y)
 * Set y-th bit in x to 0 if coressponding bit in y is 1
 */
#define CLEAR_BITS(x,y) ((x) &= (~(y)))

/*! \def SET_BIT(x, y)
 * Set y-th bit in x to 1
 */
#define SET_BIT(x,y) SET_BITS((x), (BIT((y))))

/*! \def CLEAR_BIT(x, y)
 * Set y-th bit in x to 0
 */
#define CLEAR_BIT(x,y) CLEAR_BITS((x), (BIT((y))))

/*! \def BIT_VAL(x, y)
 * Get y-th bit of x
 */
#define BIT_VAL(x,y) (((x) >> (y)) & 1)

/*! \def FLIP_BIT(x, y)
 * Flip y-th bit of x
 */
#define FLIP_BIT(x,y) (BIT_VAL((x),(y)) ? CLEAR_BIT((x),(y)) : SET_BIT((x),(y)))

/*! \def SET_VAL(x, y, z)
 * Set y-th bit of x to z
 */
#define SET_VAL(x,y,z) ((z) ? SET_BIT((x),(y)) : CLEAR_BIT((x),(y)))


#endif
