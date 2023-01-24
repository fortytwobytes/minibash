#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

/* ---------- MISC ------------ */
int		ft_atoi(char *str);

/* ---------- ERRORS ------------ */
void	ft_exit(int status, char *msg);
void    fatal(char *cmd, char *msg, int fd);

/* ---------- STRINGS ------------ */
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t size);
size_t	ft_strlen(char *str);
void	free_split(char **s);
char	*ft_substr(char *s, size_t start, size_t end);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_sep(char *s1, char *s2, char sep);

/* ---------- PRINTS ------------ */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long nbr, int fd);
void	ft_puthex_fd(unsigned long nbr, int fd, char form);

#endif // UTILS_H
