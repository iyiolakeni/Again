#include "main.h"

/**
 * _size - Determines the size of argument to be casted
 * @format: strings
 * @index: List of arguments
 * Return: size
*/
int _size(const char *format, int *index)
{
    int i = *index + 1;
    int new_size = 0;

    if (format[i] == 'l')
        new_size = S_LONG;
    else if (format[i] == 'h')
        new_size = S_SHORT;

    if (new_size == 0)
        *index = i - 1;
    else
        *index = i;

    return (new_size);
}
