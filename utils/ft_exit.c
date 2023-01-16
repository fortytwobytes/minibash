#include "../includes/minishell.h"

void ft_exit(int exit_status,char *perror_msg)
{
	if (perror_msg)
		perror(perror_msg);
	exit(exit_status);
}

