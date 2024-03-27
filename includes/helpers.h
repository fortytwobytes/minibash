/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:39:03 by relkabou          #+#    #+#             */
/*   Updated: 2023/01/31 23:39:04 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

# include "minishell.h"

int		ft_open(char *path, int oflag, int mode);
void	ft_close(int fildes);
void	ft_pipe(int fd[2]);
void	ft_dup(int fildes);
void	ft_wait(int *stat_loc);
void	ft_dup2(int fildes, int fildes2);
void	ft_execve(char *path, char **argv);
void	ft_waitpid(pid_t pid);
pid_t	ft_fork(void);

#endif // SRCS_H
