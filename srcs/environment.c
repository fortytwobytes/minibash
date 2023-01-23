#include "srcs.h"

void    add_env(t_envs **envs, char *env)
{
    t_envs  *new;
    t_envs  *tmp;
    char    **split;

    split = ft_split(env, '=');
    new = ft_calloc(sizeof(t_envs));
    new->name = ft_strdup(split[0]);
    new->value = ft_strdup(split[1]);
    new->next = NULL;
    free_split(split);
    if (!envs || !*envs)
    {
        *envs = new;
        return ;
    }
    tmp = *envs;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void    pop_env(char *name)
{
    t_envs  *tmp;
    t_envs  *prev;

    tmp = global.envs;
    prev = NULL;
    while (tmp)
    {
        if (!ft_strcmp(tmp->name, name))
        {
            if (prev)
                prev->next = tmp->next;
            else
                global.envs = tmp->next;
            free(tmp->name);
            free(tmp->value);
            free(tmp);
            return ;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

t_envs  *envs_init(void)
{
    t_envs  *envs;
    int     i;

    i = 0;
    envs = NULL;
    while (global.env && global.env[i])
    {
        add_env(&envs, global.env[i]);
        i++;
    }
    return (envs);
}

char    *ft_getenv(char *name)
{
    t_envs  *tmp;

    tmp = global.envs;
    if (!tmp)
        return (NULL);
    while (tmp)
    {
        if (!ft_strcmp(tmp->name, name))
            return (tmp->value);
        tmp = tmp->next;
    }
    return (NULL);
}