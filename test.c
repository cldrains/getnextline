/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevers <tevers@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 06:38:44 by tevers@stud       #+#    #+#             */
/*   Updated: 2023/02/08 15:29:05 by tevers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int 	fd;
    char	*str;

    fd = open("text.txt", O_RDONLY);
    while ((str = get_next_line(fd)))
    {
        printf("%s",str);
		free(str);
    }
	free(str);
	printf("\n");
    system("leaks a.out");
}
