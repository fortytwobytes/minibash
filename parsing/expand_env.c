#include "minishell.h"

// this function returns the len of the variable name , exp : $abc => 4 , $ => 1
int get_name_len(char *token, int i)
{
	int name_len;

	if (token[i+1] == 0)
		return 0;
	name_len = 1;
	while(is_env_name(token[i+1]))
	{
		i++;
		name_len++;
	}
	return name_len;
}

// this function returns the first occurence of a variable name
char *get_name(char *token)
{
	int	i;
	int	name_len;

	i = 0;
	name_len = 0;
	while(token[i])
	{
		if (token[i] == '\'')
			i = next_quote(i+1,token[i],token);
		if (token[i] == '$')
			name_len = get_name_len(token,i);
		if (name_len > 0)
			break;
		i++;
	}
	if (name_len == 0)
		return NULL;
	return ft_substr(token,i,i + name_len);
}

// this function remplace the string value in the string name and returns an allocated string
// we add one the len of name bc it doesn't contain the '$' char
// (token[i] != '$' || j == 1) , it means while we are before an unquoted $
char *replace_name_value(char *token, char *name, char *value)
{
	char *new_token;
	int	i;
	int	j;
	int k;

	i = 0;
	j = 0;
	new_token = ft_calloc(ft_strlen(token) + (ft_strlen(value) - ft_strlen(name)) + 1);
	while (token[i] != '$' || j == 1)
	{
		if (token[i] == '\'')
			j = !j;
		new_token[i] = token[i];
		i++;
	}
	k = i;
	j = 0;
	while(value[j])
		new_token[i++] = value[j++];
	k += ft_strlen(name);
	while(token[k])
		new_token[i++] = token[k++];
	free(token);
	return new_token;
}


// this funtion search for variable name and replace it by its value recursivly
char *parameter_expansion(char *token,char *envp[])
{
	char *name;
	char *value;
	char *new_token;

	name = get_name(token);
	if (!name)
		return token;
	value =  get_value(name); // should be get_value(name) later;
	new_token = replace_name_value(token,name,value);
	free(name);
	return parameter_expansion(new_token,envp);
}