#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* Function prototype for _printf */
int _printf(const char *format, ...);

/* Helper function prototypes */
int _putchar(char c);
int _strlen(const char *str);
int _putstr(char *str);

#endif /* MAIN_H */
