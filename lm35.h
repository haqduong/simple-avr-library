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

/*! \file lm35.h
 * \brief Provide function to interface with LM35 temperature sensor
 */

#ifndef AVR_LM35
#define AVR_LM35

#include <avr/io.h>

/*! \brief Return temperature in C degree.
 * Return temperature in C degree using LM35 sensor
 *
 * \b Require ADC inited
 * \param[in] channel ADC channel which the LM35 sensor is connected
 * \return temperature in C degree
 */
inline uint16_t read_temperature_in_C (uint8_t channel); //! Return the temperature in C degree

#endif
