#include "execution.h"

void	close_all_fds(t_cmd *head)
{
	t_cmd	*tmp;

	tmp = head;
	while (tmp)
	{
		// i think we should ignore the error of close
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
		ft_execve(cmd->path, cmd->args, global.envs); // we should convert the linked list to array
		// so that some apps like ls can work
		// eventhought tha path is unset
	}
	ft_waitpid(pid); // also i didn't close all process here, todo later
	// we will catch the return value of each process
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
