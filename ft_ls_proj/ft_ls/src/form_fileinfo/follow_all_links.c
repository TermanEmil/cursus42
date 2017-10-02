/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_all_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:17:21 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 14:37:51 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fileinfo	*follow_all_links(t_fileinfo *fileinfo)
{
	t_fileinfo	*l_fileinfo;
	t_fileinfo	*result;
	char		*l_name;
	char		*aux;

	l_name = ft_readlink(fileinfo->name, fileinfo->stat.st_size);
	if (l_name == NULL)
		return (NULL);
	aux = get_relative_link_path(l_name, fileinfo->name);
	free(l_name);
	if (aux == NULL)
		return (NULL);
	l_name = aux;
	l_fileinfo = new_formed_fileinfo(l_name, 1);
	free(l_name);
	if (l_fileinfo == NULL)
		return (NULL);
	if (l_fileinfo->file_type == 'l')
	{
		result = follow_all_links(l_fileinfo);
		del_fileinfo((void*)l_fileinfo, sizeof(t_fileinfo));
	}
	else
		result = l_fileinfo;
	return (result);
}
