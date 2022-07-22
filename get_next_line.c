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
	ret = ft_strjoin(ret, buff);
	return (ret =! NULL);
}

int append_last_line(char *ret, char *buff)
{
	char *addr_of_newline;
	char *end_of_line;

	addr_of_newline = ft_strchr(buff, '\n');
	end_of_line = ft_substr(buff, 0, addr_of_newline - buff);
	ft_strjoin(ret, end_of_line);
	free(end_of_line);
	// 위 함수들 반환값 확인 및 에러 호출
	return (1)
}

int is_contain_newline(char * buff)
{
	char *addr_of_newline;

	addr_of_newline = ft_strchr(buff, '\n');
	return (addr_of_newline != NULL);
}


char	*get_next_line(int fd)
{
	char		*ret;
 	static char	*buff;
	ssize_t		read_bytes = 0;
	int 		append_result;

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == 0)
		return (0);
	ret = 0;
	if(*buff == 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 1)	// -1 : 에러, 0 : EOF
			return NULL;
	}
	append_result = 0;
	while (!is_contain_newline(buff) && read_bytes > 0)
	{
		append_result = append_line(ret, buff);
		if (append_result == NULL)
			return NULL;
		read_bytes = read(fd, buff, BUFFER_SIZE);
	}



	printf("read_bytes: %zd\n",read_bytes);
	printf("buff: %s\n", buff);
	printf("--------------------\n");

	return 0;
}