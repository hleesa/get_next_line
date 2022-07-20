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

/*
 * fd 값으로 에러?
 * '\n' 찾기 || EOF 찾
 *
 *
 */

#include "get_next_line.h"

#define BUFFER_SIZE 10

/*
char	*get_next_line(int fd)
{
	fd = 0;
}
*/

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = 0;
	int ret;
	char buff[BUFFER_SIZE] = {0,};
	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
		printf("%s\n", "file open error");
	ret = read(fd, buff, BUFFER_SIZE);
	printf("ret: %d\n",ret);
	printf("buff: %s\n", buff);
	printf("--------------------\n");

	ret = read(fd, buff, BUFFER_SIZE);
	printf("ret: %d\n",ret);
	printf("buff: %s\n", buff);
	printf("--------------------\n");

	ret =read(fd, buff, BUFFER_SIZE);
	printf("ret: %d\n",ret);
	printf("buff: %s\n\n", buff);
	printf("--------------------\n");

	ret = read(fd, buff, BUFFER_SIZE);
	printf("ret: %d\n",ret);
	printf("buff: %s\n\n", buff);
	printf("--------------------\n");

}
