/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_follow_link.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:55:54 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 21:16:34 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		should_follow_link(t_ls_data *ls_data)
{
	return (ft_strchr(ls_data->options, 'l') == NULL &&
		ft_strchr(ls_data->options, 'd') == NULL);
}
