/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_owner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:07:00 by eterman           #+#    #+#             */
/*   Updated: 2017/01/02 16:26:40 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Returns -1 if it couldn't allocate memory.
*/

int		get_file_owner(t_fileinfo *fileinfo)
{
	char	*str;

	str = getpwuid(fileinfo->stat.st_uid)->pw_name;
	if (str == NULL)
	{
		fileinfo->user = ft_strdup("?");
		if (fileinfo->user == NULL)
			return (-1);
		return (0);
	}
	if ((fileinfo->user = ft_strdup(str)) == NULL)
		return (-1);
	return (0);
}
