#include "minishell.h"

int	is_operator(char c)
{
	if (c == '&' || c == ';' || c == '(')
		return (1);
	if (c == ')' || c == '>' || c == '<')
		return (1);
	if (c == '|')
		return (1);
	return (0);
}

// echo, "hello      there", how, are, 'you 'doing?, pixel, |wc, -l, >outfile, NULL
int	position_of_operator(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] =='\'')
			i = next_quote(i+1, s[i], s);
		if (is_operator(s[i]))
			return (i);
		i++;
	}
	return (-1);
}

// this function get the next word either string or sequence of operator
// we have three case :
// 1 - "simple word" => a word without operator we just duplicate it
// 2 - |||"simple wolrd" => operators in the beguining so we group them in a single word
// 3 - "simple world" | "s iadhf" => opeartor in the middle so we substr until the operator
char	*get_word(char *s, size_t *index)
{
	size_t	i;
	int		pos;
	size_t	len;

	i = *index;
	pos = position_of_operator(&s[i]);
	len = 0;
	if (pos == -1) 
	{
		len = ft_strlen(&s[i]);
		*index += len;
		return ft_substr(&s[i], 0, len);
	}
	if (pos == 0)
	{
		while(is_operator(s[i + len]))
			len++;
		*index += len;
		return ft_substr(&s[i], 0, len);
	}
	*index += pos ;
	return ft_substr(&s[i], 0, pos);
}
// wc||||||ls
// wc => ||||| => ls
t_token *split_by_operator(char **words)
{
	t_token	*tokens;
	size_t	i;
	size_t	j;
	char	*token;

	i = 0;
	tokens = NULL;
	while (words[i])
	{
		j = 0;
		while (words[i][j])
		{
			token = get_word(words[i], &j);
			add_back(&tokens, token);
		}
		i++;
	}
	return (tokens);
}
