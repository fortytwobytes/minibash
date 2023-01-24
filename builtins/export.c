#include "builtin.h"

// here i would expect args as follows:
// args = {"export", "a=10", "b=30", ..., NULL};

void export(char **args, int fd)
{
	char	*name;
	char	*value;
	char	**sp;

	if (*(args + 1) == NULL)
		return;
	args++;
	while (*args)
	{
		sp = ft_split(*args, '=');
		name = sp[0];
		value = sp[1];
		if (is_updated(name, value) == FALSE)
			add_env(&global.envs, name, value);
		free_split(sp);
		args++;
	}
	ft_putchar_fd(0, fd);
}
