#include "main.h"
#include <stdlib.h>

/**
 * append_text_to_file - appends text at the end of the file
 * @filename: the name of the file at which text is to append
 * @text_content: the text to append at the end of the file
 *
 * Return: -1 if the function fails or is NULL
 * or if the file does not exist -1
 * otherwise 1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int r, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	r = open(filename, O_WRONLY | O_APPEND);
	w = write(r, text_content, len);

	if (r == -1 || w == -1)
		return (-1);
	close(r);
	return (1);
}
