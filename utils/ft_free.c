#include "minishell.h"

// a function that free split return : a 2d array of string terminated by NULL;
void free_split(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return;
	while(s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
