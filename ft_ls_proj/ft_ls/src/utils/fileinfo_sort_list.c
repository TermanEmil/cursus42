/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_sort_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:29:42 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 15:59:22 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	change_desired_time_to_access(t_list *cell)
{
	FINFO(cell)->time_parts.which_time = TIME_LAST_ACCESS;
}

void	change_desired_time_to_modif(t_list *cell)
{
	FINFO(cell)->time_parts.which_time = TIME_LAST_MODIF;
}

void	update_time(t_list *cell)
{
	get_file_time(FINFO(cell));
	process_clock_or_year(FINFO(cell), time(NULL));
}

void	sort_list(t_list **files, t_ls_data *ls_data, int (*f)(void*, void*))
{
	if (ft_strchr(ls_data->options, 'U') == NULL)
		ft_lst_merge_sort(files, f);
}

void	fileinfo_sort_list(t_list **files, t_ls_data *ls_data)
{
	if (ft_strchr(ls_data->options, 'u'))
	{
		ft_lstiter(*files, &change_desired_time_to_access);
		if (ft_strchr(ls_data->options, 'l'))
			ft_lstiter(*files, &update_time);
		if (!(ft_strchr(ls_data->options, 'l') &&
			ft_strchr(ls_data->options, 't') == NULL))
			sort_list(files, ls_data, &fileinfo_time_compare);
	}
	else if (ft_strchr(ls_data->options, 't'))
	{
		if (ft_strchr(ls_data->options, 'u'))
		{
			sort_list(files, ls_data, &fileinfo_time_compare);
			ft_lstiter(*files, &change_desired_time_to_modif);
		}
		else
			sort_list(files, ls_data, &fileinfo_time_compare);
	}
	else
		sort_list(files, ls_data, &fileinfo_name_compare);
	if (ft_strchr(ls_data->options, 'r') && !ft_strchr(ls_data->options, 'U'))
		ft_lstreverse(files);
}
