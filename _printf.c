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
 * handle_normal_character - Handles a normal character in the format string.
 * @ch: The character to handle.
 * @printed_chars: Pointer to the count of printed characters.
 */
void handle_normal_character(const char ch, int *printed_chars)
{
	_putchar(ch);
	(*printed_chars)++;
}

/**
 * handle_format_specifier - Handles a format specifier in the format string.
 * @format_specifier: The format specifier to handle.
 * @args: The variable arguments list.
 * @printed_chars: Pointer to the count of printed characters.
 */
void handle_format_specifier(const char format_specifier, va_list args,
		int *printed_chars)
{
	if (format_specifier == 'c')
	{
		_putchar(va_arg(args, int));
		(*printed_chars)++;
	}
	else if (format_specifier == 's')
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
			str = "(null)";
		(*printed_chars) += _puts(str);
	}
	else if (format_specifier == '%')
	{
		_putchar('%');
		(*printed_chars)++;
	}
	else if (format_specifier == '\0')
	{
		*printed_chars = -1;
	}
	else
	{
		_putchar('%');
		_putchar(format_specifier);
		(*printed_chars) += 2;
	}
}

/**
 * format_parser - Parses and handles the format string.
 * @format: The format string to parse.
 * @args: The variable arguments list.
 *
 * Return: The number of printed characters, or -1 on error.
 */
int format_parser(const char *format, va_list args)
{
	int printed_chars = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			handle_normal_character(format[i], &printed_chars);
		}
		else
		{
			i++;
			handle_format_specifier(format[i], args, &printed_chars);
		}

		i++;
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
