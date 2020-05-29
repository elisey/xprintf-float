#include "xprintf_extended.h"
#include <stdint.h>
#include <string.h>

// this is reworked function. Originaly taken from here
// https://stackoverflow.com/questions/23191203/convert-float-to-string-without-sprintf

char *ftoa(float fVal, char *buffer, size_t size) {
  char *result = buffer + size; // go to end of buffer
  int dVal, dec, i;

  fVal += 0.005;

  dVal = fVal;
  dec = (int)(fVal * 100) % 100;

  memset(buffer, 0, size);
  *result = (dec % 10) + '0';
  result--;
  *result = (dec / 10) + '0';
  result--;
  *result = '.';
  result--;

  do {
    *result = (dVal % 10) + '0';
    result--;
    dVal /= 10;
  } while (dVal > 0);

  return ++result;
}