/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_is_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:44:36 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 21:15:36 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		file_is_dir(char *path, int follow_link)
{
	t_stat	buff;
	int		(*f)(const char*, t_stat*);

	f = (follow_link) ? &stat : &lstat;
	if (f(path, &buff) == -1)
		return (0);
	return (S_ISDIR(buff.st_mode));
}
