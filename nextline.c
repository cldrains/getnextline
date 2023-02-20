/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nextline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevers <tevers@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 06:38:44 by tevers@stud       #+#    #+#             */
/*   Updated: 2023/02/13 13:10:31 by tevers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>

void	*ft_memset(void *mem, int n, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)mem;
	while (len-- > 0)
		*tmp++ = (unsigned char)n;
	return (mem);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*memory;

	if (size && num > (SIZE_MAX / size))
		return (NULL);
	memory = malloc(num * size);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, num * size);
	return (memory);
}

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

char	*ft_strcdup(char *s1, char c, size_t start)
{
	char	*s2;
	size_t	tmp;
	int		i;

	tmp = start;
	if (s1 == NULL)
		return (NULL);
	while (s1[start] != c)
		start++;
	if (s1[start] == '\0')
		start--;
	s2 = ft_calloc(start - tmp + 1);
	if (s2 == NULL)
		return (NULL);
	i = start - tmp;
	while (start + 1 != tmp)
	{
		s2[i] = s1[start];
		start--;
		i--;
	}
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}

static char	*ft_delall(char **a)
{
	free(*a);
	*a = NULL;
	return (NULL);
}

static char	*ft_append(char *start, char *end)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	tmp = malloc(ft_strclen(start, '\0') + ft_strclen(end, '\0') + 1);
	if (tmp == NULL)
		return (NULL);
	i = -1;
	while (start[++i] != '\0')
		tmp[i] = start[i];
	j = -1;
	while (end[++j] != '\0')
		tmp[i++] = end[j];
	tmp[i] = '\0';
	free(start);
	return (tmp);
}

static void	ft_reading(char **rest, int fd)
{
	char	*buffer;
	int		val;

	buffer = ft_calloc(BUFFER_SIZE + 1);
	val = read(fd, buffer, BUFFER_SIZE);
	while (val > 0)
	{
		buffer[val] = '\0';
		if (*rest == NULL)
			*rest = ft_strcdup(buffer, '\0', 0);
		else
			*rest = ft_append(*rest, buffer);
		if (ft_strchr(*rest, '\n') != NULL)
			break ;
		val = read(fd, buffer, BUFFER_SIZE);
	}
	if (val < 0)
		ft_delall(rest);
	ft_delall(&buffer);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*temp;
	char		*ret;

	if (fd < 0)
		return (NULL);
	ft_reading(&rest, fd);
	if (rest == NULL || rest[0] == '\0')
		return (NULL);
	else if (ft_strchr(rest, '\n') != NULL)
	{
		ret = ft_strcdup(rest, '\n', 0);
		temp = ft_strcdup(rest, '\0', ft_strclen(rest, '\n') + 1);
		free(rest);
		rest = temp;
		if (rest[0] == '\0')
			ft_delall(&rest);
	}
	else
	{
		ret = ft_strcdup(rest, '\0', 0);
		ft_delall(&rest);
	}
	return (ret);
}

#include <stdio.h>
#include <fcntl.h>
int main()
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
