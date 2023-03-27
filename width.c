#include "main.h"

/**
 * _width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @index: List of arguments to be printed.
 * @arg: list of arguments.
 * Return: width.
 */
int _width(const char *format, int *index, va_list arg)
{
    int i;
    int width = 0;

    for (i = *index + 1; format[i] != '\0'; i++)
    {
        if (_is_digit(format[i]))
        {
            width *= 10;
            width += format[i] - '0';
        }
        else if (format[i] == '*')
        {
            i++;
            width = va_arg(arg, int);
            break;
        }
        else
            break;
    }
    *index = i - 1;

    return (width);
}
