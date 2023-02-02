/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:45:49 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 23:48:22 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*get_name_(char *args)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = NULL;
	while (args[i])
	{
		if (args[i] == '=')
			break ;
		if (args[i] == '+' && args[i + 1] == '=')
			break ;
		i++;
	}
	buffer = ft_calloc(i + 1);
	ft_memcpy(buffer, args, i);
	return (buffer);
}

char	*get_value_(int index, char *str)
{
	int		len;
	char	*buffer;

	len = ft_strlen(str);
	if (str[index] == 0)
		return (NULL);
	if (str[index] == '+')
		index ++;
	else if (str[index + 1] == 0)
		return (ft_strdup(""));
	buffer = ft_calloc(len - index + 1);
	ft_memcpy(buffer, str + index + 1, len - index);
	return (buffer);
}
