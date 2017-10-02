/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:21:54 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 20:44:24 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	recursive_ls(t_list *file, t_ls_data *ls_data)
{
	char	*f_name;

	f_name = point_to_last(FINFO(file)->name);
	if (ft_strequ(f_name, ".") || ft_strequ(f_name, ".."))
		return ;
	if (file_is_dir(FINFO(file)->name, should_follow_link(ls_data)))
		ft_ls_dir(FINFO(file)->name, ls_data);
}

static void	print_path(char *path, t_ls_data *ls_data)
{
	if (ls_data->should_print_name == 0)
		ls_data->should_print_name = 1;
	else
	{
		if (ls_data->is_the_first)
			ls_data->is_the_first = 0;
		else
			ft_putnewl();
		ft_printf("%s:\n", path);
	}
}

void		ft_ls_dir(char *path, t_ls_data *ls_data)
{
	t_list		*dirs_files;
	t_stat		stat_path;

	errno = 0;
	if (!file_exists(path, &stat_path))
		return ((void)print_file_doesnt_ex(path));
	if (file_is_link(path))
		return ;
	dirs_files = extract_all_from_path(path, ls_data);
	if (dirs_files == NULL && errno != 0)
		return ;
	fileinfo_sort_list(&dirs_files, ls_data);
	print_path(path, ls_data);
	if (ft_strchr(ls_data->options, 'l'))
	{
		ft_printf("total %lld\n", (count_blocks(dirs_files)) / 2);
		listed_print(dirs_files, ls_data);
	}
	else
		simple_print(dirs_files, ls_data);
	if (ft_strchr(ls_data->options, 'R'))
		map_list(dirs_files, ls_data, &recursive_ls);
	ft_lstdel(&dirs_files, &del_fileinfo);
}
