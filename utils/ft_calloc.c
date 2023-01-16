#include "minishell.h"

void *ft_bzero(void *p,size_t bytes)
{
	size_t i;

	i = 0;
	while(i < bytes)
	{
		*((char *)p + i) = 0;
		i++;
	}
}

void *ft_calloc(size_t bytes)
{
	void	*p;

	p = malloc(bytes);
	if (!p)
		ft_exit(EXIT_FAILURE,"malloc");
	ft_bzero(p,bytes);
	return p;
}
