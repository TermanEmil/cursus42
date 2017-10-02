/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_type_by_stat.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 15:55:13 by eterman           #+#    #+#             */
/*   Updated: 2017/01/02 16:25:33 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define STAT_ISDOOR(m)		(m & S_IFMT) == 0xd000

/*
** Stands for 'network special file (HP-UX)'
*/

#define STAT_ISNWK(m)		(m & S_IFMT) == 0x9000

char	get_file_type_by_stat(t_stat *buff)
{
	if (S_ISDIR(buff->st_mode))
		return ('d');
	if (S_ISCHR(buff->st_mode))
		return ('c');
	if (S_ISBLK(buff->st_mode))
		return ('b');
	if (S_ISREG(buff->st_mode))
		return ('-');
	if (S_ISFIFO(buff->st_mode))
		return ('p');
	if (S_ISLNK(buff->st_mode))
		return ('l');
	if (S_ISSOCK(buff->st_mode))
		return ('s');
	if (STAT_ISDOOR(buff->st_mode))
		return ('D');
	if (STAT_ISNWK(buff->st_mode))
		return ('n');
	return ('?');
}
