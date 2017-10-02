/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_given_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:40:49 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 16:00:49 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Given some files, lists them.
*/

void	ft_ls_given_files(t_list *files, t_ls_data *ls_data)
{
	fileinfo_sort_list(&files, ls_data);
	if (ft_strchr(ls_data->options, 'l'))
		listed_print(files, ls_data);
	else
		simple_print(files, ls_data);
}
