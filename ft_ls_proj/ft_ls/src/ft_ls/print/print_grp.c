/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:09:25 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 14:42:25 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_grp(t_fileinfo *fileinfo, t_ls_data *ls_data, t_max_len *lns)
{
	if (ft_strchr(ls_data->options, 'G') == NULL)
	{
		if (ft_strequ(fileinfo->group, "root") && !color_is_disabled(ls_data))
			ft_printf("{$}%-*s ", CL_ROOT, lns->group, fileinfo->group);
		else
			ft_printf("%-*s ", lns->group, fileinfo->group);
	}
}
