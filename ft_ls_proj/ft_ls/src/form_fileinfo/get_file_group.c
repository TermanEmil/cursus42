/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 15:59:23 by eterman           #+#    #+#             */
/*   Updated: 2017/01/02 16:27:13 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Returns -1 if it couldn't allocate memory.
*/

int		get_file_group(t_fileinfo *fileinfo)
{
	char	*str;

	str = getgrgid(fileinfo->stat.st_gid)->gr_name;
	if (str == NULL)
	{
		fileinfo->group = ft_strdup("?");
		if (fileinfo->group == NULL)
			return (-1);
		return (0);
	}
	if ((fileinfo->group = ft_strdup(str)) == NULL)
		return (-1);
	return (0);
}
