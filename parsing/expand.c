/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:45:02 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/29 19:45:03 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// this function copies the token string into a new 
// allocated string without copying the -1 occurenccense
char	*trim_quotes(char *token, int quotes_len)
{
	char	*trimed_token;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(token);
	trimed_token = ft_calloc(len - quotes_len + 1);
	i = 0;
	j = 0;
	while (token[i])
	{
		if (token[i] != -1)
		{
			trimed_token[j] = token[i];
			j++;
		}
		i++;
	}
	free(token);
	return (trimed_token);
}

// this function removes the outer quotes of the passed string , 
// by marking the quotes that needs to be removed by -1
// and passing the token string to the trim quotes function
char	*quotes_removal(char *token)
{
	int		i;
	char	c;
	int		quotes_len;

	i = 0;
	quotes_len = 0;
	while (token[i])
	{
		if (token[i] == '"' || token[i] == '\'')
		{
			c = token[i];
			token[i] = -1;
			i = next_quote(i + 1, c, token);
			token[i] = -1;
			quotes_len++;
		}
		i++;
	}
	if (!quotes_len)
		return (token);
	return (trim_quotes(token, quotes_len));
}

// we will loop the linked list and remove empty strings that resulted from 
// an unkown variable expansion .
t_token	*remove_empty_tokens(t_token *tokens)
{
	t_token	*prev;
	t_token	*head;

	prev = NULL;
	head = tokens;
	while (tokens)
	{
		if (*(tokens->token) == 0)
		{
			if (prev == NULL)
			{
				head = tokens->next;
				free(tokens->token);
				free(tokens);
				tokens = head;
			}
			else
			{
				prev->next = tokens->next;
				free(tokens->token);
				free(tokens);
				tokens = prev->next;
			}
		}
		else
		{
			prev = tokens;
			tokens = tokens->next;
		}
	}
	return (head);
}

//in the expansion part we only have to handle paramter expansion ($) and quotes
//removal and we will implement these expansions in the same order of the 
//bash cad variable expansion , word spliting => after word spliting we shall 
// remove
// unquoted  empty strings that did result from a variable expension ,
// then quotes removal
t_token	*expand_tokens(t_token *tokens)
{
	t_token	*token;
	t_token	*head;

	token = tokens;
	while (token)
	{
		if (token->type == WORD)
		{
			token->token = parameter_expansion(token->token);
			token = word_spliting(token);
		}
		token = token->next;
	}
	token = tokens;
	tokens = remove_empty_tokens(token);
	head = tokens;
	while (tokens)
	{
		if (tokens->type == WORD)
			tokens->token = quotes_removal(tokens->token);
		tokens = tokens->next;
	}
	return (head);
}
