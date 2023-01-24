#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"


/* ---------- ERRORS ------------ */
void	ft_exit(int status, char *msg);

/* ---------- STRINGS ------------ */
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t size);
size_t	ft_strlen(char *str);
void	free_split(char **s);
char	*ft_substr(char *s, size_t start, size_t end);
int		is_upper(char c);
int		is_lower(char c);
int		is_num(char c);


/* ---------- PRINTS ------------ */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long nbr, int fd);
void	ft_putptr_fd(void *nbr, int fd);
void	ft_fprintf(int fd, char *s, ...);
void	ft_puthex_fd(unsigned long nbr, int fd, char form);

#endif // UTILS_H
