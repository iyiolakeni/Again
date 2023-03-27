#include "main.h"

/**
 * _precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @index: Number of arguments to be printed.
 * @arg: list of arguments.
 * Return: Precision.
 */
int _precision(const char *format, int *index, va_list arg)
{
    int i = *index + 1;
    int accuracy = -1;

    if (format[i] != '.')
        return (accuracy);

    accuracy = 0;

    for (i += 1; format[i] != '\0'; i++)
    {
        if(_is_digit (format[i]))
        {
            accuracy *= 10;
            accuracy += format[i] - '0';
        }
        else if (format[i] == '*')
        {
            i++;
            accuracy = va_arg(arg, int);
            break;
        }
        else
            break;
    }

    *index = i - 1;

    return (accuracy);
}
