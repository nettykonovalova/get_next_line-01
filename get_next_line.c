/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonoval <akonoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:00:45 by akonoval          #+#    #+#             */
/*   Updated: 2025/11/03 20:00:09 by akonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_clean_buff(char *buff)
{
	if (buff)
		buff[0] = '\0';
}

char	*gnl_join_or_fail(char **line, char *buff)
{
	*line = gnl_strjoin_and_free(*line, buff);
	if (!*line)
	{
		gnl_clean_buff(buff);
		return (NULL);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	line = gnl_strjoin_and_free(line, buff);
	if (!line && buff[0] != '\0')
		return (NULL);
	while (!gnl_strchr(line, '\n'))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (gnl_clean_buff(buff), free(line), NULL);
		buff[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		if (!gnl_join_or_fail(&line, buff))
			return (NULL);
	}
	gnl_new_buff(buff);
	if (!line || line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
/*
#include <fcntl.h>   // for open()
#include <stdio.h>   // for printf()

int main(void)
{
    int fd;
    char *line;

    // Open a text file for reading
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    // Keep reading until get_next_line returns NULL
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }

    close(fd);
    return (0);
}
*/
