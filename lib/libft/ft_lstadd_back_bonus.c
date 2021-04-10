/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 03:39:56 by lchristo          #+#    #+#             */
/*   Updated: 2019/11/17 22:28:45 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *p;

	if (*alst == NULL)
	{
		new->next = NULL;
		*alst = new;
	}
	p = (ft_lstlast(*alst));
	p->next = new;
	new->next = NULL;
}
