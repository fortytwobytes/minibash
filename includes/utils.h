#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *str, int fd);
void	*ft_calloc(size_t size);
void	ft_exit(int status, char *msg);
size_t	ft_strlen(char *str);
void	free_split(char **s);
char	*ft_substr(char *s, size_t start, size_t end);
#endif // UTILS_H
