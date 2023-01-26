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

// a function that return the position of the next quote char
int next_quote(int i, char quote, char *line)
{
	while (line[i])
	{
		if (line[i] == quote)
			return (i);
		i++;
	}
	return (-1);
}

// a function that returns the number of words splited by blank 
// or -1 if the quotes are umatching
int word_count(char *line)
{
	int count;
	int i;
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
			if (i == -1)
				return -1;
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

static char *get_next_word(char *s, int *index)
{
	int i;
	int j;
	int k;
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
// a function that split a string by blank and returns the result in a 2d array 
// or -1 if the quotes are umatching
char **split_by_blank(char *line)
{
	char **res;
	int wc;
	int i;
	int j;

	wc = word_count(line);
	if (wc == -1)
		return (NULL);
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
// in first we split the words by blank characters and remove them , then we separate the words from the operators 
// and create token ,then we parse the semantics of the tokens created
t_cmd *parse_line(char *line)
{
	char	**words;
	t_token *tokens;
	t_cmd	*cmds;

	words = split_by_blank(line);
	if (words == NULL)
	{
		ft_putstr_fd("$> : syntax errorrr\n",2);
		return NULL;
	}
	tokens = split_by_operator(words);
	free_split(words);
	if (!parse(tokens))
	{
		ft_putstr_fd("$> : syntax error\n",2);
		return NULL;
	}
	tokenise_heredoc(tokens);
	tokens = expand_tokens(tokens);
	cmds = convert_to_cmds(tokens);
	// print_cmd(cmds);
	free_tokens(tokens);
	return cmds;
}
