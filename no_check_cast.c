#include "main.h"

/**
 * _print_check - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 as fail
 */
int _print_check(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * _add_hex - Append ascci in hexadecimal code to buffer
 * @ascii: ASSCI CODE.
 * @buffer_array: Array of chars.
 * @i: Index at which to start appending.
 * Return: Always 3
 */
int _add_hex(char ascii, char buffer_array[], int i)
{
    char map_tool[] = "0123456789ABCDEF";
    /* The lenght of the hexa number is 2 */
    if (ascii < 0)
        ascii *= -1;

    buffer_array[i++] = '\\';
    buffer_array[i++] = 'x';

    buffer_array[i++] = map_tool[ascii / 16];
    buffer_array[i] = map_tool[ascii % 16];

    return (3);
}

/**
 * _is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * _number_size - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int _number_size(long int num, int size)
{
    if (size == S_SHORT)
        return ((short)num);
    else if (size == S_LONG)
        return (num);

    return ((int)num);
}

/**
 * _unsigned_converter - Casts a number to the specified size
 * @num: Number to be casted
 * @_size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int _unsigned_converter(unsigned long int num, int size)
{
    if (size == S_SHORT)
        return ((unsigned short)num);
    else if (size == S_LONG)
        return (num);

    return ((unsigned int)num);
}
