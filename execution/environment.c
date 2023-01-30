#include "execution.h"

void	add_env(t_envs **envs, char *name, char *value)
{
	t_envs	*new;
	t_envs	*tmp;

	new = ft_calloc(sizeof(t_envs));
	new->name = ft_strdup(name);
	if (value == NULL)
		new->value = NULL;
	else
		new->value = ft_strdup(value);
	new->index = 0;
	new->next = NULL;
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

void	pop_env(char *name)
{
	t_envs	*tmp;
	t_envs	*prev;

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

t_envs	*envs_init(void)
{
	int		i;
	char	*name;
	char	*value;
	char	**sp;
	t_envs	*envs;

	i = 0;
	envs = NULL;
	while (global.env && global.env[i])
	{
		sp = ft_split(global.env[i], '=');
		name = sp[0];
		value = sp[1];
		add_env(&envs, name, value);
		free_split(sp);
		i++;
	}
	return (envs);
}

char	*ft_getenv(char *name)
{
	t_envs	*tmp;

	tmp = global.envs;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*get_env_value(char *name)
{
	t_envs	*tmp;

	tmp = global.envs;
	if (*name == '?')
		return (ft_itoa(global.exit_status));
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp->value);
		tmp = tmp->next;
	}
	return ("");
}

int	is_updated(char *name, char *value, int option)
{
	t_envs	*tmp;
	char	*holder;

	tmp = global.envs;
	if (value == NULL)
		return (FALSE);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			holder = tmp->value;
			if (option == ADD)
				tmp->value = ft_strdup(value);
			else if (option == APPEND)
				tmp->value = ft_strjoin(holder, value);
			free(holder);
			return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}

char	**dynamic_env(void)
{
	int		i;
	int		j;
	char	**env;
	t_envs	*tmp;

	i = 0;
	tmp = global.envs;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	env = ft_calloc(sizeof(char *) * (i + 1));
	j = 0;
	tmp = global.envs;
	while (j < i)
	{
		if (tmp->value == NULL)
			tmp->value = "";
		env[j] = ft_strjoin_sep(tmp->name, tmp->value, '=');
		tmp = tmp->next;
		j++;
	}
	return (env);
}

void	ft_setenv(char *name, char *value)
{
	t_envs	*tmp;

	tmp = global.envs;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			free(tmp->value);
			tmp->value = value;
			return ;
		}
		tmp = tmp->next;
	}
}
