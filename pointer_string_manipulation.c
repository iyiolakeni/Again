#include "main.h"

/**
 * _pointer_value - Prints the value of a pointer variable
 * @arg: List a of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed.
 */
int _pointer_value(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
    char c = 0;
    char space = ' ';
    int index = BUFFER_SIZE - 2;
    int len = 2;
    int space_begining = 1;
    unsigned long num;
    char map_tool[] = "0123456789abcdef";
    void *add = va_arg(arg, void *);

    UNUSED(width);
    UNUSED(size);

    if (add == NULL)
        return (write(1, "(nil)", 5));

    buffer_array[BUFFER_SIZE - 1] = '\0';
    UNUSED(precision);

    num = (unsigned long)add;

    while (num > 0)
    {
        buffer_array[index--] = map_tool[num % 16];
        num /= 16;
        len++;
    }

    if ((flag & _ZERO) && !(flag & _MINUS))
        space = '0';
    if (flag & _PLUS)
        c = '+', len++;
    else if (flag & _SPACE)
        c = ' ', len++;

    index++;

    return (_pointer_print(buffer_array, index, len,
        width, flag, space, c, space_begining));
}

/**
 * _hexa_np - Prints ascii codes in hexa of non printable chars
 * @arg: List of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
*/
int _hexa_np(va_list arg, char buffer_array[], int flag, int width, int precision, int size)
{
    int i = 0;
    int offset = 0;
    char *str = va_arg(arg, char *);

    UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

    if (str == NULL)
        return (write(1, "(null)", 6));

    while (str[i] != '\0')
    {
        if (_print_check(str[i]))
            buffer_array[i + offset] = str[i];
        else
            offset += _add_hex(str[i], buffer_array, i + offset);

        i++;
    }

    buffer_array[i + offset] = '\0';

    return (write(1, buffer_array, i + offset));
}

/**
 * _reverse_string - Prints reverse string.
 * @arg: List of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Numbers of chars printed
 */
int _reverse_string(va_list arg, char buffer_array[],  int flag, int width, int precision, int size)
{
    char *str;
    int i;
    int j = 0;

    UNUSED(buffer_array);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(size);

    str = va_arg(arg, char *);

    if (str == NULL)
    {
        UNUSED(precision);
        str = ")Null(";
    }
    for (i = 0; str[i]; i++)
        ;

    for (i = i - 1; i >= 0; i--)
    {
        char new_str = str[i];

        write(1, &new_str, 1);
        j++;
    }
    return (j);
}

/**
 * _rot13 - Print a string in rot13.
 * @arg: Lista of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Numbers of chars printed
 */
 int _rot13(va_list arg, char buffer_array[], int flag, int width, int precision, int size)
 {
     char a;
     char *str;
     unsigned int i;
     unsigned int j;
     int counter = 0;
     char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
     char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

     str = va_arg(arg, char *);
     UNUSED(buffer_array);
     UNUSED(flag);
     UNUSED(width);
     UNUSED(precision);
     UNUSED(size);
     if (str == NULL)
        str = "(AHYY)";
     for (i = 0; str[i] != '\0'; i++)
     {
         for (j = 0; input[j] != '\0'; j++)
         {
             if (input[j] == str[i])
             {
                 a = output[j];
                 write(1, &a, 1);
                 counter++;
                 break;
             }
         }
         if (!input[j])
         {
             a = str[i];
             write(1, &a, 1);
             counter++;
         }
     }
     return (counter);
 }
