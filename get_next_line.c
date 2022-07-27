/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:41:09 by salee2            #+#    #+#             */
/*   Updated: 2022/07/27 16:27:02 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	*memjoin(void *data, ssize_t d_size, void *buff, ssize_t b_size)
{
	void	*ret;

	ret = malloc(d_size + b_size + 1);
	if (ret == 0)
	{
		free(data);
		return (0);
	}
	ft_memmove(ret, data, d_size);
	ft_memmove((unsigned char *)ret + d_size, buff, b_size);
	((unsigned char *)ret)[d_size + b_size] = 0;
	free(data);
	return (ret);
}

ssize_t	buff_init(char *buff, t_data *repository)
{
	ssize_t	data_size;

	if (repository->size == 0)
		data_size = 0;
	else
	{
		ft_memmove((void *) buff, repository->data, repository->size);
		free(repository->data);
		data_size = repository->size;
		repository->data = 0;
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
	while (repository->data == 0)
	{
		newline_offset = get_newline_offset(buff, '\n', data_size);
		if (newline_offset == -1)
		{
			ret.data = memjoin(ret.data, ret.size, buff, data_size);
			if (ret.data == 0)
				return (0);
			ret.size += data_size;
		}
		else
		{
			ret.data = memjoin(ret.data, ret.size, buff, newline_offset + 1);
			if (ret.data == 0)
				return (0);
			ret.size += newline_offset + 1;
			if (newline_offset + 1 < BUFFER_SIZE)
			{
				repository->data = memjoin(repository->data, repository->size,
										   buff + newline_offset + 1,
										   data_size - (newline_offset + 1));
				if (repository->data == 0)
					return (0);
				repository->size = data_size - (newline_offset + 1);
			}
			break ;
		}
		data_size = read(fd, (void *) buff, BUFFER_SIZE);
		if (data_size < 1)
			break ;
	}
	if (ret.size == 0)
		return (0);
	return (ret.data);
}

char	*get_next_line(int fd)
{
	static t_data	repository;

	if (fd < 0 || fd >= OPEN_MAX)
		return (0);
	return (get_one_line(fd, &repository));
}
