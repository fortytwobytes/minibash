/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:59:34 by mtagemou          #+#    #+#             */
/*   Updated: 2023/02/06 12:59:36 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_name_here(char *token)
{
	int	i;
	int	name_len;

	i = 0;
	name_len = -1;
	while (token[i])
	{
		name_len = -1;
		if (token[i] == '$')
			name_len = get_name_len(token, i);
		if (name_len == 0)
			token[i] = -1;
		if (name_len > 0)
			break ;
		i++;
	}
	if (name_len == 0 || name_len == -1)
		return (NULL);
	return (ft_substr(token, i, i + name_len));
}

int	replace_before_name_here(char *new_token, char *token)
{
	int	i;

	i = 0;
	while (token[i] != '$')
	{
		new_token[i] = token[i];
		i++;
	}
	return (i);
}

char	*replace_name_value_here(char *token, char *name, char *value)
{
	char	*new_token;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	new_token = ft_calloc(ft_strlen(token)
			+ (ft_strlen(value) - ft_strlen(name)) + 1);
	i = replace_before_name_here(new_token, token);
	k = i;
	j = 0;
	while (value[j])
	{
		if (value[j] == '$')
			value[j] = -1;
		new_token[i++] = value[j++];
	}
	k += ft_strlen(name);
	while (token[k])
		new_token[i++] = token[k++];
	free(token);
	return (new_token);
}

char	*heredoc_expansion(char *line)
{
	char	*name;
	char	*value;
	char	*new_line;

	name = get_name_here(line);
	if (!name)
	{
		expands_dollars_dollars(line);
		return (line);
	}
	value = get_env_value(name + 1);
	new_line = replace_name_value_here(line, name, value);
	if (*(name + 1) == '?')
		free(value);
	free(name);
	return (heredoc_expansion(new_line));
}
