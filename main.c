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
	char input[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("$ ");

		if (readCommand(input) == 0)
		{
			break;
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
		else if (strcmp(input, "env") == 0)
		{
			printEnvironment();
		}
		else
		{
			executeCommand(input);
		}
	}
	return (0);
}
