/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_agetval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 10:12:45 by eterman           #+#    #+#             */
/*   Updated: 2017/05/29 18:51:43 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Finds value from an array of dexes.
*/

void	*dict_agetval(const t_dict *dex_arry,
			int (*cmp)(void*, void*), void *key)
{
	while (dex_arry && (dex_arry->key != NULL || dex_arry->value != NULL))
	{
		if (cmp(key, dex_arry->key))
			return (dex_arry->value);
		dex_arry++;
	}
	return (NULL);
}
