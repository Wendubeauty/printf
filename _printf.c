#include "main.h"
#include <stddef.h>
/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	printed_chars = format_parser(format, args);
	va_end(args);

	return (printed_chars);
}

/**
 * format_parser - Parses the format string
 * and processes the conversion specifiers.
 * @format: The format string.
 * @args: The variable arguments list.
 * Return: The number of characters printed.
 */
int format_parser(const char *format, va_list args)
{
	int i = 0, printed_chars = 0;

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_chars++;
		}
		else
		{
			i++;
			printed_chars += handle_conversion_specifier(format[i], args);
		}

		i++;
	}

	return (printed_chars);
}

/**
 * handle_conversion_specifier - Handles the conversion specifier.
 * @specifier: The conversion specifier character.
 * @args: The variable arguments list.
 *
 * Return: The number of characters printed.
 */
int handle_conversion_specifier(char specifier, va_list args)
{
	int printed_chars = 0;
	int value;

	switch (specifier)
	{
		case 'c':
			_putchar(va_arg(args, int));
			printed_chars++;
			break;
		case 's':
			printed_chars += _puts(va_arg(args, char *));
			break;
		case 'd':
		case 'i':
			value = va_arg(args, int);
			printed_chars += print_number(value);
			break;
		case '%':
			_putchar('%');
			printed_chars++;
			break;
		default:
			_putchar('%');
			_putchar(specifier);
			printed_chars += 2;
			break;
	}

	return (printed_chars);
}

/**
 * _puts - Prints a string to stdout.
 * @str: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int _puts(char *str)
{
	int i = 0;

	while (str && str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * print_number - Prints an integer to stdout.
 * @num: The integer to be printed.
 * Return: The number of characters printed.
 */
int print_number(int num)
{
	int printed_chars = 0;

	if (num < 0)
	{
		_putchar('-');
		printed_chars++;
		num = -num;
	}

	if (num / 10)
		printed_chars += print_number(num / 10);

	_putchar('0' + (num % 10));
	printed_chars++;

	return (printed_chars);
}

