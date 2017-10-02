/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:29:52 by eterman           #+#    #+#             */
/*   Updated: 2017/02/20 16:38:12 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"

t_term_data		*get_term_data(void)
{
	static t_term_data	data;
	static int			was_cleaned = 0;

	if (!was_cleaned)
	{
		ft_bzero(&data, sizeof(t_term_data));
		was_cleaned = 1;
	}
	return (&data);
}
