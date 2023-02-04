/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:38:41 by mtagemou          #+#    #+#             */
/*   Updated: 2023/02/04 02:31:47 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// rl_on_new_line  : tells that we moved to a nl
// rl_replace_line : replace the content of the rl buffer 
// rl_redisplay    : change what is on the screen with
//  the actual content of the buffer
void	handle_parent_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	g_global.exit_status = 1;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_signals(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = &handle_parent_sigint;
	sa_sigquit.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

void	default_signals(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = SIG_DFL;
	sa_sigquit.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

void set_exit_status(int sig)
{
    (void)sig;
    ft_putchar_fd('\n', 1);
}

void	ignore_signals(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_handler = &set_exit_status;
	sa_sigquit.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

void	sigint_heredoc(void)
{
	struct sigaction	sa_sigint;

	sa_sigint.sa_handler = &change_flag;
	sigaction(SIGINT, &sa_sigint, NULL);
}
