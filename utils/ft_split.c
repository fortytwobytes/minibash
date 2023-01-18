#include "utils.h"

static void		*free_all(char **tab, int i);
static char		*allocate_word(char *str, char c);
static size_t	ft_strlen_sep(char *str, char c);
static size_t	count_strings(char *str, char c);

char	**ft_split(char *s, char c)
{
	char	**str;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	str = ft_calloc(sizeof(char *) * (count_strings((char *)s, c) + 1));
	if (!str)
		ft_exit(EXIT_FAILURE, "malloc error");
	while (*(char *)s)
	{
		while (*(char *)s && *(char *)s == c)
			s++;
		if (*(char *)s)
		{
			*(str + i) = allocate_word((char *)s, c);
			if (!*(str + i))
				return (free_all(str, i),
					ft_exit(EXIT_FAILURE, "malloc error"), NULL);
			i++;
		}
		while (*(char *)s && *(char *)s != c)
			s++;
	}
	return (str);
}

static size_t	count_strings(char *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (*(str + i))
	{
		while (*(str + i) && *(str + i) == c)
			i++;
		if (*(str + i))
			count++;
		while (*(str + i) && *(str + i) != c)
			i++;
	}
	return (count);
}

static char	*allocate_word(char *str, char c)
{
	size_t	len_word;
	size_t	i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(str, c);
	word = ft_calloc(sizeof(char) * (len_word + 1));
		ft_exit(EXIT_FAILURE, "malloc error");
	while (i < len_word)
	{
		*(word + i) = *(str + i);
		i++;
	}
	return (word);
}

static size_t	ft_strlen_sep(char *str, char c)
{
	size_t	i;

	i = 0;
	while (*(str + i) && *(str + i) != c)
		i++;
	return (i);
}

static void	*free_all(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}
