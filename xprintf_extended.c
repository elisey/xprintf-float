#include "xprintf_extended.h"
#include <math.h>
#include <stdint.h>
#include <string.h>

static void reverse(char s[], int l) {
  int i, j;
  char c;

  for (i = 0, j = l - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

static char *ltoa(int64_t num, char *str, int base) {
  uint32_t i = 0;
  int isNegative = 0;

  /* Handle 0 explicitely, otherwise empty string is printed for 0 */
  if (num == 0) {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }

  // In standard itoa(), negative numbers are handled only with
  // base 10. Otherwise numbers are considered unsigned.
  if ((num) < 0 && base == 10) {
    isNegative = 1;
    num = -num;
  }

  // Process individual digits
  while (num != 0) {
    int rem = num % base;
    str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
    num = num / base;
  }

  // If number is negative, append '-'
  if (isNegative) {
    str[i++] = '-';
  }

  str[i] = '\0'; // Append string terminator

  // Reverse the string
  reverse(str, i);

  return str;
}

void floatToStr(float val, char *buffer, int prec) {

  int64_t valInt = val * (int64_t)pow(10, prec);
  ltoa(valInt, buffer, 10);

  int len = strlen(buffer);

  if (prec > 0) {
    for (int i = 0; i < prec; i++) {
      buffer[len - i] = buffer[len - i - 1];
    }
    buffer[len - prec] = '.';
    buffer[len + 1] = '\0';
  }
}
