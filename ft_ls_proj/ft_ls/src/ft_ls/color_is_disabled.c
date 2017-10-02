/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_is_disabled.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:30:52 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 17:55:12 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		color_is_disabled(t_ls_data *ls_data)
{
	return (ft_strchr(ls_data->options, 'U') ||
		ft_strchr(ls_data->options, 'e'));
}
