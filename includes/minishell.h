#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/wait.h>
# include "readline/readline.h"
# include "readline/history.h"

# include "utils.h"
# include "srcs.h"
# include "parsing.h"
# include "builtin.h"
# include "parsing.h"
# include "execution.h"

# define TRUE 1
# define FALSE 0

# define PROMPT "$> "

# define READ 0
# define WRITE 1

typedef struct s_envs	t_envs;
typedef struct s_cmd	t_cmd;
typedef struct s_global	t_global;

/* ---- Global variable ---- */
extern t_global	global;
/* ------------------------- */

struct s_envs
{
	char	*name;
	char	*value;
	t_envs	*next;
};

struct s_global
{
	char	**env;
	char	*path;	
	char	*pwd;
	char	_;
	int		exit_status;
	t_envs	*envs;
};

// "_", "pwd", this variables should be always 
// updated whenever a command get executed
// "_" is a special variable that holds the last command's argument 
// i don't know if i'm gonna use it or not

void	shell_loop(void);
#endif // MINISHELL_H
