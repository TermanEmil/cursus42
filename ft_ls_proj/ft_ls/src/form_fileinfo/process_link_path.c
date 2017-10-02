/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_link_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 18:07:14 by eterman           #+#    #+#             */
/*   Updated: 2017/01/02 18:24:04 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Creates: link_to_libft -> '/home/boss/Documents/A+/ft_ls_proj/testing_libft'
*/

int		process_link_path(t_fileinfo *fileinfo)
{
	if (fileinfo->file_type != 'l' || !S_ISLNK(fileinfo->stat.st_mode))
		return (0);
	fileinfo->link_path = ft_readlink(fileinfo->name, fileinfo->stat.st_size);
	if (fileinfo->link_path == NULL)
		return (-1);
	return (0);
}
