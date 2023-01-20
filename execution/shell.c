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
		parse_line(line, main->envp); 
		/*
				this function takes the line input and parses it , if there is no syntax error it returns a list of commmands to execute(TO DO)
				else it returns NULL .
			NB:	if NULL is returned syntax error will be printed and the variable $? needs to be set to 258 like bash
				this function also need to take the env variables as argument so it can expand them during the parsing phase.
		*/
		free(line);
	}
	free(line);
}
