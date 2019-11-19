#ifndef SHS_H_INCLUDED
#define SHS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

void _ntty(char *);
void _itty(char *);
void _read(char **);
char *token_command(char *command_line);
char **token_arguments(char *command_line);

#endif
