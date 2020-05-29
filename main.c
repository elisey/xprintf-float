#include "xprintf.h"
#include <stdio.h>

static void my_putchar(unsigned char c) {
  putchar(c); //
}

int main() {
  xfunc_out = my_putchar;
  xprintf("this is test string\r\n");
  xprintf("Percentage %d%%\r\n", 55);
  xprintf("Integer %d\r\n", 123);
  xprintf("Float %f\r\n", 12333445.02);
  xprintf("Float %f\r\n", 123.1);
  xprintf("Big float %f\r\n", 123456789.1);
  xprintf("Small float %f\r\n", 0.123456789);
  xprintf("Small float %f\r\n", .0110001);
}