#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file print to STDOUT
 * @filename: text file that is being read and printed
 * @letters: number of letters that are to be read
 *
 * Return: w- actual number of letters read and printed
 * or 0 when the function fails/the filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
