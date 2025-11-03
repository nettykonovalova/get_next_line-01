/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:00:41 by akonoval          #+#    #+#             */
/*   Updated: 2025/11/03 19:48:45 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//String length function
size_t	gnl_linelen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i + (s[i] == '\n'));
}

// Search function
char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// Concatenation function
char	*gnl_strjoin_and_free(char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(gnl_linelen(s1) + gnl_linelen(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < (size_t)BUFFER_SIZE && s2 && s2[j] && s2[j] != '\n')
	{
		str[i + j] = s2[j];
		j++;
	}
	if (s2 && s2[j] == '\n')
		str[i + j++] = '\n';
	str[i + j] = '\0';
	return (free(s1), str);
}

// New buffer function
void	gnl_new_buff(char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buff)
		return ;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	while (buff[j + i])
	{
		buff[j] = buff[i + j];
		j++;
	}
	buff[j] = '\0';
}
