#include "shell.h"

/**
 * custom_getline - Custom implementation of getline.
 * @buffer: Pointer to the buffer where the line will be stored.
 * @buf_size: The size of the buffer.
 *
 * Return: The number of characters read (including newline), or -1 on failure.
 */
ssize_t custom_getline(char **buffer, size_t *buf_size)
{
	static char static_buffer[BUFFER_SIZE];
	static ssize_t buffer_index = 0;
	static ssize_t buffer_size = 0;
	ssize_t total_bytes = 0;
	ssize_t max_len = *buf_size;
	char c;

	if (buffer == NULL || buf_size == NULL || max_len <= 0)
		return (-1);

	while (1)
	{
		if (buffer_index >= buffer_size)
		{
		buffer_index = 0;
		buffer_size = read(STDIN_FILENO, static_buffer, BUFFER_SIZE);
		if (buffer_size <= 0)
			return (-1);
		}
		c = static_buffer[buffer_index++];
		(*buffer)[total_bytes++] = c;

		if (total_bytes >= max_len)
		return (total_bytes);

		if (c == '\n')
		return total_bytes;
	}
}
