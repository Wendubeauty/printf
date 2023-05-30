#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Format string containing directives.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char buffer[1024]; /* Buffer to store formatted output */
	int buffer_index = 0;
	int i;

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			/* Handle conversion specifiers */
			i++;
			switch (format[i])
			{
				case 'c':
					buffer[buffer_index++] = va_arg(args, int);
					break;
				case 's':
					printed_chars += _putstr(&buffer[buffer_index]);
					buffer_index = 0;
					break;
				case '%':
					buffer[buffer_index++] = '%';
					break;
				default:
					buffer[buffer_index++] = '%';
					buffer[buffer_index++] = format[i];
					break;
			}
		}
		else
		{
			/* Store regular characters in buffer */
			buffer[buffer_index++] = format[i];
		}

		/* Check if buffer is full and write to stdout */
		if (buffer_index == 1024)
		{
			printed_chars += write(1, buffer, buffer_index);
			buffer_index = 0;
		}
	}

	/* Write remaining characters in buffer to stdout */
	if (buffer_index > 0)
		printed_chars += write(1, buffer, buffer_index);

	va_end(args);

	return (printed_chars);
}
