/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 04:28:24 by lchristo          #+#    #+#             */
/*   Updated: 2020/06/11 04:40:04 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_free_strjoin(char *s1, char *s2, char **leaks)
{
	char *new;

	new = *leaks;
	*leaks = ft_strjoin((const char *)s1, (const char *)s2);
	(new) ? free(new) : 0;
	new = NULL;
}
