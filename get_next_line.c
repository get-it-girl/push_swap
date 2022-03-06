/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:25:27 by wmika             #+#    #+#             */
/*   Updated: 2021/10/22 10:25:47 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*reader(int fd, char *left_buff)
{
	char	*buff;
	int		red;

	red = 1;
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	buff[BUFFER_SIZE] = '\0';
	if (!buff)
		return (NULL);
	while (red > 0 && !ft_strchr_1(buff, '\n'))
	{
		red = read(fd, buff, BUFFER_SIZE);
		if (red < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[red] = '\0';
		left_buff = ft_strjoin_1(left_buff, buff);
	}
	if (buff)
		free(buff);
	return (left_buff);
}

int	extra_1(char *left_buf)
{
	int	i;

	i = 0;
	while (left_buf[i] != '\n' && left_buf[i] != '\0')
		i++;
	return (i);
}

char	*result(char *left_buf)
{
	char	*res;
	int		i;

	if (left_buf == NULL)
		return (NULL);
	i = extra_1(left_buf);
	if (left_buf[i] == '\n')
	{
		res = malloc(sizeof(char) * (i + 2));
		if (!res)
			return (NULL);
		res[i] = '\0';
	}
	else
	{
		if (ft_strlen_1(left_buf) == 0)
			return (NULL);
		res = malloc(sizeof(char) * (i + 1));
		if (!res)
			return (NULL);
		res[i] = '\0';
	}
	while (--i >= 0)
		res[i] = left_buf[i];
	return (res);
}

char	*out_left(char *left_buf)
{
	char	*res;
	size_t	i;
	int		n;

	n = 0;
	if (left_buf == NULL)
		return (NULL);
	i = extra_1(left_buf);
	if (left_buf[i] == '\0' || ft_strlen_1(left_buf) == ++i
		|| ft_strlen_1(left_buf) == 0)
	{
		free(left_buf);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen_1(left_buf) - i + 1));
	if (!res)
	{
		free(left_buf);
		return (NULL);
	}
	while (left_buf[i] != '\0')
		res[n++] = left_buf[i++];
	res[n] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*left_buf;
	char		*res;
	char		*extra;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_buf = reader(fd, left_buf);
	res = result(left_buf);
	extra = left_buf;
	left_buf = out_left(extra);
	if (left_buf != NULL)
		free(extra);
	return (res);
}
