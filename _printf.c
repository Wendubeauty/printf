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
	char *str;
	int printed_chars = 0;

	switch (specifier)
	{
		case 'c':
			_putchar(va_arg(args, int));
			printed_chars++;
			break;
		case 's':
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(null)";
			printed_chars += _puts(str);
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

