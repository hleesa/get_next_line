/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:25:57 by salee2            #+#    #+#             */
/*   Updated: 2022/07/28 13:26:18 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_data
{
	char	*data;
	ssize_t	size;
}	t_data;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

void	*memjoin(void *data, ssize_t d_size, void *buff, ssize_t b_size);
ssize_t	buff_init(char *buff, t_data *repository);
void	update_repository(t_data *repository, char *buff, \
		ssize_t newline_offset, ssize_t data_size);
void	get_one_line(t_data *ret, int fd, char *buff, t_data *repository);
char	*get_next_line(int fd);
ssize_t	get_newline_offset(const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif //GET_NEXT_LINE_BONUS_H
