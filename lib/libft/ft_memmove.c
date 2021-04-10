/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:12:19 by lchristo          #+#    #+#             */
/*   Updated: 2019/11/02 04:57:52 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	cpy[n + 1];
	size_t			i;

	if (!dest && !src)
		return (NULL);
	s2 = (unsigned char *)src;
	s1 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		cpy[i] = s2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		s1[i] = cpy[i];
		i++;
	}
	return (dest);
}
