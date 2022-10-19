/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:59:53 by mjulliat          #+#    #+#             */
/*   Updated: 2022/10/19 16:02:19 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t nbyte)
{
	char	*str;

	str = malloc(count * nbyte);
	if (!str)
		return (NULL);
	ft_bzero(str, count * nbyte);	
	return (str);
}

void	ft_bzero(void *b, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
char	*str_join()
{
	return (str_joined);
}
*/
