#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

void    cd(char **args, int fd);
void    pwd(char **args, int fd);
void    echo(char **args, int fd);
void    env(char **args, int fd);
void    unset(char **args, int fd);
void    export(char **args, int fd);

#endif // BUILITIN_H
