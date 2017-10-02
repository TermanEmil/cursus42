/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_user.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:10:55 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 14:41:55 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_user(t_fileinfo *fileinfo, t_ls_data *ls_data, t_max_len *lns)
{
	if (ft_strchr(ls_data->options, 'g') == NULL)
	{
		if (ft_strequ(fileinfo->user, "root") && !color_is_disabled(ls_data))
			ft_printf("{$}%-*s ", CL_ROOT, lns->user, fileinfo->user);
		else
			ft_printf("%-*s ", lns->user, fileinfo->user);
	}
}
