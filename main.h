#ifndef MAIN_H_
#define MAIN_H_
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS DEFINITION */
/* FLAGS */
#define _MINUS 1
#define _PLUS 2
#define _ZERO 4
#define _HASH 8
#define _SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Struct op
 *
 * @format: The format.
 * @func: The function associated.
 */
struct format
{
	char format;
	int (*func)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format format_t - Struct op
 *
 * @format: The format.
 * @format_t: The function associated.
 */
typedef struct format format_t;

int _printf(const char *format, ...);

/**** PRINTER *****/
int _printer(const char *format, int *no, va_list arg, char buffer_array[],
	int flag, int width, int precision, int size);
void _print_buffer(char buffer_array[], int *buff_index);
/********** PRINT STRING DATA TYPES******/
int _char(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size);
int _string(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size);
int _percent(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size);

/******** PRINT NUMBER/BINARY DATA TYPES ****/
int _int(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size);
int _binary(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size);

/******* PRINT UNSIGNED NUMBERS DATA TYPES FUNCTION *******/
int _unsigned(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size);
int _octal(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size);
int _hexadecimal(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size);
int _unsigned_hexa(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size);

/***** POINTER AND STRING MANIPULATION PRINTER *****/
int _pointer_value(va_list arg, char buffer_array[], int flag, int width, int precision, int size);
int _hexa_np(va_list arg, char buffer_array[], int flag, int width, int precision, int size);
int _reverse_string(va_list arg, char buffer_array[], int flag, int width, int precision, int size);
int _rot13(va_list arg, char buffer_array[], int flag, int width, int precision, int size);

/*** Handle Specifiers such as size, width, flag and precision ****/
int _precision(const char *format, int *index, va_list arg);
int _size(const char *format, int *index);
int _width(const char *format, int *index, va_list arg);
int active_flag(const char *format, int *i);


/***** HANDLER ******/
int _char_printer(char c, char buffer_array[], int flag, int width, int precision, int size);
int _number_printer(int is_negative, int c, char buffer_array[], int flag, int width, int precision, int size);
int number_buffer(int index, char buffer_array[], int flag, int width, int precise, int length, char pad, char c);
int _pointer_print(char buffer_array[], int index, int length, int width, int flag, char pad, char c, int pad_start);
int write_unsigned(int is_negative, int index, char buffer_array[], int flag, int width, int precision, int size);


/******* Number Checker and Cast *******/
int _print_check(char);
int _add_hex(char, char[], int);
int _is_digit(char);
/******* Converters *******/
long int _number_size(long int num, int size);
long int _unsigned_converter(unsigned long int num, int size);
int _hexa_printer(va_list arg, char map_tool[], char buffer_array[], int flag, char flag_channel, int width, int precision, int size);
#endif
