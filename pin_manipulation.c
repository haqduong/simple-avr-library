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

#include "pin_manipulation.h"

void toggle_pin (volatile uint8_t * port, uint8_t pin) {
  FLIP_BIT(*port, pin);
  __asm__ ("NOP");
  FLIP_BIT(*port, pin);
  __asm__ ("NOP");
}
