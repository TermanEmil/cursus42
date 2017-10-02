/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:50:18 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 21:23:18 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*get_list_fileinfo_cell(int follow_link, char *argv)
{
	t_fileinfo	*tmp;
	t_list		*result;

	tmp = new_formed_fileinfo(argv, follow_link);
	if (tmp == NULL)
		return (NULL);
	result = ft_lstnew((void*)tmp, sizeof(t_fileinfo));
	if (result == NULL)
	{
		del_fileinfo((void*)tmp, sizeof(t_fileinfo));
		return (NULL);
	}
	return (result);
}

void			extract_args(
					int *valid_argv,
					t_ls_data *ls_data,
					t_list **files,
					t_list **dirs)
{
	int			i;
	t_list		*l_aux;
	int			follow_link;

	*files = NULL;
	*dirs = NULL;
	i = 1;
	follow_link = should_follow_link(ls_data);
	while (i < ls_data->argc)
	{
		if (valid_argv[i])
		{
			l_aux = get_list_fileinfo_cell(follow_link, ls_data->argv[i]);
			if (l_aux == NULL)
			{
				print_malloc_err();
				return ;
			}
			if (file_is_dir(ls_data->argv[i], follow_link))
				ft_lst_pushback(dirs, l_aux);
			else
				ft_lst_pushback(files, l_aux);
		}
		i++;
	}
}
