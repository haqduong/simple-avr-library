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
#include <stdlib.h>
#include "global_conf.h"
#include <util/delay.h>

#include "lcd_hd44780.h"
#include "lcd_hd44780_conf.h"
#include "pin_manipulation.h"
#include "bit_manipulation.h"

void clear_all_pin (void);
void clear_all_ctl_pin (void);
void clear_all_data_pin (void);
void set_all_data_pin (void);
void send_data (uint8_t data);
uint8_t read_data (void);

void toggle_e_pin (void);


void toggle_e_pin () {
  toggle_pin (&LCD_CTL_PORT, LCD_E_PIN);
}

void lcd_init () {
  _delay_ms (50);

  // set all data pin to output
  SET_BIT(LCD_DATA_DDR, LCD_DATA4_PIN);
  SET_BIT(LCD_DATA_DDR, LCD_DATA5_PIN);
  SET_BIT(LCD_DATA_DDR, LCD_DATA6_PIN);
  SET_BIT(LCD_DATA_DDR, LCD_DATA7_PIN);

  // set all control pin to output
  SET_BIT(LCD_CTL_DDR, LCD_RS_PIN);
  SET_BIT(LCD_CTL_DDR, LCD_RW_PIN);
  SET_BIT(LCD_CTL_DDR, LCD_E_PIN);

  clear_all_pin ();

  // function set
  SET_BIT(LCD_DATA_PORT, LCD_DATA5_PIN);
  SET_BIT(LCD_DATA_PORT, LCD_DATA4_PIN);
  toggle_e_pin ();
  _delay_ms (5);
  toggle_e_pin ();
  _delay_us (200);
  toggle_e_pin ();
  _delay_ms (10);
  // set to 4-bit interface
  CLEAR_BIT(LCD_DATA_PORT, LCD_DATA4_PIN);
  toggle_e_pin ();
  _delay_ms (1);

  // set number of display line (N) and charactor font (F)
  toggle_e_pin ();
  SET_BIT(LCD_DATA_PORT, LCD_DATA7_PIN);
  toggle_e_pin ();
  _delay_ms (1);

  // display on/off control
  clear_all_pin ();
  toggle_e_pin ();
  SET_BIT (LCD_DATA_PORT, LCD_DATA7_PIN);
  SET_BIT (LCD_DATA_PORT, LCD_DATA6_PIN);
  toggle_e_pin ();

  lcd_wait_busy ();

  lcd_clrscr ();

  // entry mode set
  clear_all_pin ();
  toggle_e_pin ();
  SET_BIT (LCD_DATA_PORT, LCD_DATA6_PIN);
  SET_BIT (LCD_DATA_PORT, LCD_DATA5_PIN);
  toggle_e_pin ();
}

void lcd_entry_mode_set (uint8_t mode) {
  clear_all_pin ();
  send_data (mode | 4);
  lcd_wait_busy ();
}

void lcd_on_off_set (uint8_t mode) {
  clear_all_pin ();
  send_data (mode | 0x08);
  lcd_wait_busy ();
}

void lcd_view_move (uint8_t dir) {
  clear_all_pin ();
  uint8_t data = 0x1f & dir;
  send_data (data);
}

// wait while LCD is busy and return address
uint8_t lcd_wait_busy () {
  // set control port to read busy flag and address
  CLEAR_BIT (LCD_CTL_PORT, LCD_RS_PIN);
  SET_BIT (LCD_CTL_PORT, LCD_RW_PIN);
  _delay_us (1);

  uint8_t data = BIT (7);
  while (BIT_VAL (data, 7) == 1) {
    data = read_data ();
    _delay_us (1);
  }

  SET_BIT (LCD_DATA_DDR, LCD_DATA7_PIN); // turn DB7 to output
  clear_all_ctl_pin ();

  return data;
}

void lcd_put_char (char c) {
  clear_all_pin ();
  SET_BIT (LCD_CTL_PORT, LCD_RS_PIN);

  send_data (c);

  lcd_wait_busy ();
}

void lcd_put_string (char * s) {
  while (s[0] != 0) {
    lcd_put_char (s[0]);
    s++;
  }
}

void lcd_put_uint8 (uint8_t d, uint8_t base) {
  char * str = (char *) malloc (sizeof (char) * 4);
  utoa (d, str, base);
  lcd_put_string (str);
  free (str);
}

void lcd_put_uint16 (uint16_t d) {
  char * str = (char *) malloc (sizeof (char) * 6);
  ultoa (d, str, 10);
  lcd_put_string (str);
  free (str);
}

// return home
void lcd_return_home () {
  clear_all_pin ();
  toggle_e_pin ();
  SET_BIT (LCD_DATA_PORT, LCD_DATA5_PIN);
  toggle_e_pin ();
  lcd_wait_busy ();
}

// display clear
void lcd_clrscr () {
  clear_all_pin ();
  toggle_e_pin ();
  SET_BIT (LCD_DATA_PORT, LCD_DATA4_PIN);
  toggle_e_pin ();
  lcd_wait_busy ();
}

