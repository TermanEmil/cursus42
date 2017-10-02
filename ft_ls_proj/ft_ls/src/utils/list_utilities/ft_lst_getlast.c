/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getlast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:59:49 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 17:21:49 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_lst_getlast(t_list *head)
{
	if (ft_lst_islast(head))
		return (head);
	else
		return (ft_lst_getlast(head->next));
}
