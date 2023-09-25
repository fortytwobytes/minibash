/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:44:24 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/31 23:56:09 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// this function returns the len of the variable name , exp : $abc => 4 , $ => 1
// [A-Z]{1,}[A-Z0-9_]
int	get_name_len(char *token, int i)
{
	int	name_len;

	if (token[i + 1] == '?')
		return (2);
	if (!(is_upper(token[i + 1]) || is_lower(token[i + 1])
			|| token[i + 1] == '_'))
		return (0);
	name_len = 1;
	while (is_env_name(token[i + 1]))
	{
		i++;
		name_len++;
	}
	return (name_len);
}

// this function returns the first occurrence of a variable name 
// if we have an occurrence of a $ alone we just mark it with -1 
// to not interump with further calls to this function
// we will change the -1 latter
char	*get_name(char *token)
{
	int	i;
	int	name_len;
	int	dbl_quote;

	i = 0;
	name_len = -1;
	dbl_quote = -1;
	while (token[i])
	{
		name_len = -1;
		if (token[i] == '"')
			dbl_quote *= -1;
		if (token[i] == '\'' && dbl_quote == -1)
			i = next_quote(i + 1, token[i], token);
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

// we need to check if the variable is not inside double quotes to 
// not expand it , but check if we don't have double quotes before 
int	replace_before_name(char *new_token, char *token)
{
	int	i;
	int	dbl_quotes;
	int	sgl_quotes;

	dbl_quotes = 0;
	sgl_quotes = 0;
	i = 0;
	while (token[i] != '$' || sgl_quotes)
	{
		if (token[i] == '\'' && !dbl_quotes)
			sgl_quotes = !sgl_quotes;
		if (token[i] == '"')
			dbl_quotes = !dbl_quotes;
		new_token[i] = token[i];
		i++;
	}
	return (i);
}

// this function remplace the string value in the string
// name and returns an allocated string
// we add one the len of name bc it doesn't contain the '$' char
// (token[i] != '$' || j == 1) , it means while we are before an unquoted $
char	*replace_name_value(char *token, char *name, char *value)
{
	char	*new_token;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	new_token = ft_calloc(ft_strlen(token)
			+ (ft_strlen(value) - ft_strlen(name)) + 1);
	i = replace_before_name(new_token, token);
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

// this function search for variable name and replace it by its value recursively
char	*parameter_expansion(char *token)
{
	char	*name;
	char	*value;
	char	*new_token;

	name = get_name(token);
	if (!name)
	{
		expands_dollars_dollars(token);
		return (token);
	}
	value = get_env_value(name + 1);
	new_token = replace_name_value(token, name, value);
	if (*(name + 1) == '?')
		free(value);
	free(name);
	return (parameter_expansion(new_token));
}
