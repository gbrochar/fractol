/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:00:51 by gbrochar          #+#    #+#             */
/*   Updated: 2016/05/11 14:44:53 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char *str, char *str2)
{
	char	*tmp;

	tmp = ft_strjoin(str, str2);
	free(str);
	return (tmp);
}

int		gnl_manage_return(char **line, char **stock)
{
	char	*tmp;
	char	*tmp2;

	if ((tmp = ft_strchr(*stock, '\n')))
	{
		*tmp = '\0';
		tmp2 = ft_strdup(tmp + 1);
		*line = ft_strdup(*stock);
		ft_memdel((void **)stock);
		*stock = ft_strdup(tmp2);
		free(tmp2);
		tmp2 = NULL;
		tmp = NULL;
		return (1);
	}
	if (ft_strlen(*stock) == 0)
	{
		ft_memdel((void **)stock);
		return (0);
	}
	*line = ft_strdup(*stock);
	ft_memdel((void **)stock);
	return (1);
}

int		gnl_manage_read(char **stock, char **line)
{
	char	*tmp;
	char	*tmp2;

	if ((tmp = ft_strchr(*stock, '\n')))
	{
		*tmp = '\0';
		tmp2 = ft_strdup(tmp + 1);
		*line = ft_strdup(*stock);
		ft_memdel((void **)stock);
		*stock = ft_strdup(tmp2);
		free(tmp2);
		tmp2 = NULL;
		tmp = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char			*stock = NULL;
	char				*buffer;
	int					ret;

	if (stock)
		if (gnl_manage_read(line, &stock))
			return (1);
	buffer = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		stock = ft_strjoin2(stock, buffer);
		ft_memdel((void **)&buffer);
		if (gnl_manage_read(&stock, line))
			return (1);
		buffer = ft_strnew(BUFF_SIZE + 1);
	}
	if (buffer)
		ft_memdel((void **)&buffer);
	if (ret == -1)
		return (-1);
	return (gnl_manage_return(line, &stock));
}
