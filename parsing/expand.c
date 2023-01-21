#include "minishell.h"

// this function copies the token string into a new allocated string without copying the -1 occurenccense
char *trim_quotes(char *token, int quotes_len)
{
	int len;
	char *trimed_token;
	int i;
	int j;

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
// this function removes the outer quotes of the passed string , by marking the quotes that needs to be removed by -1
// and passing the token string to the trim quotes function
char *quotes_removal(char *token)
{
	int i;
	char c;
	int quotes_len;

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
		return token;
	return trim_quotes(token, quotes_len);
}
// // this function return the value of a variable given its name
// char *get_paramter_value(char *name)
// {

// }
// // this function performs the neccessary parameter expansions
// char *parameter_expansion(char *token,char *envp[])
// {

// }
// in the expansion part we only have to handle paramter expansion ($) and quotes removal .
// and we will implement these expansions in the same order of the bash cad variable expansion then quotes removal
void expand_tokens(t_token *tokens, char *envp[])
{
	while (tokens)
	{
		if (tokens->type == WORD)
		{
			// tokens->token = parameter_expansion(tokens->token,envp);
			tokens->token = quotes_removal(tokens->token);
		}
		tokens = tokens->next;
	}
}
