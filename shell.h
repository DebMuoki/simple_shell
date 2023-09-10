#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND_LENGTH 100
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

int main(void);
int readCommand(char *input);
void stripNewline(char *str);
void executeCommand(char *command);
int parseArguments(char *command, char *args[]);
void printEnvironment(void);

#endif
