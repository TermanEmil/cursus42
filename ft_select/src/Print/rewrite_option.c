/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:19:33 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 23:02:10 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** Rewrite an option with its given effects (underlined, selected, etc)
*/

void		rewrite_option(int option_index, int last_len, int effects)
{
	t_option	*option;

	(void)last_len;
	option = get_option(option_index);
	if (goto_option(option_index, get_select_data(NULL)))
		return ;
	print_with_effects(option->value, effects);
}
