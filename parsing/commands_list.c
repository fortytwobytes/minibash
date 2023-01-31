#include "minishell.h"

void free_cmd(t_cmd *head)
{
	t_cmd *tmp;

	while (head)
	{
		// free(head->cmd);
		// free(head->path);
		free_split(head->args);
		tmp = head->next; 
		free(head);
		head = tmp;
	}
}