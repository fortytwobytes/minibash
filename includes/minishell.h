#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include "readline/readline.h"
#include "readline/history.h"

#define TRUE 1
#define FALSE 0

#define PROMPT "$> "

#define READ 0
#define WRITE 1

typedef struct s_main t_main;
struct s_main
{
	int		argc;
	char	**argv;
	char	**envp;
};

void shell_loop(t_main *main);

#include "utils.h"
#include "parsing.h"
#include "builtin.h"
#include "parsing.h"

#endif // MINISHELL_H
