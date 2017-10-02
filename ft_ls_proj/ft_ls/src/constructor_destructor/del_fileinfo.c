/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_fileinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:18:34 by eterman           #+#    #+#             */
/*   Updated: 2017/01/04 15:44:54 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	del_fileinfo(void *content, size_t size)
{
	t_fileinfo *fileinfo;

	(void)size;
	fileinfo = (t_fileinfo*)content;
	if (fileinfo != NULL)
	{
		ft_strdelif(&(fileinfo->name));
		ft_strdelif(&(fileinfo->user));
		ft_strdelif(&(fileinfo->group));
		ft_strdelif(&(fileinfo->link_path));
		if (fileinfo->followed_link != NULL)
			del_fileinfo((void*)(fileinfo->followed_link), sizeof(t_fileinfo));
		free(fileinfo);
	}
}
