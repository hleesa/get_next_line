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

struct s_struct
{
	char *stored_data;
	ssize_t bytes_of_data;
};

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
	char		buff[BUFFER_SIZE];
	static struct s_line

	};
	char 		*adrr_of_newline;
	ssize_t 	len_of_rest;

	if(rest_buff == )
		read(fd, buff, BUFFER_SIZE);

	ssize_t read_bytes = 0;
}
