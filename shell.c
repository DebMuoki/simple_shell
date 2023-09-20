#include "shell.h"

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
 * findCommandPath - Searches for the full path of a command
 * @command: The command to search for
 * @full_path: A buffer to store the full path of the command
 *
 * Return: 1 if the command was found, 0 otherwise.
 */
int findCommandPath(char *command, char *full_path)
{
	char *path = getenv("PATH");
	int path_len = strlen(path);
	int full_path_len = 0;
	int i;

	for (i = 0; i <= path_len; i++)
	{
		if (path[i] == ':' || path[i] == '\0')
		{
			if (full_path_len == 0)
				snprintf(full_path, MAX_COMMAND_LENGTH, "./%s", command);
			else
			{
				full_path[full_path_len] = '/';
				full_path_len++;
				strcpy(full_path + full_path_len, command);
			}

			if (access(full_path, X_OK) == 0)
			{
				return (1);
			}
			full_path_len = 0;
		}
		else
		{
			full_path[full_path_len] = path[i];
			full_path_len++;
		}
	}
	return (0);
}

/**
 * executeCommand - Executes a command with arguments in a child process
 * @command: The command and its arguments as a single string
 */
int executeCommand(char *command)
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

		if (parseArguments(command, args) == -1)
		{
			fprintf(stderr, "Error parsing arguments\n");
			exit(EXIT_FAILURE);
		}
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (status);
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
	char *token = command;

	while (*token != '\0' && argc < MAX_COMMAND_LENGTH - 1)
	{
		while (*token == ' ' || *token == '\t')
			token++;

		if (*token == '\0')
			break;

		args[argc++] = token;
		while (*token != ' ' && *token != '\t' && *token != '\0')
			token++;

		if (*token != '\0')
			*token++ = '\0';
	}
	args[argc] = NULL;
	return (argc);
}
