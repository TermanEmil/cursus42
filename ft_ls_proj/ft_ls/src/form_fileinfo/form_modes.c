/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_modes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 15:52:54 by eterman           #+#    #+#             */
/*   Updated: 2017/01/02 16:24:34 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define USR_R_MODE(stat)	(stat->st_mode & S_IRUSR)
#define USR_W_MODE(stat)	(stat->st_mode & S_IWUSR)
#define USR_X_MODE(stat)	(stat->st_mode & S_IXUSR)

/*
** GRP == group
*/

#define GRP_R_MODE(stat)	(stat->st_mode & S_IRGRP)
#define GRP_W_MODE(stat)	(stat->st_mode & S_IWGRP)
#define GRP_X_MODE(stat)	(stat->st_mode & S_IXGRP)

/*
** OTH == other
*/

#define OTH_R_MODE(stat)	(stat->st_mode & S_IROTH)
#define OTH_W_MODE(stat)	(stat->st_mode & S_IWOTH)
#define OTH_X_MODE(stat)	(stat->st_mode & S_IXOTH)

#define USRID_IS_SET(stat)	(stat->st_mode & S_ISUID)
#define GRPID_IS_SET(stat)	(stat->st_mode & S_ISGID)
#define STICKY_BIT_IS_SET(stat)	(stat->st_mode & S_ISVTX)

/*
** I observed that for directories and files, the 'sst' values varies.
*/

void	special_file_perms(t_stat *file_stat, char *str, t_fileinfo *fileinfo)
{
	if (USRID_IS_SET(file_stat))
		str[2] = (S_ISDIR(fileinfo->stat.st_mode)) ? 's' : 'S';
	if (GRPID_IS_SET(file_stat))
		str[5] = (S_ISDIR(fileinfo->stat.st_mode)) ? 's' : 'S';
	if (STICKY_BIT_IS_SET(file_stat))
		str[8] = (S_ISDIR(fileinfo->stat.st_mode)) ? 't' : 'T';
}

char	*form_modes(t_fileinfo *fileinfo)
{
	t_stat	*file_stat;
	char	*str;

	file_stat = &(fileinfo->stat);
	str = fileinfo->modes;
	str[0] = (USR_R_MODE(file_stat)) ? 'r' : '-';
	str[1] = (USR_W_MODE(file_stat)) ? 'w' : '-';
	str[2] = (USR_X_MODE(file_stat)) ? 'x' : '-';
	str[3] = (GRP_R_MODE(file_stat)) ? 'r' : '-';
	str[4] = (GRP_W_MODE(file_stat)) ? 'w' : '-';
	str[5] = (GRP_X_MODE(file_stat)) ? 'x' : '-';
	str[6] = (OTH_R_MODE(file_stat)) ? 'r' : '-';
	str[7] = (OTH_W_MODE(file_stat)) ? 'w' : '-';
	str[8] = (OTH_X_MODE(file_stat)) ? 'x' : '-';
	special_file_perms(file_stat, str, fileinfo);
	str[9] = ' ';
	str[10] = 0;
	return (str);
}
