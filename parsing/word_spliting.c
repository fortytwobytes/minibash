/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_spliting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:45:14 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/29 19:45:16 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minibash.h"

void	init_values(int *flag, int *i, int *count, int *q)
{
	*flag = 1;
	*i = 0;
	*count = 0;
	*q = -1;
}

int	word_split_count(char *line)
{
	int	count;
	int	i;
	int	q;
	int	flag;

	init_values(&flag, &i, &count, &flag);
	while (line[i])
	{
		q = -1;
		if (line[i] != ' ' && line[i] != '\t')
		{
			if (line[i] == '"' || line[i] == '\'')
				q = next_quote(i + 1, line[i], line);
			if (q != -1)
				i = q;
			if (flag != 0)
				count++;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	return (count);
}

static char	*get_next_word(char *s, int *index)
{
	int		i;
	int		j;
	int		k;
	char	*word;

	k = 0;
	i = *index;
	while ((s[i] == ' ' || s[i] == '\t') && s[i])
		i++;
	j = i;
	while (!(s[i] == ' ' || s[i] == '\t') && s[i])
		i++;
	word = ft_calloc(i - j + 1);
	while (j < i)
	{
		word[k] = s[j];
		k++;
		j++;
	}
	*index = i;
	return (word);
}

char	**my_split(char *line, int wc)
{
	char	**res;
	int		i;
	int		j;

	res = ft_calloc((wc + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < wc)
	{
		res[i] = get_next_word(line, &j);
		i++;
	}
	return (res);
}

// if wc == 0 that means that we need to remove this token ,
//  we will do it in a separate function 
// if wc == 1 means that no splitting is required 
// if wc > 1 means that the variable expansion caused a blank separator 
// in the middle of the token 
// so we need to split it into two words
t_token	*word_spliting(t_token *token)
{
	char	**words;
	int		wc;
	int		i;

	wc = word_split_count(token->token);
	if (wc == 1 || wc == 0)
		return (token);
	words = my_split(token->token, wc);
	free(token->token);
	token->token = words[0];
	i = 1;
	while (words[i])
	{
		add_middle(token, words[i]);
		token = token->next;
		i++;
	}
	free(words);
	return (token);
}
