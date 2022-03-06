/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmika <wmika@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:25:59 by wmika             #+#    #+#             */
/*   Updated: 2021/10/22 10:26:07 by wmika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>

# define BUFFER_SIZE  1

char	*get_next_line(int fd);
size_t	ft_strlen_1(char *str);
char	*ft_strjoin_1(char *s1, char *s2);
char	*ft_strchr_1(char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*reader(int fd, char *left_buff);
char	*result(char *left_buf);
char	*out_left(char *left_buf);

#endif
