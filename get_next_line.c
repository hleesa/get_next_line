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


int	append_line(char *ret, char *buff)
{
	char *new_ret;

	new_ret = ft_strjoin(ret, buff);
	if(new_ret == NULL)
		return (0);
	free(ret);
	ret = new_ret;
	return (ret != NULL);
}

char*	get_addr_of_newline(char * buff)
{
	return (ft_strchr(buff, '\n'));
}


int append_last_line(char *ret, char *buff)
{
	char *addr_of_newline;
	char *end_of_line;

	addr_of_newline = get_addr_of_newline(buff);
	end_of_line = ft_substr(buff, 0, addr_of_newline - buff);
	ft_strjoin(ret, end_of_line);
	free(end_of_line);
	// 위 함수들 반환값 확인 및 에러 호출
	return (1);
}

char	*get_next_line(int fd)
{
	char		*ret;
 	static char	*buff;
	ssize_t		read_bytes = 0;
	char		*addr_of_newline;

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	ret = 0;
	if(buff == NULL)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 1)	// -1 : 에러, 0 : EOF
		{
			free(buff);
			return NULL;
		}
	}
	while (1)
	{
		addr_of_newline = get_addr_of_newline(buff);
		if (addr_of_newline != NULL)
			break;
		if (append_line(ret, buff) == 0)
			return NULL;
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return NULL;
		else if (read_bytes == 0)
			break;
	}
	append_last_line(ret, buff);
	if(read_bytes < 1)
		free(buff);
	return 0;
}