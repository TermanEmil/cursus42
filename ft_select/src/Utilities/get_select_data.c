/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_select_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:06:11 by eterman           #+#    #+#             */
/*   Updated: 2017/02/12 17:27:01 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** Since we're not allowed to use globak variables, we can use static vars.
** So here is stored this var. The main reverence of t_select is in main().
*/

t_select	*get_select_data(t_select *new_data)
{
	static t_select	*data;

	if (new_data != NULL)
		data = new_data;
	return (data);
}
