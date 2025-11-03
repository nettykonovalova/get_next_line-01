/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:00:50 by akonoval          #+#    #+#             */
/*   Updated: 2025/11/03 19:52:00 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

// Utility functions
size_t	gnl_linelen(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin_and_free(char *s1, const char *s2);
void	gnl_new_buff(char *buff);
void	gnl_clean_buff(char *buff);
char	*gnl_join_or_fail(char **line, char *buff);

#endif