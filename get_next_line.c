/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:10:11 by jechoi            #+#    #+#             */
/*   Updated: 2021/05/27 20:33:44 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		chk_newline(char *buf)
{
	size_t	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	split_by_newline(char **store, char **line)
{
	size_t	i;

	i = 0;
	if (!*store)
	{
		*line = 0;
		return ;
	}
	while ((*store)[i] && (*store)[i] != '\n')
		i++;
	if (!(*line = malloc(sizeof(char) * (i + 1))))
	{
		*line = 0;
		return ;
	}
	i = 0;
	while ((*store)[i] && (*store)[i] != '\n')
	{
		(*line)[i] = (*store)[i];
		i++;
	}
	(*line)[i] = '\0';
}

char	*remain_process(char **store)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!*store)
		return (0);
	i = 0;
	j = 0;
	while ((*store)[i] && (*store)[i] != '\n')
		i++;
	if (!(*store)[i])
	{
		free(*store);
		return (0);
	}
	if (!(ret = malloc(sizeof(char) * (ft_strlen(*store) - i + 1))))
		return (0);
	i++;
	while ((*store)[i])
		ret[j++] = (*store)[i++];
	ret[j] = '\0';
	free(*store);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*store[OPEN_MAX];
	int				size_of_read;
	
	if ((fd < 0) || (BUFFER_SIZE <= 0) || (line == 0))
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	size_of_read = 1;
	while (!chk_newline(store[fd]) && size_of_read != 0)
	{
		if ((size_of_read = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[size_of_read] = '\0';
		store[fd] = ft_strjoin(store[fd], buf);
	}
	free(buf);
	split_by_newline(&store[fd], line);
	store[fd] = remain_process(&store[fd]);
	if (size_of_read == 0)
		return (0);
	return (1);
}
