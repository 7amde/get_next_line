/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmalman <ahmalman@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:21:56 by ahmalman          #+#    #+#             */
/*   Updated: 2023/08/16 20:58:21 by ahmalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(int fd, char *buffer, int i)
{
	char	*textsave;

	textsave = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!textsave)
		return (NULL);
	while (i == 1 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, textsave, BUFFER_SIZE);
		if (i == -1)
		{
			free (buffer);
			free (textsave);
			return (NULL);
		}
		textsave[i] = '\0';
		buffer = ft_strjoin_gnl(buffer, textsave);
		if (i)
			i = 1;
	}
	free(textsave);
	if (buffer[0] == '\0')
		return (free(buffer), NULL);
	return (buffer);
}

static char	*spliter(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	res = (char *) malloc (sizeof (char) * i +2);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*lastline(char *str, int i, int c)
{
	char	*last;

	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i++;
	c = i;
	while (str[i])
		i++;
	i = i - c;
	last = (char *) malloc (sizeof (char) * i + 1);
	if (last == NULL)
		return (NULL);
	i = 0;
	while (str[c] != '\0')
		last[i++] = str[c++];
	last[i] = '\0';
	free(str);
	return (last);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	buffer = reader(fd, buffer, 1);
	if (buffer == NULL)
		return (NULL);
	str = spliter(buffer);
	buffer = lastline(buffer, 0, 0);
	return (str);
}

// int	main()
// {
// 	char *annar;

// 	int fd = open("bible.txt", O_RDWR);
// 	annar = get_next_line(fd);
// 	printf ("%s",annar);
// 	annar = get_next_line(fd);
// 	printf ("%s",annar);
// 	while (annar)
// 	{
// 		annar = get_next_line(62);
// 			annar = get_next_line(64);
// 		annar = get_next_line(fd);
// 		printf ("%s",annar);
// 	}
//  	return (0);
// }