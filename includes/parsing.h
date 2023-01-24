#ifndef PARSING_H
#define PARSING_H

#include "minishell.h"

#define EXIT_SYNTAX 258

#define OPERATOR -1
#define PIPE 0
#define REDIRECTION 1
#define WORD 2
#define HEREDOC 3
#define LIMITER 4
#define FILE 5

#define READ_END 0
#define WRITE_END 1

typedef struct s_token
{
	char *token;
	int type;
	int pipe[2];
	struct s_token *next;
} t_token;

typedef struct s_cmd
{
	char *cmd;
	char **args;
	char *path;
	int infile;
	int outfile;
	struct s_cmd *next;
} t_cmd;

// void	parse(t_main *main, char *line);
int parse(t_token *tokens);
void parse_line(char *line, char **envp);
t_token *split_by_operator(char **words);
int next_quote(int i, char quote, char *line);
t_token *expand_tokens(t_token *tokens, char *envp[]);
int is_env_name(char c);
t_cmd *convert_to_cmds(t_token *tokens);
char *parameter_expansion(char *token, char *envp[]);
char *get_value(char *s);

void add_back(t_token **head, char *s);
void add_middle(t_token *token, char *word);
void print_list(t_token *head);
void check_heredoc(t_token *token);
int is_operator(char c);
t_token *word_spliting(t_token *token);

void print_cmd(t_cmd *cmd);
#endif // PARSING_H
