#include "execution.h"

void	close_all_fds(t_cmd *head)
{
	t_cmd	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->outfile != 0)
			ft_close(tmp->outfile);
		if (tmp->infile != 0)
			ft_close(tmp->infile);
		tmp = tmp->next;
	}
}
void command_not_found()
{
	printf("command not found\n");
	exit(127);
}
int	exec_single_cmd(t_cmd *head, t_cmd *cmd)
{
	pid_t	pid;

	// check if builtin;
	pid = ft_fork();
	if (pid == -1)
		return -1;
	if (pid == 0)
	{
		if (cmd->infile != 0)
			ft_dup2(cmd->infile, 0);
		if (cmd->outfile != 0)
			ft_dup2(cmd->outfile, 1);
		close_all_fds(head);
		cmd->path = ft_getpath(cmd->cmd);
		if (cmd->path == NULL)
			command_not_found();
		ft_execve(cmd->path, cmd->args);
	}
	return pid;
}

void	execute(t_cmd *head)
{
	t_cmd	*tmp;
	int		last_pid;
	int		status;
	int		pid;

	tmp = head;
	last_pid = 0;
	pid = 0;
	while (tmp)
	{
		if (tmp->cmd)
			last_pid = exec_single_cmd(head, tmp);
		if (last_pid == -1)
			break;
		tmp = tmp->next;
	}
	close_all_fds(head);
	if (last_pid == 0)
		return ;
	while (pid != -1)
	{
		pid = wait(&status);
		if (last_pid == pid)
			global.exit_status = WEXITSTATUS(status);
	}
}
