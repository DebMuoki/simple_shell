#include "shell.h"

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
			break;
		}
		if (strcmp(input, "env") == 0)
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
