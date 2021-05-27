/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:42:58 by jechoi            #+#    #+#             */
/*   Updated: 2021/05/26 20:54:27 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

// size_t	ft_strlcat(char *dest, const char *src, size_t size)
// {
// 	size_t ret;

// 	ret = 0;
// 	while (*dest && ret < size)
// 	{
// 		dest++;
// 		ret++;
// 	}
// 	while (*src && ret + 1 < size)
// 	{
// 		*dest = *src;
// 		dest++;
// 		src++;
// 		ret++;
// 	}
// 	if (ret < size)
// 		*dest = '\0';
// 	while (*src)
// 	{
// 		src++;
// 		ret++;
// 	}
// 	return (ret);
// }

// size_t	ft_strlcpy(char *dest, const char *src, size_t size)
// {
// 	size_t	pos;

// 	pos = 0;
// 	while (src[pos] && pos + 1 < size)
// 	{
// 		dest[pos] = src[pos];
// 		pos++;
// 	}
// 	if (size != 0)
// 		dest[pos] = '\0';
// 	while (src[pos])
// 		pos++;
// 	return (pos);
// }

// char	*ft_strdup(const char *src)
// {
// 	char	*ret;
// 	size_t	idx;
// 	size_t	len;

// 	len = ft_strlen(src);
// 	ret = (char *)malloc(sizeof(char) * (len + 1));
// 	idx = -1;
// 	while (++idx < len)
// 		ret[idx] = src[idx];
// 	ret[idx] = '\0';
// 	return (ret);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ret_len;
	char	*ret;

	if (!s1 || !s2)
		return (0);
	ret_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(ret = (char *)malloc(ret_len)))
		return (0);
	ft_strlcpy(ret, s1, ret_len);
	ft_strlcat(ret, s2, ret_len);
	return (ret);
}
