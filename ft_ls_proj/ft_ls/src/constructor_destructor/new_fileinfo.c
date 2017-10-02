/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fileinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:10:43 by eterman           #+#    #+#             */
/*   Updated: 2017/01/04 15:34:03 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fileinfo	*new_fileinfo(void)
{
	t_fileinfo	*fileinfo;

	fileinfo = (t_fileinfo*)malloc(sizeof(t_fileinfo));
	if (fileinfo == NULL)
		return (NULL);
	init_fileinfo(fileinfo);
	return (fileinfo);
}
