/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:07:31 by lchristo          #+#    #+#             */
/*   Updated: 2019/10/11 05:06:55 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;
	int		y;

	y = 0;
	i = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] && i <= (int)len)
	{
		if ((str[i] == to_find[0]) && ((i + ft_strlen(to_find)) <= (int)len))
		{
			while ((str[i] == to_find[y]) && str[i])
			{
				y++;
				i++;
			}
			i = (i - y);
			if (y == ft_strlen(to_find))
				return ((char *)&str[i]);
			else
				y = 0;
		}
		i++;
	}
	return (0);
}
