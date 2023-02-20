/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevers <tevers@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:14:38 by tevers            #+#    #+#             */
/*   Updated: 2023/02/20 20:25:46 by tevers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *buf)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		++i;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	res = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	if (!res)
		return (NULL);

	j = 0;
	while (buf[++i] != '\0')
		res[j++] = buf[i];
	free(buf);
	return (res);
}

char	*ft_line(char *buf)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		++i;
	res = ft_calloc(i + 2, sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (buf[++i] && buf[i] != '\n')
		res[i] = buf[i];
	if (buf[i] == '\n')
		res[i] = '\n';
	buf = res;
	return (buf);
}

char	*ft_read(int fd, char *buf)
{
	char	*str;
	int		readable;

	if (!buf)
		buf = ft_calloc(1, 1);
	if (!buf)
		return (NULL);
	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readable = 1;
	while (readable >= 1)
	{
		ft_memset(str, 0, BUFFER_SIZE + 1);
		readable = read(fd, str, BUFFER_SIZE);
		if (readable == -1)
			return (free(buf), free(str), NULL);
		buf = ft_strjoin(buf, str);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (free(str), buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_line(buf);
	buf = ft_next(buf);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
    int 	fd;
    char	*str;

    fd = open("abc.txt",O_RDONLY);
    while ((str = get_next_line(fd)))
    {
        printf("%s",str);
		free(str);
    }
	free(str);
	printf("\n");
    system("leaks a.out");
}
