/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_lenghts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:48:49 by eterman           #+#    #+#             */
/*   Updated: 2017/01/05 15:20:19 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define CHNG_IF_BIGGER(field) if (max->field < tmp.field) max->field = tmp.field

static void	set_max_lengths(t_list *src, t_max_len *buff)
{
	t_fileinfo	*fileinfo;

	fileinfo = FINFO(src);
	buff->modes = ft_strlen(fileinfo->modes);
	buff->nr_links = log_ten(fileinfo->stat.st_nlink);
	buff->user = ft_strlen(fileinfo->user);
	buff->group = ft_strlen(fileinfo->group);
	if (fileinfo->major != 0 || fileinfo->minor != 0)
	{
		buff->major = log_ten(fileinfo->major);
		buff->minor = log_ten(fileinfo->minor);
		buff->size = 0;
	}
	else
	{
		buff->major = 0;
		buff->minor = 0;
		buff->size = ft_strlen(fileinfo->file_size);
	}
}

void		get_max_lenghts(t_list *file_infos, t_max_len *max)
{
	t_list				*aux;
	t_max_len			tmp;

	set_max_lengths(file_infos, max);
	aux = file_infos->next;
	while (aux)
	{
		set_max_lengths(aux, &tmp);
		CHNG_IF_BIGGER(modes);
		CHNG_IF_BIGGER(nr_links);
		CHNG_IF_BIGGER(user);
		CHNG_IF_BIGGER(group);
		CHNG_IF_BIGGER(major);
		CHNG_IF_BIGGER(minor);
		CHNG_IF_BIGGER(size);
		aux = aux->next;
	}
	if (max->major + max->minor + 2 > max->size)
		max->size = max->major + max->minor + 2;
	else
		max->major = max->size - 2 - max->minor;
}
