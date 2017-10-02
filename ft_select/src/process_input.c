/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:20:42 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 23:07:13 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int			dex_key_cmp(void *key1, void *key2)
{
	return (ft_strequ((char*)key1, (char*)key2));
}

static const void	*dex_array_getval(void *key, int (*cmp)(void*, void*))
{
	const t_dex		*dex;

	dex = get_dex();
	while (dex[0].key != NULL || dex[0].value != NULL)
	{
		if (cmp(key, (*dex).key))
			return ((*dex).value);
		dex++;
	}
	return (NULL);
}

int					process_input(t_select *data)
{
	char		buff[10];
	const void	*val;

	ft_bzero(buff, sizeof(buff));
	if (read(STDIN, buff, 10) < 0)
		ft_proj_err("can't read from stdin", 1);
	if ((val = dex_array_getval(buff, &dex_key_cmp)))
	{
		if (CAST(val, t_key_cmd*)(data))
			return (1);
	}
	else if (data->is_in_find_mode)
	{
		if (ft_strlen(buff) == 1)
			add_char_to_find_input(data, buff[0]);
	}
	return (0);
}
