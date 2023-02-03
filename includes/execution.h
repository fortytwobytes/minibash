/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:37:12 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 06:35:30 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"

typedef struct s_envs	t_envs;
typedef struct s_cmd	t_cmd;

void	shell_loop(void);
void	execute(t_cmd *head);
int		exec_single_cmd(t_cmd *head, t_cmd *cmd);
void	command_not_found(void);
int		is_updated(char *name, char *value, int option);
void	add_env(t_envs **envs, char *name, char *value);
void	pop_env(char *name);
char	*ft_getenv(char *name);
char	*get_env_value(char *name);
t_envs	*envs_init(char **env);
void	ft_setenv(char *name, char *value);
void	close_all_fds(t_cmd *head);

char	**dynamic_env(void);
char	*here_doc_name(void);
char	*ft_getpath(char *cmd);
void	update_env(char *name, char *value);

void	default_signals(void);
void	handle_signals(void);
void	ignore_signals(void);
void	sigint_heredoc(void);
void	change_flag(int s);

#endif // EXECUTION_H
