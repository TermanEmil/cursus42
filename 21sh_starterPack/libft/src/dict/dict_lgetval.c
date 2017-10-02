/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dex_lgetval.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 21:46:09 by eterman           #+#    #+#             */
/*   Updated: 2017/02/20 10:32:52 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		**dex_lgetval(t_list *ldex, int (*cmp)(void*, void*), void *key)
{
	if (ldex == NULL)
		return (NULL);
	if (cmp(DEX_K(ldex), key))
		return (&DEX_V(ldex));
	return (dex_lgetval(ldex->next, cmp, key));
}
