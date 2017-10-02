/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:12:13 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 14:33:03 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_mode_colors(t_fileinfo *fileinfo)
{
	if (ft_tolower(fileinfo->modes[8]) == 't')
		return (CL_STICKY);
	if (ft_tolower(fileinfo->modes[5]) == 's')
		return (CL_SETGID);
	if (ft_tolower(fileinfo->modes[2]) == 's')
		return (CL_SETUID);
	return (NULL);
}
