/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmalman <ahmalman@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:21:56 by ahmalman          #+#    #+#             */
/*   Updated: 2023/08/10 18:33:45 by ahmalman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(int fd, char *lineextra, int buffsize, int i)
{
	char	*textsave;

	textsave = (char *) malloc (sizeof(char) * buffsize + 1);
	if (!textsave)
		return (NULL);
	while (i == 1 && !ft_strchr(lineextra, '\n'))
	{
		i = read(fd, textsave, buffsize);
		if (i == -1)
		{
			free (textsave);
			return (NULL);
		}
		textsave[i] = '\0';
		lineextra = ft_strjoin_gnl(lineextra, textsave);
		if (i)
			i = 1;
	}
	free(textsave);
	if (lineextra[0] == '\0')
	{
		free(lineextra);
		return (NULL);
	}
	return (lineextra);
}

static char	*copy(char *srt1)
{
	int		i;
	char	*res;

	i = 0;
	if (!srt1)
		return (NULL);
	while (srt1[i] != '\n' && srt1[i] != '\0')
		i++;
	res = (char *) malloc (sizeof (char) * i +2);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (srt1[i] != '\n' && srt1[i] != '\0')
	{
		res[i] = srt1[i];
		i++;
	}
	if (srt1[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*lastline(char *srt2, int i, int c)
{
	char	*lsat;

	if (!srt2)
		return (NULL);
	while (srt2[i] != '\n' && srt2[i] != '\0')
		i++;
	if (srt2[i] == '\0')
	{
		free(srt2);
		return (NULL);
	}
	i++;
	c = i;
	while (srt2[i])
		i++;
	i = i - c;
	lsat = (char *) malloc (sizeof (char) * i + 1);
	if (lsat == NULL)
		return (NULL);
	i = 0;
	while (srt2[c] != '\0')
		lsat[i++] = srt2[c++];
	lsat[i] = '\0';
	free(srt2);
	return (lsat);
}

char	*get_next_line(int fd)
{
	static char	*lineextra;
	char		*srt;

	if (fd < 0)
		return (NULL);
	lineextra = reader(fd, lineextra, BUFFER_SIZE, 1);
	if (lineextra == NULL)
		return (NULL);
	srt = copy(lineextra);
	lineextra = lastline(lineextra, 0, 0);
	return (srt);
}

// int main ()
// {
	// char *annar;

	// int fd = open("input.txt", O_RDWR);
	// annar = get_next_line(fd);
	// printf ("%s",annar);
	// annar = get_next_line(fd);
	// printf ("%s",annar);
	// while (annar)
	// {
	// 	annar = get_next_line(fd);
	// 	printf ("%s",annar);
	// }
	// 
// 
	// char *buff;

	// buff = malloc(BUFFER_SIZE + 1);

	// read(fd, buff, BUFFER_SIZE);
	// printf("%s\n", buff);

// 	int i;

// 	i = i + 1;
// 	printf("%d\n", i);
// 	return (0);
// }