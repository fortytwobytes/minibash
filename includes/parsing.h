#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

#define EXIT_SYNTAX 258

typedef struct s_token{
	char *token;
	int type;
	struct s_token *next;
}t_token;

typedef struct s_cmd {
	char	*cmd;
	char	**args;
	char	*path;
	int		infile;
	int		outfile;
	struct s_cmd *next;
}t_cmd;

// void	parse(t_main *main, char *line);
int		parse(t_token *tokens);
void	parse_line(char *line, char **envp);
t_token *split_by_operator(char **words);
int next_quote(int i, char quote, char *line);

void	add_back(t_token **head,char *s);
void	print_list(t_token *head);
int		is_operator(char c);

#define OPERATOR -1
#define PIPE 0
#define REDIRECTION 1
#define WORD 2
#endif // PARSING_H
