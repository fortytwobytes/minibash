/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:38:56 by relkabou          #+#    #+#             */
/*   Updated: 2023/01/31 23:38:57 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minibash.h"

/* ---------- MISC ------------ */
int		ft_atoi(char *str);
int		is_char_in_str(char *str, char c);

/* ---------- ERRORS ------------ */
void	ft_exit(int status, char *msg);
void	fatal(char *cmd, char *msg);

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
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_sep(char *s1, char *s2, char sep);
int		contains(char *s, char c);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dst, void *src, size_t size);

/* ---------- PRINTS ------------ */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long nbr, int fd);
void	ft_puthex_fd(unsigned long nbr, int fd, char form);

#endif // UTILS_H
