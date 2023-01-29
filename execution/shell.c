#include "minishell.h"

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
		// hardcode_builtins(cmd->args);
		execute(cmd);
		free(line);
	}
}
