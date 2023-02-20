/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevers <tevers@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:14:35 by tevers            #+#    #+#             */
/*   Updated: 2023/02/13 13:29:31 by tevers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (free(s1), str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		strl;

	strl = ft_strlen(s);
	i = -1;
	if (strl == 0 && *s != 0)
		return (NULL);
	if (*s == 0 && strl != 0)
		return ((char *)s);
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
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

