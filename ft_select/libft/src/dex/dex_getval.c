/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dex_getval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 21:46:09 by eterman           #+#    #+#             */
/*   Updated: 2017/02/14 11:45:22 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		**dex_getval(t_list *ldex, int (*cmp)(void*, void*), void *key)
{
	if (ldex == NULL)
		return (NULL);
	if (cmp(DEX_K(ldex), key))
		return (&DEX_V(ldex));
	return (dex_getval(ldex->next, cmp, key));
}
