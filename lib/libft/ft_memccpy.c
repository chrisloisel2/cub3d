/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:10:24 by lchristo          #+#    #+#             */
/*   Updated: 2019/11/02 04:56:51 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pt_src;
	unsigned char	*pt_dst;

	pt_src = (unsigned char *)src;
	pt_dst = (unsigned char *)dst;
	while (n-- && *pt_src != (unsigned char)c)
		*pt_dst++ = *pt_src++;
	if (*pt_src == (unsigned char)c)
	{
		*pt_dst++ = *pt_src;
		return ((unsigned char *)pt_dst);
	}
	return ((unsigned char *)0);
}
