/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:17:22 by eterman           #+#    #+#             */
/*   Updated: 2017/02/18 17:18:24 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_option		*get_option(int option_index)
{
	t_list		*option;

	option = ft_lstget(get_select_data(NULL)->options, option_index);
	if (option == NULL)
		ft_proj_err("internal error: invalid index in options", 1);
	return (LCONT(option, t_option*));
}
