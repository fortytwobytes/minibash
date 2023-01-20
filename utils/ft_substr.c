#include "minishell.h"

char	*ft_substr(char *s, size_t start, size_t end)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = end - start;
	i = 0;
	word = ft_calloc(len + 1);
	while(i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	return (word);
}