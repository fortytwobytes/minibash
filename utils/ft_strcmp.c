#include "utils.h"

static int	get_return(char a, char b);

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (get_return(*s1, *s2));
		s1++;
		s2++;
	}
	return (get_return(*s1, *s2));
}

static int	get_return(char a, char b)
{
	if (a == b)
		return (0);
	if (a > b)
		return (1);
	return (-1);
}
