#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"

void	shell_loop(void);
void	execute(t_cmd *head);
int		exec_single_cmd(t_cmd *head, t_cmd *cmd);

int		is_updated(char *name, char *value);
void	add_env(t_envs **envs, char *name, char *value);
void	pop_env(char *name);
char	*ft_getenv(char *name);
char	*get_env_value(char *name);
t_envs	*envs_init(void);
void	ft_setenv(char *name, char *value);

char	**dynamic_env(void);
char	*here_doc_name(void);
char	*ft_getpath(char *cmd);

#endif // EXECUTION_H
