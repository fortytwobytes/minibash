/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:37:22 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 07:02:20 by relkabou         ###   ########.fr       */
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
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "builtin.h"
# include "parsing.h"
# include "execution.h"
# include "srcs.h"
# include "utils.h"

# define TRUE 1
# define FALSE 0

# define PROMPT "$> "

# define READ 0
# define WRITE 1

# define ADD 1
# define APPEND 2

typedef struct s_global	t_global;
extern t_global			g_global;
typedef struct s_envs	t_envs;
typedef struct s_cmd	t_cmd;

struct s_envs
{
	char	*name;
	char	*value;
	int		index;
	t_envs	*next;
};

struct s_global
{
	int		exit_status;
	int		heredoc_flag;
	t_envs	*envs;
};

void	shell_loop(void);
#endif // MINISHELL_H
