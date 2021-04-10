/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:30:35 by lchristo          #+#    #+#             */
/*   Updated: 2019/10/22 03:48:41 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*si;
	size_t		i;

	i = 0;
	si = s;
	while ((i < n))
	{
		if (si[i] == c)
			return ((char *)si + i);
		i++;
	}
	return (NULL);
}
