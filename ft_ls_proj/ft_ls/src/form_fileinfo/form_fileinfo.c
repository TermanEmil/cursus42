/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_fileinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 19:48:32 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 20:18:12 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_major_min(t_fileinfo *fileinfo)
{
	if (S_ISCHR(fileinfo->stat.st_mode) || S_ISBLK(fileinfo->stat.st_mode))
	{
		fileinfo->major = FT_MAJOR(fileinfo->stat.st_rdev);
		fileinfo->minor = FT_MINOR(fileinfo->stat.st_rdev);
		return (0);
	}
	else
	{
		fileinfo->major = 0;
		fileinfo->minor = 0;
		return (-1);
	}
}

int		link_file(t_fileinfo *fileinfo)
{
	char	*l_name;
	char	*aux;

	if ((l_name = ft_readlink(fileinfo->name, fileinfo->stat.st_size)) == NULL)
		return (-1);
	aux = get_relative_link_path(l_name, fileinfo->name);
	free(l_name);
	if (aux == NULL)
		return (-1);
	ft_strdelif(&(fileinfo->name));
	fileinfo->name = aux;
	return (0);
}

int		stat_fileinfo(t_fileinfo *fileinfo, int link_follow)
{
	if (lstat(fileinfo->name, &(fileinfo->stat)) == -1)
		return (-2);
	if (link_follow && file_is_dir(fileinfo->name, link_follow) &&
		S_ISLNK(fileinfo->stat.st_mode))
	{
		if (link_file(fileinfo) < 0)
			return (-1);
		if (lstat(fileinfo->name, &(fileinfo->stat)) == -1)
			return (-2);
	}
	return (0);
}

void	get_functions(t_fileinfo *fileinfo)
{
	get_major_min(fileinfo);
	get_file_size(fileinfo);
	get_file_time(fileinfo);
}

/*
** Like this (calling lstat first), I check if the given file is a symlink.
** Returns -2 if file_name doesn't exist.
*/

int		form_fileinfo(CHR *file_name, t_fileinfo *fileinfo, int link_follow)
{
	errno = 0;
	fileinfo->name = ft_strdup(file_name);
	if (fileinfo->name == NULL)
		return (print_malloc_err() - 2);
	if (stat_fileinfo(fileinfo, link_follow) < 0)
		return (-2);
	fileinfo->file_type = get_file_type_by_stat(&(fileinfo->stat));
	form_modes(fileinfo);
	errno = 0;
	if (get_file_owner(fileinfo) == -1 || get_file_group(fileinfo) == -1)
	{
		ft_strdelif(&(fileinfo->user));
		ft_strdelif(&(fileinfo->group));
		ft_strdelif(&(fileinfo->name));
		return (print_malloc_err() - 2);
	}
	get_functions(fileinfo);
	process_clock_or_year(fileinfo, time(NULL));
	if (process_link_path(fileinfo) == -1)
		return (-1);
	if (fileinfo->file_type == 'l')
		fileinfo->followed_link = follow_all_links(fileinfo);
	else
		fileinfo->followed_link = NULL;
	return (0);
}
