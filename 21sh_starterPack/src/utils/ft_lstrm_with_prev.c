/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm_with_prev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 00:03:45 by eterman           #+#    #+#             */
/*   Updated: 2017/01/22 00:33:15 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Such a shity lib function ...
*/

void	ft_lstrm_with_prev(t_list **head, t_list *target, t_list *prev)
{
	if (head == NULL || *head == NULL || target == NULL)
		return ;
	if (prev == NULL)
		*head = LNEXT(*head);
	else
		prev->next = LNEXT(target);
	ft_lstdelone(&target, &del_strlist_cell);
}
