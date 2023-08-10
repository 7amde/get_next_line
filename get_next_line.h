#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define	BUFFER_SIZE 21
#endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *e, int a);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen(const char *c);

#endif