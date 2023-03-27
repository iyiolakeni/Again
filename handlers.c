#include "main.h"

/**
 * _char_printer - String writer/printer
 * @c: character
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
*/
int _char_printer(char c, char buffer_array[],
        int flag, int width, int precision, int size)
{
    int i = 0;
    char pad = ' ';

    UNUSED(precision);
	UNUSED(size);

    if (flag & _ZERO)
        pad = '0';

    buffer_array[i++] = c;
    buffer_array[i] = '\0';

    if (width > 1)
    {
        buffer_array[BUFFER_SIZE - 1] = '\0';
        for (i = 0; i < width - 1; i++)
            buffer_array[BUFFER_SIZE - i - 2] = pad;

        if (flag & _MINUS)
            return (write(1, &buffer_array[0], 1) +
					write(1, &buffer_array[BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer_array[BUFFER_SIZE - i - 1], width - 1) +
					write(1, &buffer_array[0], 1));
	}

	return (write(1, &buffer_array[0], 1));
}

/**
 * _number_printer - Prints a string
 * @is_negative: no of arguments
 * @c: char types.
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int _number_printer(int is_negative, int c, char buffer_array[], int flag, int width, int precision, int size)
{
    int length = BUFFER_SIZE - c - 1;
    char pad = ' ';
    char ch = 0;

    UNUSED(size);

    if ((flag & _ZERO) && !(flag & _MINUS))
        pad = '0';
    if (is_negative)
        ch = '-';
    else if (flag & _PLUS)
        ch = '+';
    else if (flag & _SPACE)
        ch = ' ';

    return (number_buffer(c, buffer_array, flag, width, precision, length, pad, ch));
}

/**
 * number_buffer - Write a number using a bufffer
 * @index: Index at which the number starts on the buffer
 * @buffer_array: Buffer
 * @flags: Flags
 * @width: width
 * @precise: Precision specifier
 * @length: Number length
 * @pad: Pading char
 * @c: char
 * Return: Number of printed chars.
 */
int number_buffer(int index, char buffer_array[], int flag, int width, int precise, int length, char pad, char c)
{
    int i;
    int start = 1;

    if (precise == 0 && index == BUFFER_SIZE - 2 && buffer_array[index] == '0' && width == 0)
        return (0); /* no character is printed same as printf(".0d", 0) */
    if (precise == 0 && index == BUFFER_SIZE - 2 && buffer_array[index] == '0')
        buffer_array[index] = pad = ' '; /* pad becomes width */
    if (precise > 0 && precise < length)
        pad = ' ';
    while (precise > length)
        buffer_array[--index] = '0', length++;
    if (c != 0)
        length++;
    if (width > length)
    {
        for (i = 1; i < width - length + 1; i++)
            buffer_array[i] = pad;
        buffer_array[i] = '\0';
        if (flag & _MINUS && pad == ' ')
        {
            if (c)
                buffer_array[--index] = c;
            return (write(1, &buffer_array[index], length) + write(1, &buffer_array[1], i - 1));
        }
        else if (!(flag & _MINUS) && pad == ' ')
        {
            if (c)
                buffer_array[--index] = c;
            return (write(1, &buffer_array[1], i - 1) + write(1, &buffer_array[index], length));
        }
        else if (!(flag & _MINUS) && pad == '\0')
        {
            if (c)
                buffer_array[--start] = c;
            return (write(1, &buffer_array[start], i - start) +
                    write(1, &buffer_array[index], length - (1 - start)));
        }
    }
    if (c)
        buffer_array[--index] = c;
    return (write(1, &buffer_array[index], length));
}

/**
 * write_unsigned - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @_size: Size specifier
 * @index: Index at which the number starts in the buffer
 * @buffer_array: Array of chars
 * @flag: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * Return: Number of written chars.
 */
int write_unsigned(int is_negative, int index, char buffer_array[], int flag, int width, int precision, int size)
{
    int length = BUFFER_SIZE - index - 1;
    int i = 0;
    char pad = ' ';

    UNUSED(is_negative);
	UNUSED(size);

    if (precision == 0 && index == BUFFER_SIZE - 2 && buffer_array[index] == '0')
        return (0);

    if (precision > 0 && precision < length)
        pad = ' ';

    while (precision > length)
    {
        buffer_array[--index] = '0';
        length++;
    }

    if ((flag && _ZERO) && !(flag & _MINUS))
        pad = '0';

    if (width > length)
    {
        for (i = 0; i < width - length; i++)
            buffer_array[i] = pad;

        buffer_array[index] = '\0';

        if (flag & _MINUS)
        {
            return (write(1, &buffer_array[index], length) + write(1, &buffer_array[0], i));
        }
        else
        {
            return (write(1, &buffer_array[0], i) + write(1, &buffer_array[index], length));
        }
    }

    return (write(1, &buffer_array[index], length));
}

/**
 * _pointer_print - Write a memory address
 * @buffer_array: Arrays of chars
 * @index: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flag: Flags specifier
 * @pad: Char representing the padding
 * @c: Char representing extra char
 * @pad_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int _pointer_print(char buffer_array[], int index, int length, int width, int flag, char pad, char c, int pad_start)
{
    int i;

    if (width > length)
    {
        for (i = 3; i < width - length + 3; i++)
            buffer_array[i] = pad;
        buffer_array[i] = '\0';

        if (flag & _MINUS && pad == ' ')
        {
            buffer_array[--index] = 'x';
            buffer_array[--index] = '0';
            if (c)
                buffer_array[--index] = c;
            return (write(1, &buffer_array[index], length) + write(1, &buffer_array[3], i - 3));
        }
        else if (!(flag & _MINUS) && pad == ' ')
        {
            buffer_array[--index] = 'x';
            buffer_array[--index] = '0';
            if (c)
                buffer_array[--index] = c;
            return (write(1, &buffer_array[3], i - 3) + write(1, &buffer_array[index], length));
        }
        else if (!(flag & _MINUS) && pad == '0')
        {
            if (c)
                buffer_array[--pad_start] = c;
            buffer_array[1] = '0';
            buffer_array[2] = 'x';
            return (write(1, &buffer_array[pad_start], i - pad_start) +
                    write(1, &buffer_array[index], length - (1 - pad_start) - 2));
        }
    }
    buffer_array[--index] = 'x';
    buffer_array[--index] = '0';
    if (c)
        buffer_array[--index] = c;
    return (write(1, &buffer_array[index], BUFFER_SIZE - index - 1));
}

