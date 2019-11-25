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
int _findcmd(char **, char *, char *, int *);
char *token_command(char *);
char **token_arguments(char *);
void print_env();
void _free_all(char *, char **, char *);
int _getpath(char **, char *);

#endif
