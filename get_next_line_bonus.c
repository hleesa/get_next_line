/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:41:09 by salee2            #+#    #+#             */
/*   Updated: 2022/07/29 13:50:00 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*memjoin(void *data, ssize_t d_size, void *buff, ssize_t b_size)
{
	void	*ret;

	ret = malloc(sizeof(unsigned char) * (d_size + b_size + 1));
	if (ret == NULL)
	{
		if (data != NULL)
			free(data);
		return (NULL);
	}
	ft_memmove(ret, data, d_size);
	ft_memmove((unsigned char *)ret + d_size, buff, b_size);
	((unsigned char *)ret)[d_size + b_size] = '\0';
	if (data != NULL)
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
		*repository = (t_data){NULL, 0};
	}
	return (data_size);
}

void	update_repository(t_data *repository, char *buff, \
		ssize_t newline_offset, ssize_t data_size)
{
	if (newline_offset + 1 < data_size)
	{
		repository->data = memjoin(NULL, 0, \
				buff + newline_offset + 1, data_size - (newline_offset + 1));
		if (repository->data == NULL)
		{
			repository->size = 0;
			return ;
		}
		repository->size = data_size - (newline_offset + 1);
	}
	return ;
}

void	get_one_line(t_data *ret, int fd, char *buff, t_data *repository)
{
	ssize_t	data_size;
	ssize_t	newline_offset;
	ssize_t	b_size;

	data_size = buff_init(buff, repository);
	while (1)
	{
		newline_offset = get_newline_offset(buff, '\n', data_size);
		if (newline_offset == -1)
			b_size = data_size;
		else
			b_size = newline_offset + 1;
		ret->data = memjoin(ret->data, ret->size, buff, b_size);
		if (ret->data == NULL)
			return ;
		ret->size += b_size;
		if (newline_offset != -1)
			break ;
		data_size = read(fd, (void *) buff, BUFFER_SIZE);
		if (data_size < 1)
			break ;
	}
	if (data_size < 0)
		return ;
	update_repository(repository, buff, newline_offset, data_size);
}

char	*get_next_line(int fd)
{
	t_data			ret;
	char			*buff;
	static t_data	repository[OPEN_MAX];

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 0)
		return (0);
	buff = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (buff == NULL)
		return (NULL);
	ret = (t_data){NULL, 0};
	get_one_line(&ret, fd, buff, repository + fd);
	if (ret.size == 0)
	{
		if (ret.data != NULL)
			free(ret.data);
		ret.data = NULL;
	}
	free(buff);
	return (ret.data);
}
