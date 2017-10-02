/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:14:42 by eterman           #+#    #+#             */
/*   Updated: 2017/01/08 18:37:42 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_name(t_fileinfo *fileinfo)
{
	if (fileinfo->name_should_be_modified)
		return (point_to_last(fileinfo->name));
	else
		return (fileinfo->name);
}
