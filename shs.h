#ifndef SHS_H_INCLUDED
#define SHS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

void _ntty(char *);
void _itty(char *);
void _exec( char *, char **);
void _read(char **, char **);
char *_getenv(char *);
int _findcmd(char **, char *, char *);
char *token_command(char *command_line);
char **token_arguments(char *command_line);
void print_env(char **env)

#endif
