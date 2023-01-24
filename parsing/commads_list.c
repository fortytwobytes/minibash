#include "minishell.h"


void print_cmd(t_cmd *cmd)
{
	int i =0 ;
	while (cmd)
	{
		printf("name :%s\n",cmd->cmd);
		printf("options:\n");
		while (cmd->args[i])
		{
			printf("%s\n",cmd->args[i]);
			i++;
		}
		printf("outf : %d , inf : %d\n",cmd->infile,cmd->outfile);
		cmd = cmd->next;
	}
	
}
