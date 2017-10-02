/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_strlist_cell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 09:39:42 by eterman           #+#    #+#             */
/*   Updated: 2017/01/17 10:01:32 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees the data of a t_list cell, considering that the content is a string.
*/

void	del_strlist_cell(void *data, size_t size)
{
	(void)size;
	ft_strdelif((char**)(&data));
}
