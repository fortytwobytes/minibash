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
	write(2,"command not found\n",19);
	exit(127);
}

// if fork fails the exit status is 1
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
		if (is_builtins(cmd->cmd))
		{
			hardcode_builtins(cmd->args,1); 
			exit(1111); // ^ should return exit status
		}
		cmd->path = ft_getpath(cmd->cmd);
		if (cmd->path == NULL)
			command_not_found();
		ft_execve(cmd->path, cmd->args);
	}
	return pid;
}

void wait_all_childs(int last_pid)
{
	int		pid;
	int		status;
	int		tmp_pid;

	pid = 0;
	tmp_pid = last_pid;
	if (last_pid == 0)
		return ;
	while (pid != -1)
	{
		pid = wait(&status);
		if (last_pid == pid)
			global.exit_status = WEXITSTATUS(status);
	}
	if (tmp_pid == -1)
		global.exit_status = 1;
}

void	execute(t_cmd *head)
{
	t_cmd	*tmp;
	int		last_pid;

	tmp = head;
	last_pid = 0;
	if (!head)
		return;
	if (is_builtins(head->cmd) && !head->next)
	{
		hardcode_builtins(head->args,head->outfile); // this fucntion should return the exit status of the builtins 
		close_all_fds(head);
		return ;
	}
	while (tmp)
	{
		if (tmp->cmd)
			last_pid = exec_single_cmd(head, tmp);
		if (last_pid == -1)
			break;
		tmp = tmp->next;
	}
	close_all_fds(head);
	wait_all_childs(last_pid);
}
