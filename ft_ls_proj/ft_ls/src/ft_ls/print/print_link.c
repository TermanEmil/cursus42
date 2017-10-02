/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:23:17 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 14:41:07 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_link(t_fileinfo *fileinfo, t_ls_data *ls_data)
{
	ft_putstr(" -> ");
	if (!color_is_disabled(ls_data))
		print_color(get_name_color(fileinfo->followed_link));
	ft_printf("%s", fileinfo->link_path);
	if (!color_is_disabled(ls_data))
		ft_printf("{eoc}");
}
