#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file print to stdout
 * @filename: text file that is being read and printed
 * @letters: number of letters that are to be read
 *
 * Return: w- actual number of letters read and printed
 * or 0 when the function fails/the filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *but;
	ssize_t ft;
	ssize_t w;
	ssize_t r;

	ft = open(filename, O_RDONLY);
	if (ft == 1)
		return (0);
	but = malloc(sizeof(char) * letters);
	r = read(ft, but, letters);
	w = write(STDOUT_FILENO, but, r);

	free(but);
	close(ft);
	return (w);
}
