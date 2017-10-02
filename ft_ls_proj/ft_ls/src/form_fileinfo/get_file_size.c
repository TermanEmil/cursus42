/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:01:34 by eterman           #+#    #+#             */
/*   Updated: 2017/01/02 16:27:34 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** I may need this function to transformi the size from B to MB, etc.
** Form now it's just B.
*/

void	get_file_size(t_fileinfo *fileinfo)
{
	ft_bufitoa(fileinfo->stat.st_size, fileinfo->file_size);
}
