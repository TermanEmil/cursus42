/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_memdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:41:44 by eterman           #+#    #+#             */
/*   Updated: 2017/02/13 18:04:31 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Usually used as: ft_lstdel(&list, &ft_lst_memdel);
*/

void		ft_lst_memdel(void *content, size_t size)
{
	(void)size;
	if (content != NULL)
		free(content);
}
