#include "get_next_line.h"

char	*ft_strchr(const char *e, int a)
{
	char	*w;

	if (!e)
		return (NULL);
	w = (char *)e;
	while (*w != (char)a)
	{
		if (!*w)
			return (NULL);
		w++;
	}
	return (w);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*str0;


	i = 0;
	n = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	str0 = (char *) malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) +1);
	if (!str0)
		return (NULL);
	while (s1[i])
	{
		str0[i] = s1[i];
		i++;
	}
	while (s2[n])
		str0[i++] = s2[n++];
	str0[i] = '\0';
	free(s1);
	return (str0);
}

size_t	ft_strlen(const char *c)
{
	size_t	l;

	l = 0;
	if (!c)
		return (0);
	while (c[l] != '\0')
		l++;
	return (l);
}

