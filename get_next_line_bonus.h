/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevers <tevers@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 04:11:15 by tevers            #+#    #+#             */
/*   Updated: 2023/02/23 04:22:40 by tevers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

# include <unistd.h>
# include <stdlib.h>

// Returns the length of "str"
size_t	ft_strlen(const char *str);
//// Sets "n" bytes from "mem" to "c"
void	*ft_memset(void *mem, int n, size_t len);
// Allocates memory for "num" items with "size", initialises to 0
void	*ft_calloc(size_t num, size_t size);
// Reads and saves until newline is found or no byte is read
// Connects with previous leftovers from buf
char	*ft_readsave(int fd, char *left_str);
// Returns the occurence of "c" in "str"
char	*ft_strchr(const char *s, int c);
// Returns a freeable string which is the concatination of str1 and str2
char	*ft_strjoin(char *s1, char *s2);
// Reads a line in a given file and returns the line. 
// Every call of the function returns a new line, if it exists.
char	*get_next_line(int fd);
// Takes the full joined string and splits it at newline (if it exists),
char	*ft_line(char *buf);
// returns everything after the newline and frees the full string
char	*ft_next(char *buf);

#endif