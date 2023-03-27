#include "main.h"

/**
 * _unsigned - Prints an unsigned number
 * @arg: List a of arguments
 * @buffer_array: An array buffer to print unsigned number
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int _unsigned(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
    int i = BUFFER_SIZE - 2;
    unsigned long int num = va_arg(arg, unsigned long int);

    num = _unsigned_converter(num, size);

    if (num == 0)
        buffer_array[i--] = '\0';

    buffer_array[BUFFER_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer_array[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    return(write_unsigned(0, i, buffer_array, flag, width, precision, size));
}

/**
 * _octal - Prints an unsigned number in octal notation
 * @arg: List  of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _octal(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
    int i = BUFFER_SIZE - 2;
    unsigned long int num = va_arg(arg, unsigned long int);
    unsigned long int num_holder = num;

    UNUSED(width);

    num = _unsigned_converter(num, size);

    if (num == 0)
        buffer_array[i--] = '0';

    buffer_array[BUFFER_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer_array[i--] = (num % 8) + '0';
        num /= 8; /* Divide the number by 8 which is octal base */
    }

    if (flag & _HASH && num_holder != 0)
        buffer_array[i--] = '0';

    i++;

    return(write_unsigned(0, i, buffer_array, flag, width, precision, size));
}

/**
 * _hexadecimal - Prints an unsigned number in hexadecimal notation
 * @arg: Lista of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _hexadecimal(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
	return (_hexa_printer(arg, "0123456789abcdef", buffer_array,
		flag, 'x', width, precision, size));
}

/**
 * _unsigned_hexa - Prints an unsigned number in upper hexadecimal notation
 * @arg: Lista of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */
int _unsigned_hexa(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
     return (_hexa_printer(arg, "0123456789ABCDEF", buffer_array, flag, 'X', width, precision, size));
}
/**
 * _hexa_printer - Prints a hexadecimal number in lower or upper
 * @arg: Lista of arguments
 * @map_tool: Array of values to map the number to
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @flag_channel: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */
int _hexa_printer(va_list arg, char map_tool[], char buffer_array[],
	int flag, char flag_channel, int width, int precision, int size)
{
    int i = BUFFER_SIZE - 2;
    unsigned long int n = va_arg(arg, unsigned long int);
    unsigned long int num = n;

    UNUSED(width);

    n = _unsigned_converter(n, size);

    if (n == 0)
        buffer_array[i--] = '0';

    buffer_array[BUFFER_SIZE - 1] = '\0';

    while (n > 0)
    {
        buffer_array[i--] = map_tool[n % 16]; /* modulus by hexa */
        n /= 16;
    }

    if (flag & _HASH && num != 0)
    {
        buffer_array[i--] = flag_channel;
        buffer_array[i--] = '0';
    }

    i++;

    return (write_unsigned(0, i, buffer_array, flag, width, precision, size));
}
