/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_select_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:29:23 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 16:53:26 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_list	*new_option_cell(char *arg)
{
	t_list		*result;
	t_option	tmp_option;

	tmp_option.value = arg;
	tmp_option.is_selected = 0;
	if ((result = ft_lstnew(&tmp_option, sizeof(t_option))) == NULL)
		ft_err_mem(1);
	return (result);
}

static t_list	*create_options(int argc, char **argv)
{
	int			i;
	t_list		*result;

	result = NULL;
	i = 1;
	while (i < argc)
	{
		ft_lstadd(&result, new_option_cell(argv[i]));
		i++;
	}
	return (result);
}

void			init_select_data(t_select *data, int argc, char **argv)
{
	data->options = create_options(argc, argv);
	get_select_data(data);
}
