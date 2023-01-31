#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int		size_of_env(void);
void	index_envs(void);

void	cd(char **args, int fd);
void	pwd(char **args, int fd);
void	echo(char **args, int fd);
void	env(char **args, int fd);
void	unset(char **args, int fd);
void	export(char **args, int fd);
int		shell_exit(char **args);
int		is_builtins(char *cmd);
int		exec_builtins(char **args, int outfile);

#endif // BUILITIN_H
