/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:26:34 by salee2            #+#    #+#             */
/*   Updated: 2022/07/29 13:00:40 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dp;
	const unsigned char	*sp;

	if (dst == 0 && src == 0)
		return (0);
	if (len == 0)
		return (dst);
	i = 0;
	dp = (unsigned char *)dst;
	sp = (const unsigned char *)src;
	while (i < len)
	{
		if (dp < sp)
		{
			dp[i] = sp[i];
			++i;
		}
		else
		{
			dp[len - 1] = sp[len - 1];
			--len;
		}
	}
	return (dst);
}
