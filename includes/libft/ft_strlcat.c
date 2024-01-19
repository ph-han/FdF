/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:31:06 by phan              #+#    #+#             */
/*   Updated: 2023/04/01 14:56:52 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	p_idx;
	size_t	s_idx;

	if (!dstsize)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	s_idx = 0;
	p_idx = dst_len;
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	while (src[s_idx] && (s_idx + dst_len + 1) < dstsize)
	{
		dst[p_idx] = src[s_idx];
		p_idx++;
		s_idx++;
	}
	dst[p_idx] = '\0';
	return (src_len + dst_len);
}
