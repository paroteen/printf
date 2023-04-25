#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int a, curr_x;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_x = *i + 1; format[curr_x] != '\0'; curr_x++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
			if (format[curr_x] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}

		if (FLAGS_CH[a] == 0)
			break;
	}

	*i = curr_x - 1;

	return (flags);
}

