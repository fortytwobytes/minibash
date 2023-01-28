#include "utils.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	i = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	buffer = ft_calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[++i])
		buffer[i] = s1[i];
	j = i;
	i = -1;
	while (s2[++i])
		buffer[j++] = s2[i];
	return (buffer);
}

char	*ft_strjoin_sep(char *s1, char *s2, char sep)
{
	int		i;
	int		j;
	char	*buffer;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	buffer = ft_calloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	while (s1[++i])
		buffer[i] = s1[i];
	buffer[i] = sep;
	j = i + 1;
	i = -1;
	while (s2[++i])
		buffer[j++] = s2[i];
	return (buffer);
}
