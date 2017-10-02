/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_no_args_case.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 21:18:28 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 21:46:38 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** ls -l -R == no_args_were_given
*/

static int	no_args_were_given(t_ls_data *ls_data)
{
	int		i;
	int		count;

	count = 0;
	i = 1;
	while (i < ls_data->argc)
	{
		if (its_option_field(ls_data->argv[i]))
			count++;
		i++;
	}
	return (ls_data->argc - count - 1 == 0);
}

int			handle_no_args_case(t_ls_data *ls_data, t_list **dirs)
{
	t_fileinfo	*tmp;
	t_list		*l_aux;

	if (no_args_were_given(ls_data))
	{
		tmp = new_formed_fileinfo(".", 0);
		if (tmp == NULL)
		{
			print_malloc_err();
			free(ls_data);
			exit(EXIT_FAILURE);
		}
		l_aux = ft_lstnew((void*)tmp, sizeof(t_fileinfo));
		if (l_aux == NULL)
		{
			print_malloc_err();
			free(ls_data);
			exit(EXIT_FAILURE);
		}
		ft_lst_pushback(dirs, l_aux);
		return (1);
	}
	return (0);
}
