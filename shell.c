#include "shell.h"

/**
 * readCommand - Reads a command from the user
 * @input: Buffer to store the input command
 *
 * Return: 0 on Ctrl+D (EOF), 1 otherwise.
 */
int readCommand(char *input)
{
	if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		printf("\n");
		return (0);
	}
	stripNewline(input);
	return (1);
}

/**
 * stripNewline - Removes the trailing newline character from a string
 * @str: The string to modify
 */
void stripNewline(char *str)
{
	char *newline = strchr(str, '\n');

	if (newline != NULL)
	{
		*newline = '\0';
	}
}

/**
 * executeCommand - Executes a command with arguments in a child process
 * @command: The command and its arguments as a single string
 */

void executeCommand(char *command)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		char *args[MAX_COMMAND_LENGTH];

		parseArguments(command, args);
		if (execvp(args[0], args) == -1)
		{
		perror("exec");
		exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * parseArguments - Parses a command string into an array of arguments
 * @command: The command and its arguments as a single string
 * @args: An array to store the parsed arguments
 *
 * Return: The number of parsed arguments.
 */
int parseArguments(char *command, char *args[])
{
	int argc = 0;
	char *token = strtok(command, " \t\n");

	while (token != NULL && argc < MAX_COMMAND_LENGTH - 1)
	{
		args[argc++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[argc] = NULL;
	return (argc);
}

/**
 * printEnvironment - Prints the current environment variables
 */
void printEnvironment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
