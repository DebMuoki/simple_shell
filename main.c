#include "shell.h"

/**
 * startsWith - Checks if a string starts with a specified prefix.
 * @str: The string to check.
 * @prefix: The prefix to look for.
 *
 * Return: 1 if the string starts with the prefix, 0 otherwise.
 */
int startsWith(const char *str, const char *prefix)
{
	while (*prefix)
	{
		if (*prefix != *str)
		{
			return (0);
		}
		prefix++;
		str++;
	}
	return (1);
}
/**
 * main - Simple UNIX command line interpreter
 *
 * Description: A basic command line interpreter that reads one-word
 * commands from the user, executes them, and displays the results.
 * It handles "end of file" (Ctrl+D) to exit the shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *input = NULL;
	size_t n = 0;
	ssize_t len;

	while (1)
	{
		len = get_line(&input, &n, STDIN_FILENO);
		if (len <= 0)
		{
			break;
		}
		if (len > 0 && input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
			len--;
		}

		if (strcmp(input, "exit") == 0)
		{
			exit(0);
		}
		else if (startsWith(input, "exit "))
		{
			char *status_str = input + 5;
			int status = atoi(status_str);

			exit(status);
		}
		else if (startsWith(input, "setenv "))
		{
			char *args[MAX_COMMAND_LENGTH];

			if (parseArguments(input, args) != 3)
			{
				fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
			}
			else
			{
				setEnvironmentVariable(args[1], args[2]);
			}
		}
		else if (startsWith(input, "unsetenv "))
		{
			char *args[MAX_COMMAND_LENGTH];

			if (parseArguments(input, args) != 2)
			{
				fprintf(stderr, "Usage: unsetenv VARIABLE\n");
			}
			else
			{
				unsetEnvironmentVariable(args[1]);
			}
		}
		else if (startsWith(input, "cd "))
		{
			char *args[MAX_COMMAND_LENGTH];

			if (parseArguments(input, args) != 2)
			{
				fprintf(stderr, "Usage: cd [DIRECTORY]\n");
			}
			else
			{
				changeDirectory(args[1]);
			}
		}
		else if (strcmp(input, "cd") == 0)
		{
			changeDirectory("~");
		}
		else if (strcmp(input, "env") == 0)
		{
			printEnvironment();
		}
		else
		{
			executeCommand(input);
		}
	}

	free(input);
	return (0);
}
