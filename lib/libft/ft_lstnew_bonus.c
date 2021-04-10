/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:38:18 by lchristo          #+#    #+#             */
/*   Updated: 2019/10/24 05:24:44 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *lsnext;

	if (!(lsnext = malloc(sizeof(t_list))))
		return (NULL);
	lsnext->content = content;
	lsnext->next = NULL;
	return (lsnext);
}
