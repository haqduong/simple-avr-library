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

/*! \file button.h
 * \brief provide convenient functions to use button
 *
 */

#ifndef AVR_BUTTON
#define AVR_BUTTON

/*! \brief Attach an button to a pin
 * \param [in] port_ddr DDR of PORT to attach button
 * \param [in] port PORT to attach button
 * \param [in] pin PIN of PORT to attach button
 */
inline void attach_button_to (volatile uint8_t * port_ddr,
                              volatile uint8_t * port,
                              uint8_t pin);

/*! \brief Wait until an button is clicked (pressed and released)
 * \param [in] port_in Port input Pins - PINx
 * \param [in] pin Pin of port_in
 */
void wait_until_button_clicked (volatile uint8_t * port_in, uint8_t pin);

#endif
