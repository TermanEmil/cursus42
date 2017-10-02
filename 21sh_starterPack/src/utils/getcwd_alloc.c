/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcwd_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:08:03 by eterman           #+#    #+#             */
/*   Updated: 2017/01/25 15:34:23 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

char	*getcwd_alloc(void)
{
	t_ddata	ddata;

	ft_ddatainit(&ddata, ft_strnew(50), 50, 30);
	while (getcwd((char*)(ddata.content), ddata.size) == NULL)
		if (ft_ddata_sizeadd(&ddata) == NULL)
			ft_error_mem();
	return ((char*)(ddata.content));
}
