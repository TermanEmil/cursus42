/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ls_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:04:41 by eterman           #+#    #+#             */
/*   Updated: 2017/01/03 14:35:41 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_ls_data(t_ls_data *ls_data, int argc, char **argv)
{
	ft_bzero((void*)(ls_data->options), sizeof(ls_data->options));
	ls_data->argc = argc;
	ls_data->argv = argv;
	ls_data->is_the_first = 1;
}
