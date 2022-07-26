/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:58:45 by salee2            #+#    #+#             */
/*   Updated: 2022/07/19 18:58:46 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
