#include "main.h"

/**
 * _char - Prints a char
 * @arg: List a of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */
int _char(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
	char c = va_arg(arg, int);

	return (_char_printer(c, buffer_array, flag, width, precision, size));
}

/**
 * _string - function to print string datatype
 * @arg: List a of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of strings printed
 */
int _string(va_list arg, char buffer_array[],
            int flag, int width, int precision, int size)
{
    int i;
    int length = 0;
    char *str_ptr = va_arg(arg, char *);

    UNUSED(buffer_array);
    UNUSED(flag);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str_ptr == NULL)
    {
        str_ptr = "(null)";
        if (precision > 5)
            str_ptr = "      ";
    }

    while (str_ptr[length] != '\0') /*iterate to determine string length*/
        length++;

    if (precision >= 0 && precision < length)
        length = precision;

    if (width > length)
    {
        if (flag & _MINUS)
        {
            write(1, &str_ptr[0], length);

            i = width - length;
            while (i != 0)
            {
                write(1, " ", 1);
                i--;
            }
            return (width);
        }
        else
        {
            i = width - length;
            while (i != 0)
            {
                write(1, " ", 1);
                i--;
            }
            write(1, &str_ptr[0], length);
            return (width);
        }
    }

    return (write(1, str_ptr, length));
}

/**
 * _percent - Prints a percent sign
 * @arg: List of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */
int _percent(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
    UNUSED(arg);
    UNUSED(buffer_array);
    UNUSED(flag);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    return (write(1, "%%", 1));
}

/**
 * _int - Print int
 * @arg: List of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _int(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
    int i = BUFFER_SIZE - 2;
    int negative = 0;
    long int num = va_arg(arg, long int);
    unsigned long int _num;

    num = _number_size(num, size);

    if (num == 0)
        buffer_array[i--] = '0';

    buffer_array[BUFFER_SIZE -1] = '\0';
    _num = (unsigned long int)num;

    if (num < 0)
    {
        _num = (unsigned long int)((-1) * num);
        negative = 1;
    }

    while (_num > 0)
    {
        buffer_array[i--] = (num % 10) + '0';
        num /=10;
    }

    i++;

    return (_number_printer(negative, i, buffer_array, flag, width, precision, size));
}

/**
 * _binary - Prints an unsigned number
 * @arg: List of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Numbers of char printed.
 */
int _binary(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
    unsigned int i = 0;
    unsigned int arg_holder;
    unsigned int binary;
    unsigned int sum;
    unsigned int arr[32];
    int counter;

    UNUSED(buffer_array);
    UNUSED(flag);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    arg_holder = va_arg(arg, unsigned int);
    binary = 2147483648; /* (2 ^ 31) */
    arr[0] = arg_holder / binary;

    for (i = 1; i < 32; i++)
    {
        binary /= 2;
        arr[i] = (arg_holder / binary) % 2;
        i++;
    }

    for (i = 0, sum = 0, counter = 0; i < 32; i++)
    {
        sum += arr[i];
        if (sum || i == 32)
        {
            char new_char = '0' + arr[i];

            write(1, &new_char, 1);
            counter++;
        }
    }
    return (counter);
}
