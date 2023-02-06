/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:58:34 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/29 19:58:35 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

# define EXIT_SYNTAX 258

# define OPERATOR -1
# define PIPE 0
# define REDIRECTION 1
# define WORD 2
# define HEREDOC 3
# define LIMITER 4
# define FILE 5

# define READ_END 0
# define WRITE_END 1

typedef struct s_token
{
	char			*token;
	int				type;
	int				pipe[2];
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	char			*path;
	int				infile;
	int				outfile;
	struct s_cmd	*next;
}	t_cmd;

int		parse(t_token *tokens);
t_cmd	*parse_line(char *line);
t_token	*split_by_operator(char **words);
int		next_quote(int i, char quote, char *line);
t_token	*expand_tokens(t_token *tokens);
int		is_env_name(char c);
t_cmd	*convert_to_cmds(t_token *tokens);
char	*parameter_expansion(char *token);
char	*get_value(char *s);
char	*quotes_removal(char *token);
void	add_back(t_token **head, char *s);
void	add_middle(t_token *token, char *word);
void	print_list(t_token *head);
void	free_tokens(t_token *tokens);
void	tokenise_heredoc(t_token *token);
int		is_operator(char c);
t_token	*word_spliting(t_token *token);
void	free_cmd(t_cmd *head);
void	close_fds(t_cmd *cmd);
t_token	*add_cmd(t_cmd **cmds, t_token *tokens);
int		handle_heredoc(t_cmd *cmd, char *limiter, char *file);
t_token	*next_pipe(t_token *tokens);
t_token	*next_pipe(t_token *tokens);
void	handle_pipes(t_cmd *cmd, t_token *tokens);
int		handle_redirection(t_cmd *cmd, t_token *tokens);
void	handle_cmd(t_cmd *cmd, t_token *tokens);
char	*get_next_line(int fd);
t_token	*next_pipe(t_token *tokens);
void	open_pipes(t_token	*tokens);
void	expands_dollars_dollars(char *token);
void	free_token_word(t_token *token, char *word);
void	check_and_redirect(int *inf_out, int fd);
void	free_all(t_token *tokens);
int		handle_heredocs(t_cmd *cmd, t_token *tokens);
int		get_name_len(char *token, int i);
char	*heredoc_expansion(char *line);

#endif // PARSING_H
