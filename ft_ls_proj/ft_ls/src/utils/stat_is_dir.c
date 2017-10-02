/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_is_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:14:48 by eterman           #+#    #+#             */
/*   Updated: 2017/01/04 15:32:18 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Checks if a given stat is a directory.
*/

int		stat_is_dir(t_stat *buff)
{
	return (S_ISDIR(buff->st_mode));
}
