/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:14:39 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/29 20:14:41 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	ft_bzero(void *p, size_t bytes);

void	*ft_calloc(size_t bytes)
{
	void	*p;

	p = malloc(bytes);
	if (!p)
		ft_exit(EXIT_FAILURE, "malloc error");
	ft_bzero(p, bytes);
	return (p);
}

static void	ft_bzero(void *p, size_t bytes)
{
	size_t	i;

	i = 0;
	while (i < bytes)
	{
		*((char *)p + i) = 0;
		i++;
	}
}
