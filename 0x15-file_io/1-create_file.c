#include "main.h"
#include <stdlib.h>

/**
 * create_file - a function that creates a file
 * @filename: the name of the file to be created by the function
 * @text_content: string to be writen in the file created
 * Return: 1 on success or -1 when the file fails, otherwise -1
 */
int create_file(const char *filename, char *text_content)
{
	int ft, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	ft = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(ft, text_content, len);

	if (ft == -1 || w == -1)
		return (-1);

	close(ft);
	return (1);
}
