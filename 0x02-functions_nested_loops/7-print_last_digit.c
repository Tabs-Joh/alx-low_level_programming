#include "main.h"

/**
 * print_last_digit - Prints last digit of the number
 * @n: The number to be treated
 * Return: Value of the last number
 */

int print_last_digit(int n)
{
	int last;

	last = n % 10;
	if (last < 0)
	{
		last = last * -1;
	}
	_putchar(last + '0');
	return (last);
}
