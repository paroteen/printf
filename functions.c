#include "main.h"

/**
 * print_char - function to be printed
 * @types: arguments
 * @buffer: Buffer arra.
 * @flags: flags
 * @width: Width
 * @precision: specification
 * @size: size
 * Return: returns number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char b = va_arg(types, int);

	return (handle_write_char(b, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints string
 * @types: arguments
 * @buffer: Buffer array
 * @flags: flags
 * @width: width.
 * @precision: specification
 * @size: size
 * Return: returns number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * print_percent - function to be printed
 * @types: arguments
 * @buffer: Buffer array.
 * @flags: flags
 * @width: width.
 * @precision: specification
 * @size: Size.
 * Return: returns number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/**
 * print_int - function
 * @types: arguments
 * @buffer: Buffer array
 * @flags: flags
 * @width: width.
 * @precision: specification
 * @size:  specifier
 * Return: returns number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - function
 * @types: arguments
 * @buffer: Buffer array
 * @flags:  flags
 * @width: width.
 * @precision: specification
 * @size: specifier
 * Return: returns numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, x, sum;
	unsigned int a[32];
	int c;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (x = 1; x < 32; x++)
	{
		m /= 2;
		a[x] = (n / m) % 2;
	}
	for (x = 0, sum = 0, c = 0; x < 32; x++)
	{
		sum += a[x];
		if (sum || x == 31)
		{
			char z = '0' + a[x];

			write(1, &z, 1);
			c++;
		}
	}
	return (c);
}

