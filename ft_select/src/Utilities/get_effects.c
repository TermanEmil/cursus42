/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_effects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:18:03 by eterman           #+#    #+#             */
/*   Updated: 2017/02/18 17:18:03 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_effects(int option_index, int is_cursored)
{
	t_option	*option;
	int			effects;

	option = get_option(option_index);
	effects = 0;
	if (is_cursored)
		effects |= UNDERLINE_FLAG;
	if (option->is_selected)
		effects |= SELECT_FLAG;
	return (effects);
}
