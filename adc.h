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

/*! \file adc.h
 * \brief Provide functions to interface with ADC sub-system
 */

#ifndef AVR_ADC
#define AVR_ADC

#include <avr/io.h>

/*! \brief Init ADC sub-system
 */
void init_ADC ();

/*! \brife Read ADC value at an channel
 * \b Require ADC inited
 * \param[in] channel ADC channel to read
 * \return ADC output value
 */
uint16_t read_ADC(uint8_t ch);

#endif
