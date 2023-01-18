/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:58:50 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/17 11:58:51 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t next_quote(size_t i, char quote, char *line)
{
	while (line[i])
	{
		if (line[i] == quote)
			return i;
		i++;
	}
	ft_exit(EXIT_FAILURE, "syntax error");
	return -1;
}

size_t word_count(char *line)
{
	size_t count;
	size_t i;
	int flag;

	flag = 1;
	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
		{
			if (line[i] == '"' || line[i] == '\'')
				i = next_quote(i + 1, line[i], line);
			if (flag != 0)
				count++;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	return count;
}

char *get_next_word(char *s, size_t *index)
{
	size_t i;
	size_t j;
	size_t k;
	char *word;

	k = 0;
	i = *index;
	while ((s[i] == ' ' || s[i] == '\t') && s[i])
		i++;
	j = i;
	while (!(s[i] == ' ' || s[i] == '\t') && s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
			i = next_quote(i + 1, s[i], s);
		i++;
	}
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

char **split_by_blank(char *line)
{
	char **res;
	size_t wc;
	size_t i;
	size_t j;

	wc = word_count(line);
	res = ft_calloc((wc + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < wc)
	{
		res[i] = get_next_word(line, &j);
		i++;
	}
	return res;
}

void parse_line(char *line)
{
	char **words;

	words = split_by_blank(line);
	// words = split_by_metachar(words); // to do
}
