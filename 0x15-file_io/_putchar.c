#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes character c to stdout
 * @c: the character to print
 * Return: 1 on sucess
 * on error, return -1, and set error appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
