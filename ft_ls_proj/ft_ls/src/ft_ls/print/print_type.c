/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:19:58 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 14:39:58 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_type(t_fileinfo *fileinfo, t_ls_data *ls_data)
{
	if (!color_is_disabled(ls_data))
		print_color(get_type_color(fileinfo, 0));
	ft_printf("%c", fileinfo->file_type);
	if (!color_is_disabled(ls_data))
		ft_printf("{eoc}");
}
