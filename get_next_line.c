/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:10:11 by jechoi            #+#    #+#             */
/*   Updated: 2021/05/26 21:15:12 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	chk_newline(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	split_by_newline(char **store, char **line)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*store)[i])
	{
		if ((*store)[i] == '\n')
		{
			(*store)[i] = '\0';
			break ;
		}
		i++;
	}
	*line = ft_strdup(*store);
	if (ft_strlen(*store + i + 1) == 0)
	{
		free(*store);
		*store = 0;
		return (1);
	}
	tmp = ft_strdup(*store + i + 1);
	free(*store);
	*store = tmp;
	return (1);
}

int	poc_remain(int size_of_read, char **store, char **line)
{
	if (size_of_read < 0)
		return (-1);
	if (*store && chk_newline(*store))
		return (split_by_newline(store, line));
	if (*store)
	{
		*line = *store;
		*store = 0;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*store[OPEN_MAX];
	int				size_of_read;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (line == 0))
		return (-1);
	while ((size_of_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size_of_read] = '\0';
		store[fd] = ft_strjoin(store[fd], buf);
		if (chk_newline(store[fd]))
			return (split_by_newline(&store[fd], line));
	}
	return (poc_remain(size_of_read, &store[fd], line));
}
