#include "minishell.h"

void print_list(t_token *head)
{
	while(head)
	{
		printf("%s\n",head->token);
		head = head ->next;
	}
}
// in this function we chose the type of passed string 
// the possible strings are sequences of operators or  noraml chars
// if the sequence of operators is not to be handle by our minishell we name it by the token OPERATOR wich should syntax error
// else the token are allowed 
int choose_token_type(char *s)
{
	size_t i;

	i =0;
	if (!ft_strcmp(s,"|"))
		return (PIPE);
	if (!ft_strcmp(s,"<<"))
		return (HEREDOC);
	if (!ft_strcmp(s,">>"))
		return (REDIRECTION);
	if (!ft_strcmp(s,"<") || !ft_strcmp(s,">"))
		return (REDIRECTION);
	if (is_operator(s[i]))
		return (OPERATOR);
	else
		return (WORD);
}

t_token *create_node(char *s)
{
	t_token *p;
	p = ft_calloc(sizeof(t_token));
	p->token = s;
	p->type = choose_token_type(s);
	return p;
}

void add_back(t_token **head,char *s)
{
	t_token *p;
	t_token *i;

	i = *head;
	p = create_node(s);
	if (i == NULL)
	{
		*head = p;
		return ;
	}
	while(i->next)
		i = i->next;
	i->next = p;
}

void add_middle(t_token *token,char *word)
{
	t_token *p;

	p = create_node(word);
	p->type = WORD;
	p->next = token->next;
	token->next = p;
}

// this function checks for heredoc and set the word next to it to a limiter
void tokenise_heredoc(t_token *token)
{
	while (token)
	{
		if (token->type == HEREDOC)
			(token->next)->type = LIMITER;
		token = token->next;
	}
	
}

void free_tokens(t_token *tokens)
{	
	t_token *prev;

	while(tokens)
	{
		prev = tokens;
		tokens = tokens->next;
		free(prev);
	}
}