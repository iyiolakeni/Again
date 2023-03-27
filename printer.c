#include "main.h"

/**
 * _printer - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @arg: List of arguments to be printed.
 * @no: integer
 * @buffer_array: Buffer array to handle print.
 * @flag: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: 1 or 2;
 */
int _printer(const char *format, int *no, va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
    int i;
    int len = 0;
    int j = -1;

    format_t format_n[] = {
        {'c', _char}, {'s', _string}, {'%', _percent},
		{'i', _int}, {'d', _int}, {'b', _binary},
		{'u', _unsigned}, {'o', _octal}, {'x', _hexadecimal},
		{'X', _unsigned_hexa}, {'p', _pointer_value}, {'S', _hexa_np},
		{'r', _reverse_string}, {'R', _rot13}, {'\0', NULL}
	};

	for (i = 0; format_n[i].format != '\0'; i++)
        if (format[*no] == format_n[i].format)
        return (format_n[i].func(arg, buffer_array, flag, width, precision, size));

    if (format_n[i].format == '\0')
    {
        if (format[*no] == '\0')
            return (-1);
        len += write(1, "%%", 1);
        if (format[*no - 1] == ' ')
            len += write(1, " ", 1);
        else if (width)
        {
            --(*no);
            while (format[*no] != ' ' && format[*no] != '%')
                --(*no);
            if (format[*no] == ' ')
                --(*no);
            return (1);
        }
        len += write (1, &format[*no], 1);
        return (len);
    }
    return (j);
}
