#include "shell.h"
/**
 * get_line - reads an entire line from file descriptor
 * @lineptr: pointer to a buffer to hold the line of text
 * @n: pointer to the size of the buffer
 * @fd: file descriptor to read from
 *
 * Return: number of characters read, or -1 on failure
 */

ssize_t get_line(char **lineptr, size_t *n, int fd)
{
	static char buffer[BUFFER_SIZE];
	static char *p;
	static ssize_t len;
	size_t line_len = 0;

	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}
	if (*lineptr == NULL)
	{
		*lineptr = malloc(BUFFER_SIZE);
		if (*lineptr == NULL)
		{
			return (-1);
		}
		*n = BUFFER_SIZE;
	}
	while (1)
	{
		if (len <= 0)
		{
			len = read(fd, buffer, BUFFER_SIZE);
			if (len < 0)
			{
				return (-1);
			}
			else if (len == 0)
			{
				return (line_len);
			}
				p = buffer;
		}
		if (line_len + len >= *n)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
			{
				return (-1);
			}
		}
		while (len > 0)
		{
			(*lineptr)[line_len++] = *p++;
			len--;
			if ((*lineptr)[line_len - 1] == '\n')
			{
				(*lineptr)[line_len] = '\0';
				return (line_len);
			}
		}
	}
}
