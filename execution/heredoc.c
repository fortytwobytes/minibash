#include "execution.h"

static char	*get_id(char *name);

char	*here_doc_name(void)
{
	char	*name;
	char	*tty_name;
	char	*id;
	char	*tmp;

	tty_name = ttyname(0);
	id = get_id(tty_name);
	tmp = id;
	name = ft_strjoin("/tmp/.heredoc_", id);
	free(id);
	return (name);
}

static char	*get_id(char *name)
{
	char	*id;

	if (!name)
		return (NULL);
	while (*name && !is_num(*name))
		name++;
	id = name;
	return (ft_strdup(id));
}
