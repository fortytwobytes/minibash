#ifndef SRCS_H
#define SRCS_H

#include "minishell.h"

int		ft_open(char *path, int oflag, int mode);
void	ft_close(int fildes);
void	ft_pipe(int fd[2]);
void	ft_dup(int fildes);
void	ft_wait(int *stat_loc);
void	ft_dup2(int fildes, int fildes2);
void	ft_execve(char *path, char **argv, char **envp);
void	ft_waitpid(pid_t pid, int *stat_loc, int options);
void	ft_wait3(int *wstatus, int options, struct rusage *rusage);
void	ft_wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage);
pid_t	ft_fork(void);

#endif // SRCS_H
