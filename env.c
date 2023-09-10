#include "shell.h"
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
