#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

void    cd(char **args);
void    pwd(char **args);
void    echo(char **args);
void    env(char **args);
void    unset(char **args);
void    export(char **args);

#endif // BUILITIN_H
