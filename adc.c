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
#include "adc.h"

void init_ADC () {
  ADMUX |= (1 << REFS0);
  ADCSRA = (1 << ADEN) | (7 << ADPS0);
}

uint16_t read_ADC(uint8_t ch) {
  ADMUX &= 0xf0;
  ADMUX |= ch;
  ADCSRA |= (1 << ADSC);
  while (!(ADCSRA & (1 << ADIF)));
  ADCSRA |= (1 << ADIF);

  return (ADC);
}
