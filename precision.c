#include "main.h"

/**
 * get_precision - function`
 * @format: Formatted string
 * @i: List of arguments.
 * @list: list all arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_b = *i + 1;
	int prec = -1;

	if (format[curr_b] != '.')
		return (prec);

	prec = 0;

	for (curr_b += 1; format[curr_b] != '\0'; curr_b++)
	{
		if (is_digit(format[curr_b]))
		{
			prec *= 10;
			prec += format[curr_b] - '0';
		}
		else if (format[curr_b] == '*')
		{
			curr_b++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_b - 1;

	return (prec);
}

