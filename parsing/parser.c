#include "minishell.h"

void check_invalid_operator(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == OPERATOR)
			ft_exit(EXIT_SYNTAX,"syntax error");
		tokens = tokens->next;
	}
}

void check_redirections(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == REDIRECTION)
		{
			if (tokens->next)
			{
				if ((tokens->next)->type != WORD)
					ft_exit(EXIT_SYNTAX,"syntax error");
			}
			else
				ft_exit(EXIT_SYNTAX,"syntax error");
		}
		tokens = tokens->next;
	}
	
}

int word_after(t_token *tokens)
{
	tokens = tokens->next;
	while(tokens && tokens->type != PIPE)
	{
		if (tokens->type == WORD)
			return 1;
		tokens = tokens->next;
	}
	return (0);
}

void check_pipes(t_token *tokens)
{
	int word_before;

	word_before = 0; 
	while (tokens)
	{
		if (tokens->type == WORD)
			word_before = 1;
		if (tokens->type == PIPE)
		{
			if (!word_before || !word_after(tokens))
				ft_exit(EXIT_SYNTAX,"syntax error");
			word_before = 0;
		}
		tokens = tokens->next;
	}
}

void	parse(t_token *tokens)
{
	check_invalid_operator(tokens);
	check_redirections(tokens);
	check_pipes(tokens);
}
