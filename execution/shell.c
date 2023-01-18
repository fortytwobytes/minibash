#include "minishell.h"

void	shell_loop(t_main *main)
{
	char	*line;

	while (TRUE)
	{
		line = readline(PROMPT);
		if (!line || !ft_strcmp(line, "exit"))
			/*
				TODO: 	add a function that frees the memory,
						clears history, etc.
			*/
			break ;
		add_history(line);
		parse(main, line);
		free(line);
	}
	free(line);
}
