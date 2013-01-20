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

#include <avr/io.h>
#include "global_conf.h"
#include <util/delay.h>
#include "bit_manipulation.h"
#include "lcd_hd44780.h"

void wait_until_button_clicked (volatile uint8_t * port_in, uint8_t pin) {
  while (BIT_VAL (*port_in, pin) == 1) {
    _delay_ms (10);
  }

  while (BIT_VAL (*port_in, pin) == 0) {
    _delay_ms (10);
  }
}

inline void attach_button_to (volatile uint8_t * port_ddr,
                              volatile uint8_t * port,
                              uint8_t pin) {
  CLEAR_BIT (*port_ddr, pin);
  SET_BIT (*port, pin);
}
