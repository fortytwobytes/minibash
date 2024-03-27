/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:14:14 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/29 20:14:16 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minibash.h"

// a function that free split return : a 2d array of string terminated by NULL;
void	free_split(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
