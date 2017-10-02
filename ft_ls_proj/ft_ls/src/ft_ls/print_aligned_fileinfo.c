/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aligned_fileinfo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:11:57 by eterman           #+#    #+#             */
/*   Updated: 2017/01/04 15:40:07 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** I made this function for more flexibility, for different time formats.
*/

static void	print_aligned_time(t_fileinfo *fileinfo, t_ls_data *ls_data)
{
	(void)ls_data;
	ft_printf("%3s %2s %5s ", fileinfo->time_parts.month,
		fileinfo->time_parts.nr_day,
		fileinfo->time_parts.clock_or_year);
}

/*
** print_size and (minor && major)
*/

static void	print_size(
				t_fileinfo *fileinfo,
				t_ls_data *ls_data,
				t_max_len *lens)
{
	(void)ls_data;
	if (fileinfo->major != 0 || fileinfo->minor != 0)
	{
		ft_printf("%*d, %*d ", lens->major, fileinfo->major,
			lens->minor, fileinfo->minor);
	}
	else
		ft_printf("%*s ", lens->size, fileinfo->file_size);
}

void		print_aligned_fileinfo(
				t_fileinfo *fileinfo,
				t_max_len *max_lens,
				t_ls_data *ls_data)
{
	print_type(fileinfo, ls_data);
	ft_printf("%*s ", max_lens->modes, fileinfo->modes);
	ft_printf("%*d ", max_lens->nr_links, fileinfo->stat.st_nlink);
	print_user(fileinfo, ls_data, max_lens);
	print_grp(fileinfo, ls_data, max_lens);
	print_size(fileinfo, ls_data, max_lens);
	print_aligned_time(fileinfo, ls_data);
	print_name(fileinfo, ls_data, 0, 0);
	if (fileinfo->link_path != NULL)
		print_link(fileinfo, ls_data);
	ft_putnewl();
}
