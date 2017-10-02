/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_selected.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:58:43 by eterman           #+#    #+#             */
/*   Updated: 2017/02/15 22:14:53 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		print_selected(t_list *options, int is_first)
{
	while (options)
	{
		if (LCONT(options, t_option*)->is_selected)
		{
			if (!is_first)
				ft_putstr(" ");
			ft_putstr(LCONT(options, t_option*)->value);
			print_selected(LNEXT(options), 0);
			return ;
		}
		LTONEXT(options);
	}
}
