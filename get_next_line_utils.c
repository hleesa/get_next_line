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

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	const char	ch = c;

	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		++i;
	}
	if (ch == 0)
		return ((char *)(s + i));
	return (0);
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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		++len;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1len;
	size_t	s2len;

	if (s1 == 0 && s2 == 0)
		return (0);
	s1len = 0;
	s2len = 0;
	if (s1 != 0)
		s1len = ft_strlen(s1);
	if (s2 != 0)
		s2len = ft_strlen(s2);
	ret = (char *) malloc(s1len + s2len + 1);
	if (ret == 0)
		return (0);
	ft_memmove(ret, s1, s1len);
	ft_memmove(ret + s1len, s2, s2len);
	ret[s1len + s2len] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	s_len;

	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (s_len < len + start)
		len = s_len - start;
	ret = (char *) malloc(len + 1);
	if (ret == 0)
		return (0);
	i = 0;
	ft_memmove(ret, s + start, len);
	ret[len] = '\0';
	return (ret);
}



char	*ft_strdup(const char *s1)
{
	char			*ret;
	size_t			i;
	const size_t	size = ft_strlen(s1) + 1;

	ret = (char *) malloc(sizeof(char) * (size));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		ret[i] = s1[i];
		++i;
	}
	return (ret);
}
