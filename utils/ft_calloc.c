#include "utils.h"

void	*ft_calloc(size_t size)
{
	size_t	i;
	char	*memory_area;

	i = 0;
	memory_area = malloc(size);
	if (!memory_area)
		ft_exit("malloc error", 1);
	while (i <= size)
	{
		memory_area[i] = 0;
		i++;
	}
	return ((void *)memory_area);
}
