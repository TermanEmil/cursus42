/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:16:37 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 20:42:17 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	map_list(
			t_list *files,
			t_ls_data *ls_data,
			void (*action)(t_list*, t_ls_data*))
{
	while (files)
	{
		action(files, ls_data);
		files = files->next;
	}
}
