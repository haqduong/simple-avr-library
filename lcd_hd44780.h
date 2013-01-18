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

/*! \file lcd_hd44780.h
 * \brief Provide function to use LCD use HD4470 dot-matrix LCD controller
 * \detail Provide function to use LCD use HD4470 dot-matrix LCD controller
 *
 * Configuration in lcd_hd44780_conf.h
 */

#include <avr/io.h>

#ifndef LCD_HD44780
#define LCD_HD44780

/*! \brief Init lcd controller
 * Init lcd controller with 4-bit interface.
 * Current, only support 8 x 2 LCD
 * After init the LCD is on, cursor and blinky is off.
 *     entry mode is increment, no-shift
 */
void lcd_init (void);

/*! \brief Set entry mode
 * \detail Set entry mode using the entry mode constants
 * \param[in] mode mode to be set
 */
void lcd_entry_mode_set (uint8_t mode);

/*! \brief Display on/off control
 * \detail Display on/off control using the corresponding constants
 * \param[in] mode mode to be set
 */
void lcd_on_off_set (uint8_t mode);

/*! \brief Call LCD "return home" instruction
 */
void lcd_return_home (void);

/*! \brief Wait until lcd is ready for next instruction */
uint8_t lcd_wait_busy (void);

/*! \brief Call LCD "clear display" instruction */
void lcd_clrscr (void);

/*! \todo Complete this function */
void lcd_goto_xy (uint8_t x, uint8_t y);

/*!
 * Put a string to LCD
 * \param[in] s String to put
 */
void lcd_put_string (char * s);

/*!
 * Put an char to LCD
 * \param[in] c Char to put
 */
void lcd_put_char (char c);

/*!
 * Put an uint8_t to LCD
 * \param[in] d number to put
 * \param[in] base base of number to display
 */
void lcd_put_uint8 (uint8_t d, uint8_t base);

/*!
 * Put an uint16_t to LCD
 * \param[in] d number to put
 * \param[in] base base of number to display
 */
void lcd_put_uint16 (uint16_t d);

// entry mode set constants
#define LCD_INCREMENT 2
#define LCD_DECREMENT 0
#define LCD_SHIFT 1

// cursor or display shift constants
#define DISPLAY_SHIFT 8
#define CURSOR_MOVE 0
#define SHIFT_LEFT 0
#define SHIFT_RIGHT 4

// display on/off controll constants
#define DISPLAY_OFF 0
#define DISPLAY_ON 4
#define CURSOR_OFF 0
#define CURSOR_ON 2
#define BLINKING_OFF 0
#define BLINKING_ON 1

#endif
