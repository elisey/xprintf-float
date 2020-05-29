#include "xprintf.h"
#include <stdio.h>

static void my_putchar(unsigned char c) {
  putchar(c); //
}

int main() {
  xfunc_out = my_putchar;
  xprintf("this is test\r\n");
  xprintf("this is %d\r\n", 123);
  xprintf("this is %D\r\n", 123);
  xprintf("this is %f\r\n", 12333445.02);
  xprintf("this is %f\r\n", 123.);
  xprintf("this is %f\r\n", 123456789.1234);
}