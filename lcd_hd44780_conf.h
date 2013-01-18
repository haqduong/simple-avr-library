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

/*! \file lcd_hd44780_conf.h
 * \brief contain setting for lcd_hd44780, self-describe
 */

#define LCD_DATA_PORT PORTC
#define LCD_DATA_DDR DDRC
#define LCD_DATA_IN PINC
#define LCD_DATA4_PIN 0
#define LCD_DATA5_PIN 1
#define LCD_DATA6_PIN 2
#define LCD_DATA7_PIN 3

#define LCD_CTL_PORT PORTB
#define LCD_CTL_DDR DDRB
#define LCD_RS_PIN 0
#define LCD_RW_PIN 1
#define LCD_E_PIN 2
