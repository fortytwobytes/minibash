#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *str, int fd);
void	*ft_calloc(size_t size);
void	ft_exit(char *msg, int status);
size_t	ft_strlen(char *str);

#endif // UTILS_H
