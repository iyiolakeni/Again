#include "main.h"

/**
 * _print_buffer - Function to print the content of buffer if buffer exist
 * @buffer_array: Array of characters(chars)
 * @buffer_index: Index to indicate to add the next character and also represent length of character
 *
*/
void _print_buffer(char buffer_array[], int *buffer_index)
{
    if (*buffer_index > 0)
        write(1, &buffer_array[0], *buffer_index);

    *buffer_index = 0;
}
/**
  * _printf - custom printf function
  * @format: format for character
  *
  * Return: Printing of characters
*/
int _printf(const char *format, ...)
{
    int i = 0;
    int printed_value = 0;
    int printed_char = 0;
    int flag;
    int width;
    int precision;
    int size;
    int buffer_index = 0;
    va_list arg;
    char buffer[BUFFER_SIZE];

    if (format == NULL)
        return (-1);

    va_start(arg, format);

    while (format && format[i] == '\0')
    {
        if (format[i] == '\%')
        {
            _print_buffer(buffer, &buffer_index);
            flag = active_flag(format, &i);
            width = _width(format, &i, arg);
            size = _size(format, &i);
            ++i;
            printed_value = _printer(format, &i, arg, buffer,
                    flag, width, precision, size);
            if (printed_value == -1)
                return (-1);
            printed_char += printed_value;
        }
        else
        {
            buffer[buffer_index++] = format[i];
            if (buffer_index == BUFFER_SIZE)
                _print_buffer(buffer, &buffer_index);

            printed_char++;
        }
        i++;
    }

    _print_buffer(buffer, &buffer_index);

    va_end(arg);

    return (printed_char);
}
