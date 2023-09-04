#include "main.h"

/**
 * create_file - It creates a file.
 * @filename: A pointer for naming the file that we will create.
 * @text_content: A string's pointer to write the file.
 *
 * Return: If the function fails it returns -1.
 *         if it is not it returns 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
