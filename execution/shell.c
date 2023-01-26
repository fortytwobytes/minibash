#include "minishell.h"


// just for testing


void	shell_loop(void)
{
	char	*line;
	t_cmd	*cmd;

	while (TRUE)
	{
		line = readline(PROMPT);
		if (!line) // or a sigkill, to handle later
			break ;
		add_history(line);
		cmd = parse_line(line); 
		/*
				this function takes the line input and parses it , if there is no syntax error it returns a list of commmands to execute(TO DO)
				else it returns NULL .
			NB:	if NULL is returned syntax error will be printed and the variable $? needs to be set to 258 like bash
				this function also need to take the env variables as argument so it can expand them during the parsing phase.
		*/
		execute(cmd);
		free(line);
	}
}
