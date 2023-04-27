#include "main.h"
/**
 * is_printable - function name
 * @c: Char.
 *
 * Return: returns 1 if it's a success and 0 if it's not
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * append_hexa_code - function name.
 * @buffer: buffer array.
 * @i: Index.
 * @ascii_code: ASSCI sheet codes.
 * Return: returns 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - function
 * @c: Char
 *
 * Return: returns 1 if it's a success 0 if it's not
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * convert_size_number - function name
 * @num: casted nunmber
 * @size: number of cast.
 *
 * Return: returns num's value
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}
/**
 * convert_size_unsgnd - function name
 * @num: casted number
 * @size: number of casted
 *
 * Return: returns value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
