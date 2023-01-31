#include "minishell.h"

void	shell_loop(void)
{
	char	*line;
	t_cmd	*cmd;

	while (TRUE)
	{
		line = readline(PROMPT);
		if (!line)
			break ;
		add_history(line);
		cmd = parse_line(line);
		execute(cmd);
		free(line);
	}
}
