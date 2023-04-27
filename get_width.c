#include "main.h"
int get_width(const char *format, int *i, va_list list)
{
	int me;
	int width = 0;

	for (me = *i + 1; format[me] != '\0'; me++)
	{
		if (is_digit(format[me]))
		{
			width *= 10;
			width += format[me] - '0';
		}
		else if (format[me] == '*')
		{
			me++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = me - 1;

	return (width);
}
