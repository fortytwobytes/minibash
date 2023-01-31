/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:37:22 by relkabou          #+#    #+#             */
/*   Updated: 2023/01/31 23:59:38 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define TRUE 1
# define FALSE 0

# define PROMPT "$> "

# define READ 0
# define WRITE 1

# define ADD 1
# define APPEND 2

typedef struct s_envs	t_envs;
typedef struct s_cmd	t_cmd;
typedef struct s_global	t_global;

extern t_global	global; // global variable must start with g_ (NORM)

struct s_envs
{
	char	*name;
	char	*value;
	int		index;
	t_envs	*next;
};

struct s_global
{
	char	**env;
	char	*path;	
	char	*pwd;
	int		exit_status;
	t_envs	*envs;
};

void	shell_loop(void);

// missaligned includes declaration (NORM) 
# include "builtin.h"
# include "execution.h"
# include "parsing.h"
# include "srcs.h"
# include "utils.h"

#endif // MINISHELL_H
