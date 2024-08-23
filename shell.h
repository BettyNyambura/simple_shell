#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int _strlen(char *str);
char *get_input(char **buffer, size_t *bufsize);
char *strDup(char *str);
char *strCpy(char *dest, char *src);
char *strCat(char *str2, char *str1);
int execute(char *command);
void signal_handler(int file_des);

#endif
