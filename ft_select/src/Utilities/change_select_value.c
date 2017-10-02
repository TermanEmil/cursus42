/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_select_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:39:52 by eterman           #+#    #+#             */
/*   Updated: 2017/02/18 17:22:51 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** Slect or diselects all options. Must call refresh after that.
*/

void		change_select_value(t_list *options, int to_true)
{
	while (options)
	{
		LCONT(options, t_option*)->is_selected = to_true;
		LTONEXT(options);
	}
}
