/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_formed_fileinfo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:08:05 by eterman           #+#    #+#             */
/*   Updated: 2017/01/04 15:34:35 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fileinfo	*new_formed_fileinfo(char *path, int follow_link)
{
	t_fileinfo	*result;

	result = new_fileinfo();
	if (result == NULL)
		return (NULL);
	if (form_fileinfo(path, result, follow_link) < 0)
	{
		del_fileinfo((void*)result, sizeof(t_fileinfo));
		return (NULL);
	}
	return (result);
}
