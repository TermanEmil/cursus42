/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_matches.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 20:58:25 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 21:03:36 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		all_matches_are_selected(t_list *options)
{
	while (options)
	{
		if (LCONT(options, t_option*)->matches)
		{
			if (!LCONT(options, t_option*)->is_selected)
				return (0);
		}
		LTONEXT(options);
	}
	return (1);
}

void			select_matches(t_list *options)
{
	int		to_value;

	to_value = !all_matches_are_selected(options);
	while (options)
	{
		if (LCONT(options, t_option*)->matches)
			LCONT(options, t_option*)->is_selected = to_value;
		LTONEXT(options);
	}
}
