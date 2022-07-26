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

void	*memjoin(void *addr_front, t_range front_range, void *addr_back, t_range back_range)
{
	void	*ret;
	const ssize_t front_size = front_range.end - front_range.begin;
	const ssize_t back_size = back_range.end - back_range.begin;

	ret = malloc(front_size + back_size + 1);
	if (ret == 0)
		return (0);
	ft_memmove(ret, addr_front, front_size);
	ft_memmove((unsigned char *) ret + front_size, addr_back, \
			back_size);
	return (ret);
}

ssize_t	buff_init(char *buff, t_data *repository)
{
	ssize_t	data_size;

	if (repository == 0)
		data_size = 0;
	else
	{
		ft_memmove((void *) buff, repository->data, repository->size);
		repository->data = 0;
		data_size = repository->size;
		repository->size = 0;
	}
	return (data_size);
}

char	*get_one_line(int fd, t_data *repository)
{
	t_data	ret;
	char	buff[BUFFER_SIZE];
	ssize_t	data_size;
	ssize_t	newline_offset;

	ret = (t_data){0, 0};
	data_size = buff_init(buff, repository);
	while (repository == 0)
	{
		if (data_size == -1)
			break ;
		newline_offset = get_newline_offset(buff, '\n', data_size);
		if (newline_offset == -1)
		{
			ret.data = memjoin(ret.data, (t_range){0, ret.size}, buff, (t_range){0, data_size});
			ret.size += data_size;
		}
		else
		{
			ret.data = memjoin(ret.data, (t_range){0, ret.size}, buff, (t_range){0, newline_offset + 1});
			ret.size += newline_offset + 1;
			ret.data = memjoin(repository->data, (t_range){0, repository->size}, buff, (t_range){newline_offset + 1, data_size});
			repository->size = data_size - (newline_offset + 1);
			break ;
		}
		data_size = read(fd, (void *) buff, BUFFER_SIZE);
	}
	return (ret.data);
}

char	*get_next_line(int fd)
{
	static t_data	repository;

	if (fd < 0)
		return (0);
	return (get_one_line(fd, &repository));
}
