/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:13:07 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/29 20:13:08 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minibash.h"

char	*ft_substr(char *s, size_t start, size_t end)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = end - start;
	i = 0;
	word = ft_calloc(len + 1);
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	return (word);
}
