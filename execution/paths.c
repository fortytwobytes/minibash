#include "execution.h"

char	*ft_getpath(char *cmd)
{
	int		i;
	char	*tmp;
	char	*paths;
	char	**sp_paths;

	i = -1;
	if (is_char_in_str(cmd, '/'))
		return (ft_strdup(cmd));
	paths = ft_getenv("PATH");
	if (!paths)
	{
		tmp = ft_strjoin("/bin/", cmd);
		if (access(tmp, X_OK) == -1)
			return (free(tmp), NULL);
		return (tmp);
	}
	sp_paths = ft_split(paths, ':');
	while (sp_paths[++i])
	{
		tmp = ft_strjoin_sep(sp_paths[i], cmd, '/');
		if (access(tmp, X_OK) == -1)
			free(tmp);
		else
			return (free_split(sp_paths), tmp);
	}
	return NULL;
}

int	is_char_in_str(char *str, char c)
{
	while (str && *str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
