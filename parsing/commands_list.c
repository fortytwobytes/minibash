/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:00:55 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 00:02:10 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// free(head->cmd);
// free(head->path);
void	free_cmd(t_cmd *head)
{
	t_cmd	*tmp;

	while (head)
	{
		free_split(head->args);
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
