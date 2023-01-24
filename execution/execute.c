#include "execution.h"

void	close_all_fds(t_cmd *head)
{
	t_cmd	*tmp;

	tmp = head;
	while (tmp)
	{
		// i think we should egnore the error of close
		// to disccuss
		ft_close(tmp->outfile);
		ft_close(tmp->infile);
		tmp = tmp->next;
	}
}

void	exec_single_cmd(t_cmd *head, t_cmd *cmd)
{
	pid_t	pid;

	pid = ft_fork();
	if (pid == 0)
	{
		if (cmd->infile != READ)
			ft_dup2(cmd->infile, READ);
		if (cmd->outfile != WRITE)
			ft_dup2(cmd->outfile, WRITE);
		close_all_fds(head);
	}
	ft_waitpid(pid);
}

void	execute(t_cmd *head)
{
	t_cmd	*tmp;

	while (tmp)
	{
		exec_single_cmd(head, tmp);
		tmp = tmp->next;
	}
	close_all_fds(head);
}
