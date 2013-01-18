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

/*! \file pin_manipulation.h
 * \brief Provide some function and macro to manipulate MCU's pins
 */

#ifndef PIN_MANIPULATION
#define PIN_MANIPULATION

#include <avr/io.h>
#include "bit_manipulation.h"

/*!
 * \brief toggle an MCU's pin
 * \param[in] port port of pin
 * \param[in] pin pin-th pin
 */
void toggle_pin (volatile uint8_t * port, uint8_t pin);

/*! \def output_high(x,n)
 * Set n pin of port x to output high (require DDRxn is 1);
 */
#define output_high(x,n) SETBIT(x,n)

/*! \def output_low(x,n)
 * Set n pin of port x to output low (require DDRxn is 1);
 */
#define output_low(x,n) CLEARBIT(x,n)

#endif
