/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:33 by mjulliat          #+#    #+#             */
/*   Updated: 2022/10/21 13:56:56 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_and_join(char *buffer, char *str)
{
	char	*tmp;

	tmp = ft_strjoin(str, buffer);
	free(buffer);
	return (tmp);
}

char	*read_buffer(int fd, char *str)
{
	char	*buffer;
	int		byte_read;

	if (!str)
	{
		str = ft_calloc(1, 1);
		if (!str)
			return (NULL);
	}
	byte_read = 1;
	while (byte_read > 0)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		byte_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		str = free_and_join(buffer, str);
		if (ft_strchr(str, '\n'))
			break ;
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
	len_line = i;
	i = 0;
	line = ft_calloc(len_line + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (i < len_line)
	{
		line[i] = buffer[i];
		i++;
	}
	line[len_line] = '\n';
	return (line);
}

char	*ft_next_line(char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (buffer[i] != '\n')
		i++;
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
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	line = ft_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
	free(buffer);
}
/*
int	main(void)
{
	int	fd;
	char *test;

	fd = open("test.txt", O_RDONLY);
	test = get_next_line(fd);
	printf("--------------------\n");
	printf("{%s}\n", test);
	test = get_next_line(fd);
	printf("--------------------\n");
	printf("{%s}\n", test);
	test = get_next_line(fd);
	printf("--------------------\n");
	printf("{%s}\n", test);
	test = get_next_line(fd);
	printf("--------------------\n");
	printf("{%s}\n", test);
	test = get_next_line(fd);
	printf("--------------------\n");
	printf("{%s}\n", test);
	test = get_next_line(fd);
	printf("--------------------\n");
	printf("{%s}\n", test);
	test = get_next_line(fd);
	printf("--------------------\n");
	printf("{%s}\n", test);
	free(test);
	test = 0;
	return (0);
}
*/