// go to position (x, y)
void lcd_goto_xy (uint8_t x, uint8_t y) {
  uint8_t addr;
  if (y == 0) {
    addr = x;
  } else {
    addr = 0x40 + x;
  }
  clear_all_pin ();
  SET_BIT (LCD_DATA_PORT, LCD_DATA7_PIN);
  send_data (addr | 0x80);
  lcd_wait_busy ();
}

// Set data port and toggle e pin
void send_data (uint8_t data) {
  uint8_t part;

  // send upper bit
  part = data >> 4;
  SET_VAL (LCD_DATA_PORT, LCD_DATA7_PIN, BIT_VAL(part, 3));
  SET_VAL (LCD_DATA_PORT, LCD_DATA6_PIN, BIT_VAL(part, 2));
  SET_VAL (LCD_DATA_PORT, LCD_DATA5_PIN, BIT_VAL(part, 1));
  SET_VAL (LCD_DATA_PORT, LCD_DATA4_PIN, BIT_VAL(part, 0));
  toggle_e_pin ();

  // send lower bit
  part = data;
  SET_VAL (LCD_DATA_PORT, LCD_DATA7_PIN, BIT_VAL(part, 3));
  SET_VAL (LCD_DATA_PORT, LCD_DATA6_PIN, BIT_VAL(part, 2));
  SET_VAL (LCD_DATA_PORT, LCD_DATA5_PIN, BIT_VAL(part, 1));
  SET_VAL (LCD_DATA_PORT, LCD_DATA4_PIN, BIT_VAL(part, 0));
  toggle_e_pin ();
}

uint8_t read_data () {
  // clear_all_data_pin ();
  uint8_t re = 0;
  // set all ports to input
  CLEAR_BIT (LCD_DATA_DDR, LCD_DATA7_PIN);
  CLEAR_BIT (LCD_DATA_DDR, LCD_DATA6_PIN);
  CLEAR_BIT (LCD_DATA_DDR, LCD_DATA5_PIN);
  CLEAR_BIT (LCD_DATA_DDR, LCD_DATA4_PIN);

  //  set_all_data_pin ();

  // received higher bit
  output_high (LCD_CTL_PORT, LCD_E_PIN);
  __asm__ ("NOP");
  re |= BIT_VAL (LCD_DATA_IN, LCD_DATA7_PIN) << 7;
  re |= BIT_VAL (LCD_DATA_IN, LCD_DATA6_PIN) << 6;
  re |= BIT_VAL (LCD_DATA_IN, LCD_DATA5_PIN) << 5;
  re |= BIT_VAL (LCD_DATA_IN, LCD_DATA4_PIN) << 4;
  output_low (LCD_CTL_PORT, LCD_E_PIN);
  __asm__ ("NOP");

  // received lower bit
  output_high (LCD_CTL_PORT, LCD_E_PIN);
  __asm__ ("NOP");
  re |= BIT_VAL (LCD_DATA_IN, LCD_DATA7_PIN) << 3;
  re |= BIT_VAL (LCD_DATA_IN, LCD_DATA6_PIN) << 2;
  re |= BIT_VAL (LCD_DATA_IN, LCD_DATA5_PIN) << 1;
  re |= BIT_VAL (LCD_DATA_IN, LCD_DATA4_PIN);
  output_low (LCD_CTL_PORT, LCD_E_PIN);
  __asm__ ("NOP");

  // set all data ports to output
  SET_BIT (LCD_DATA_DDR, LCD_DATA7_PIN);
  SET_BIT (LCD_DATA_DDR, LCD_DATA6_PIN);
  SET_BIT (LCD_DATA_DDR, LCD_DATA5_PIN);
  SET_BIT (LCD_DATA_DDR, LCD_DATA4_PIN);

  return re;
}


void clear_all_pin () {
  clear_all_ctl_pin ();
  clear_all_data_pin ();
}

void clear_all_data_pin () {
  // clear data pin
  CLEAR_BIT(LCD_DATA_PORT, LCD_DATA4_PIN);
  CLEAR_BIT(LCD_DATA_PORT, LCD_DATA5_PIN);
  CLEAR_BIT(LCD_DATA_PORT, LCD_DATA6_PIN);
  CLEAR_BIT(LCD_DATA_PORT, LCD_DATA7_PIN);
}

void set_all_data_pin () {
  SET_BIT(LCD_DATA_PORT, LCD_DATA4_PIN);
  SET_BIT(LCD_DATA_PORT, LCD_DATA5_PIN);
  SET_BIT(LCD_DATA_PORT, LCD_DATA6_PIN);
  SET_BIT(LCD_DATA_PORT, LCD_DATA7_PIN);
}

void clear_all_ctl_pin () {
  // clear control pin
  CLEAR_BIT(LCD_CTL_PORT, LCD_RS_PIN);
  CLEAR_BIT(LCD_CTL_PORT, LCD_RW_PIN);
  CLEAR_BIT(LCD_CTL_PORT, LCD_E_PIN);
}
