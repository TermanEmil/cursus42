/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:01:25 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 14:32:25 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		is_orphan_link(t_fileinfo *fileinfo)
{
	return (fileinfo->followed_link == NULL || !ft_file_exists(fileinfo->name));
}

char			*get_type_color(t_fileinfo *fileinfo, int can_be_orphan)
{
	char	*clr;

	if (fileinfo == NULL)
		return (clr = CL_UNDEF_FILE);
	clr = CL_NOCL;
	if (fileinfo->file_type == 'd')
		clr = CL_DIR;
	else if (fileinfo->file_type == 'l')
		clr = (is_orphan_link(fileinfo) && can_be_orphan) ?
			CL_ORPHAN_LINK : CL_SYMLINK;
	else if (fileinfo->file_type == 'p')
		clr = CL_PIPE;
	else if (fileinfo->file_type == 's')
		clr = CL_SOCKET;
	else if (fileinfo->file_type == 'b')
		clr = CL_BLKDEVICE;
	else if (fileinfo->file_type == 'c')
		clr = CL_CHRDEVICE;
	else if (fileinfo->file_type == '?')
		clr = CL_UNDEF_FILE;
	else if (fileinfo->file_type == 'D')
		clr = CL_DOOR;
	return (clr);
}
