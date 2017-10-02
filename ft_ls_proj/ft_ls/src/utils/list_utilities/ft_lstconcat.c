/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:04:58 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 17:22:28 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_lstconcat(t_list **dest, t_list *files)
{
	t_list	*last;

	if (*dest == NULL)
		*dest = files;
	else if (files != NULL)
	{
		last = ft_lst_getlast(*dest);
		if (last != NULL)
			last->next = files;
	}
	return (*dest);
}
