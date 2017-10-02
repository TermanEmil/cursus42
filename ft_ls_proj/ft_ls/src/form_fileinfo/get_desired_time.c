/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_desired_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:26:01 by eterman           #+#    #+#             */
/*   Updated: 2017/01/03 17:53:31 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ull			get_desired_time(t_fileinfo *fileinfo)
{
	if (fileinfo->time_parts.which_time == TIME_LAST_ACCESS)
		return ((t_ull)(fileinfo->stat.st_atime));
	if (fileinfo->time_parts.which_time == TIME_LAST_STAT_CHANGE)
		return ((t_ull)(fileinfo->stat.st_ctime));
	return ((t_ull)(fileinfo->stat.st_mtime));
}
