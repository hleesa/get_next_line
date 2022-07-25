/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:41:09 by salee2            #+#    #+#             */
/*   Updated: 2022/07/19 18:58:16 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 10

ssize_t	get_newline_offset(const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	ch = c;
	const unsigned char	*sp = (const unsigned char *) src;

	i = 0;
	while (i < n)
	{
		if (sp[i] == ch)
			return (i);
		++i;
	}
	return (-1);
}

void	*memjoin(void *front, void *back, t_range back_range)
{
	void	*ret;
	void	*addr_of_front_data;
	void	*addr_of_back_data;
	ssize_t	front_size;
	ssize_t	back_size;

	addr_of_front_data = ((t_data *) front)->data;
	addr_of_back_data = ((t_data *) back)->data;
	front_size = ((t_data *) front)->size;
	back_size = back_range.end - back_range.begin;
	ret = malloc(front_size + back_size);
	if (ret == 0)
	{
		free(front);
		return (0);
	}
	ft_memmove(ret, addr_of_front_data, front_size);
	ft_memmove((unsigned char *) ret + front_size, addr_of_back_data, \
			back_size);
	free(front);
	return (ret);
}

ssize_t	buff_init(char *buff, t_data **repository)
{
	ssize_t	data_size;

	if ((*repository)->size == 0)
		data_size = 0;
	else
	{
		ft_memmove((void *) buff, (*repository)->data, (*repository)->size);
		free((*repository)->data);
		(*repository)->data = 0;
		data_size = (*repository)->size;
		(*repository)->size = 0;
	}
	return (data_size);
}

char	*get_one_line(int fd, t_data **repository)
{
	t_data	ret;
	char	buff[BUFFER_SIZE];
	ssize_t	data_size;
	ssize_t	newline_offset;

	ret = (t_data){0, 0};
	data_size = buff_init(buff, repository);
	while ((*repository)->size == 0)
	{
		if (data_size == -1)
			break ;
		newline_offset = get_newline_offset(buff, '\n', data_size);
		if (newline_offset == -1)
		{
			ret.data = memjoin(ret.data, buff, (t_range){0, data_size});
			ret.size += data_size;
		}
		else
		{
			ret.data = memjoin(ret.data, buff, \
					(t_range){0, newline_offset + 1});
			ret.size += newline_offset + 1;
			(*repository)->data = memjoin((*repository)->data, buff, \
					(t_range){newline_offset + 1, data_size});
			(*repository)->size = data_size - (newline_offset + 1);
			break ;
		}
		data_size = read(fd, (void *) buff, BUFFER_SIZE);
	}
	return (ret.data);
}

char	*get_next_line(int fd)
{
	static t_data	*repository;

	if (fd < 0)
		return (0);
	return (get_one_line(fd, &repository));
}
