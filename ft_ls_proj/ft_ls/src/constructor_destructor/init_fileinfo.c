/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fileinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 11:39:30 by eterman           #+#    #+#             */
/*   Updated: 2017/01/03 12:12:30 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_fileinfo(t_fileinfo *fileinfo)
{
	fileinfo->name = NULL;
	fileinfo->file_type = 0;
	fileinfo->modes[0] = 0;
	fileinfo->file_size[0] = 0;
	fileinfo->group = NULL;
	fileinfo->user = NULL;
	fileinfo->link_path = NULL;
	fileinfo->color_on = 1;
	fileinfo->followed_link = NULL;
	fileinfo->time_parts.which_time = TIME_LAST_MODIF;
	fileinfo->name_should_be_modified = 1;
}
