#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int ft);

/**
 * create_buffer - used to allocate 1024 bytes of a buffer
 * @file: name of the file whose chars are stored by the buffer
 * Return: a pointer of newly allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - closes all file descriptors.
 * @ft: file descriptores that are to be closed
 */
void close_file(int ft)
{
	int l;

	l = close(ft);

	if (l == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close ft %d\n", ft);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file
 * @argc: argument count supplied to the program
 * @argv: argument vector
 * Return: 0 on success
 *
 * Descriptio - if the argument count is incorrect - exit code 97.
 * if file_from does not exist or cannot be read - exit code 98.
 * if the file_to cannot be created or written to - exit code 99.
 * if file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_file(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREATE | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argc[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
