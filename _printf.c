#include "main.h"
#include <>
/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
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
 * format_parser - Parses the format string and processes the conversion specifiers.
 * @format: The format string.
 * @args: The variable arguments list.
 *
 * Return: The number of characters printed.
 */
int format_parser(const char *format, va_list args)
{
	int i = 0, printed_chars = 0;
	char *str;

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
			if (format[i] == 'c')
			{
				_putchar(va_arg(args, int));
				printed_chars++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				printed_chars += _puts(str);
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				printed_chars++;
			}
			else if (format[i] == '\0')
				return (-1);
			else
			{
				_putchar('%');
				_putchar(format[i]);
				printed_chars += 2;
			}
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
