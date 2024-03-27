/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:36:46 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/03 14:12:43 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minibash.h"

int		size_of_env(void);
void	index_envs(void);
int		is_export_valid(char *exp);
int		cd(char **args, int fd);
void	pwd(char **args, int fd);
void	echo(char **args, int fd);
void	env(char **args, int fd);
int		unset(char **args, int fd);
int		export(char **args, int fd);
int		shell_exit(char **args);
int		is_builtins(char *cmd);
int		exec_builtins(char **args, int outfile);
char	*get_name_(char *args);
char	*get_value_(int index, char *str);

#endif // BUILITIN_H
