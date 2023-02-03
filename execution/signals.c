/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:38:41 by mtagemou          #+#    #+#             */
/*   Updated: 2023/02/01 12:38:43 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// rl_on_new_line  : tells that we moved to a nl
// rl_replace_line : replace the content of the rl buffer 
// rl_redisplay    : change what is on the screen with the actual content of the buffer
void handle_parent_SIGINT(int sig)
{
	(void)sig;
	write(1,"\n",1);
	rl_on_new_line();
	rl_replace_line("",0);
	rl_redisplay();
}

void handle_signals()
{
	struct sigaction sa_SIGINT;
	struct sigaction sa_SIGQUIT;

	sa_SIGINT.sa_handler = &handle_parent_SIGINT;
	sa_SIGQUIT.sa_handler = SIG_IGN;
	sigaction(SIGINT,&sa_SIGINT,NULL);
	sigaction(SIGQUIT,&sa_SIGQUIT,NULL);
}

void default_signals()
{
	struct sigaction sa_SIGINT;
	struct sigaction sa_SIGQUIT;

	sa_SIGINT.sa_handler = SIG_DFL; 
	sa_SIGQUIT.sa_handler = SIG_DFL;
	sigaction(SIGINT,&sa_SIGINT,NULL);
	sigaction(SIGQUIT,&sa_SIGQUIT,NULL);
}

void ignore_signals()
{
	struct sigaction sa_SIGINT;
	struct sigaction sa_SIGQUIT;

	sa_SIGINT.sa_handler = SIG_IGN; 
	sa_SIGQUIT.sa_handler = SIG_IGN;
	sigaction(SIGINT,&sa_SIGINT,NULL);
	sigaction(SIGQUIT,&sa_SIGQUIT,NULL);
} 

void sigint_heredoc()
{
	struct sigaction sa_SIGINT;

	sa_SIGINT.sa_handler = &change_flag;
	sigaction(SIGINT,&sa_SIGINT,NULL);
}