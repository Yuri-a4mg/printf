#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @lenb: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *lenb)
{
	if (*lenb > 0)
		write(1, &buffer[0], *lenb);

	*lemb = 0;
}

/**
 * _printf - formatted output conversion and print data.
 * @format: format.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	int i, printed, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[lenb++] = format[i];
			if (lenb == BUFF_SIZE)
				print_buffer(buffer, &lenb);
			/* write(1, &format[i], 1);*/
			chars_print++;
		}
		else
		{
			print_buffer(buffer, &lenb);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &lenb);

	va_end(list);

	return (chars_print);
}
