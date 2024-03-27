/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:33:38 by relkabou          #+#    #+#             */
/*   Updated: 2023/01/31 23:33:39 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	ft_waitpid(pid_t pid)
{
	int	status;

	if (waitpid(pid, &status, 0) == -1)
		ft_exit(WEXITSTATUS(status), strerror(errno));
}

void	ft_wait(int *status)
{
	if (wait(status) == -1)
		ft_exit(errno, strerror(errno));
}

void	ft_wait3(int *status, int options, struct rusage *rusage)
{
	if (wait3(status, options, rusage) == -1)
		ft_exit(errno, strerror(errno));
}

void	ft_wait4(pid_t pid, int *status, int options, struct rusage *rusage)
{
	if (wait4(pid, status, options, rusage) == -1)
		ft_exit(errno, strerror(errno));
}
