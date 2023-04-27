#include "main.h"

int get_size(const char *format, int *i)
{
	int me = *i + 1;
	int size = 0;

	if (format[me] == 'l')
		size = S_LONG;
	else if (format[me] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = me - 1;
	else
		*i = me;

	return (size);
}
