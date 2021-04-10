/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:54:03 by lchristo          #+#    #+#             */
/*   Updated: 2019/10/29 04:22:47 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*str;
	const char	*rts;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	str = dst;
	rts = src;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		str[i] = rts[i];
		i++;
	}
	return (dst);
}
