/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:33 by mjulliat          #+#    #+#             */
/*   Updated: 2022/10/24 10:58:44 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_str(char *buffer, char *str, int byte_read, int fd)
{
	char	*tmp;

	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read <= 0)
			break ;
		buffer[byte_read] = '\0';
		tmp = ft_strjoin(str, buffer);
		free(str);
		str = tmp;
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

char	*ft_read_buffer(int fd, char *str)
{
	char	*buffer;
	int		byte_read;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = 1;
	str = ft_join_str(buffer, str, byte_read, fd);
	free(buffer);
	buffer = 0;
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*ft_line(char *buffer)
{
	unsigned int	i;
	size_t			len_line;
	char			*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		len_line = i + 1;
	else
		len_line = i;
	i = 0;
	line = ft_calloc(len_line + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (i < len_line)
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*ft_next_line(char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i += 1;
	str = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (buffer[i] != '\0')
	{
		str[j] = buffer[i];
		j++;
		i++;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_next_line(buffer[fd]);
	return (line);
}
