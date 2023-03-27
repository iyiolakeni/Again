#include "main.h"

/**
 * active_flag - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int active_flag(const char *format, int *i)
{
    /* Flag Types */
    /* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j = 0;
	int index;
	int flag = 0;
	const char flag_sign[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_arrays[] = {_MINUS, _PLUS, _ZERO, _HASH, _SPACE, 0};

	for (index = *i + 1; format[index] != '\0'; index++)
    {
        while (flag_sign[j] != '\0')
        {
            if (format[index] == flag_sign[j])
            {
                flag |= flag_arrays[j];
                break;
            }
            j++;
        }

        if (flag_arrays[j] == 0)
            break;
    }

    *i = index - 1;

    return (flag);
}
