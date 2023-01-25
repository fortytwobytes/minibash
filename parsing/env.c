#include "minishell.h"

int is_env_name(char c)
{
	if (is_lower(c) || is_upper(c) || is_num(c) || c == '_')
		return (1);
	return (0);
}
