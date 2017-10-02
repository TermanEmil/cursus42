/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:02:26 by eterman           #+#    #+#             */
/*   Updated: 2017/01/02 16:30:56 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Just in case ...
*/

void	get_file_time(t_fileinfo *fileinfo)
{
	char	buff[32];
	char	**parts;

	if (fileinfo->time_parts.which_time == TIME_LAST_ACCESS)
		ft_strcpy(buff, ctime(&(fileinfo->stat.st_atime)));
	else if (fileinfo->time_parts.which_time == TIME_LAST_STAT_CHANGE)
		ft_strcpy(buff, ctime(&(fileinfo->stat.st_ctime)));
	else
		ft_strcpy(buff, ctime(&(fileinfo->stat.st_mtime)));
	parts = ft_strsplit(buff, ' ');
	ft_strcpy(fileinfo->time_parts.day, parts[0]);
	ft_strcpy(fileinfo->time_parts.month, parts[1]);
	ft_strcpy(fileinfo->time_parts.nr_day, parts[2]);
	ft_strncpy_nul(fileinfo->time_parts.clock, parts[3], 5);
	*ft_strchrnul(parts[4], '\n') = 0;
	ft_strcpy(fileinfo->time_parts.year, parts[4]);
	ft_free_bidimens(parts);
}
