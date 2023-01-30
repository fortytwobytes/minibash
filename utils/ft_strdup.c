/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:13:48 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/29 20:13:49 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	dup = ft_calloc(sizeof(char) * (ft_strlen(s1) + 1));
	while (s1 && s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
