#include "shell.h"

/**
 * setAlias - Function sets alias.
 * @name: This is the name of the alias.
 * @value: This The value of the alias.
 * Return: Void.
 */
alias_t *alias_list = NULL;
void setAlias(char *name, char *value)
{
	alias_t *new_alias = malloc(sizeof(alias_t));

	if (new_alias == NULL)
	{
		return;
	}
	new_alias->name = strdup(name);
	new_alias->value = strdup(value);
	new_alias->next = alias_list;
	alias_list = new_alias;
}

/**
 * getAlias - Function Retrieves the value of an alias.
 * @name: This is the name of the alias.
 * Return: The value of the alias, or NULL if the alias does not exist.
 */
char *getAlias(char *name)
{
	alias_t *current = alias_list;

	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
		{
			return (current->value);
		}
		current = current->next;
	}
	return (NULL);
}
