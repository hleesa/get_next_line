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


int	add_line(char *ret, char *buff, ssize_t read_bytes)
{
	char * addr_of_newline = ft_strchr(buff, '\n');


	/*
	 * 파일의 끝 vs 개행 없는 꽉찬 데이터
	 */

	if (addr_of_newline == 0)
	{
		ft_strjoin(ret, ft_substr(buff, 0, len));
		buff += len;
	}
	else
	{
		ft_strjoin(ret, ft_substr(buff, 0, addr_of_newline - buff));
		buff += addr_of_newline - buff;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		**ret;
 	static char	*buff;
	ssize_t		read_bytes = 0;


	buff = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (buff == 0)
		return (0);
	ret = 0;
	if(*buff == 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		printf("----------- in if(*buff == 0) -----------\n");
		/*
		 * 에러 발생?
		 *
		 * EOF 처리는 read() 에서 처리
		 * return : 읽은 바이트 수
		 * -1 : 에러
		 * 0 : 파일의
		 */
	}
	while(add_line(ret, buff, read_bytes))
	{
		printf("%s\n", ret);
		if(*buff == 0)
			return 0;
	}

	/*
	 * 널을 찾을 떄 까지 읽는다.
	 *
	 */
	printf("read_bytes: %zd\n",read_bytes);
	printf("buff: %s\n", buff);
	printf("--------------------\n");

	return 0;
}