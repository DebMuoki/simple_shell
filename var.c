#include "shell.h"
/**
 * replaceVariables - Replaces variables in a command with their values.
 * @command: The command string.
 *
 * Return: A new string with variables replaced by their values.
 */
char *replaceVariables(char *command)
{
	char *newCommand = malloc(MAX_COMMAND_LENGTH);
	int i = 0, j = 0, k = 0;
	char varName[MAX_COMMAND_LENGTH];
	char *varValue;
	int lastExitStatus = 0;

	while (command[i] != '\0')
	{
		if (command[i] == '$')
		{
			i++;
			while (isalnum(command[i]) || command[i] == '_')
			{
				varName[k++] = command[i++];
			}
			varName[k] = '\0';
			if (strcmp(varName, "?") == 0)
			{
				varValue = malloc(4);
				sprintf(varValue, "%d", lastExitStatus);
			}
			else if (strcmp(varName, "$") == 0)
			{
				varValue = malloc(10);
				sprintf(varValue, "%d", getpid());
			}
			else
			{
				varValue = getenv(varName);
			}

			if (varValue != NULL)
			{
				strcpy(newCommand + j, varValue);
				j += strlen(varValue);
			}
		}
		else
		{
			newCommand[j++] = command[i++];
		}
	}
	newCommand[j] = '\0';
	return (newCommand);
}
