#include "minishell.h"


void print_cmd(t_cmd *cmd)
{
	while (cmd)
	{
	int i =0 ;
		printf("name :%s\n",cmd->cmd);
		printf("options:\n");
		while (cmd->args[i])
		{
			printf("%s\n",cmd->args[i]);
			i++;
		}
		printf("inf : %d , outf : %d\n",cmd->infile,cmd->outfile);
		cmd = cmd->next;
	}
	
}
