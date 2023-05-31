#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int format_parser(const char *format, va_list args);
int _puts(char *str);
int handle_conversion_specifier(char specifier, va_list args);

#endif /* MAIN_H */

