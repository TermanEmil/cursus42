/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 19:28:18 by eterman           #+#    #+#             */
/*   Updated: 2016/12/30 19:48:28 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** will be called at the start
*/

static void	start_ls(t_list *file, t_ls_data *ls_data)
{
	ft_ls_dir(FINFO(file)->name, ls_data);
}

static void	should_print_name_at_beggining(
				t_list *files,
				t_list *dirs,
				t_ls_data *ls_data)
{
	if (files == NULL && ft_lstlen(dirs) == 1 &&
		ft_strchr(ls_data->options, 'R') == NULL)
	{
		ls_data->should_print_name = 0;
	}
	else
		ls_data->should_print_name = 1;
}

static int	extract_ls_data(t_ls_data *ls_data, t_list **files, t_list **dirs)
{
	int		valid_argv[ls_data->argc];

	int_table_assign_value(valid_argv, 0, ls_data->argc);
	if (extract_argv_options(ls_data, valid_argv) == -1)
		return (-1);
	check_files_for_existance(ls_data->argc, ls_data->argv, valid_argv);
	extract_args(valid_argv, ls_data, files, dirs);
	return (0);
}

static void	ft_ls(t_ls_data *ls_data, t_list *files, t_list *dirs)
{
	handle_no_args_case(ls_data, &dirs);
	should_print_name_at_beggining(files, dirs, ls_data);
	if (ft_strchr(ls_data->options, 'd'))
	{
		ft_lstconcat(&files, dirs);
		ft_lstiter(files, &set_name_should_be_modified);
		ft_ls_given_files(files, ls_data);
		ft_lstdel(&files, &del_fileinfo);
	}
	else
	{
		if (files != NULL)
		{
			ft_lstiter(files, &set_name_should_be_modified);
			ft_ls_given_files(files, ls_data);
			ls_data->is_the_first = 0;
			ft_lstdel(&files, &del_fileinfo);
		}
		if (dirs != NULL)
		{
			ft_lstiter(files, &set_name_should_be_modified);
			map_list(dirs, ls_data, &start_ls);
			ft_lstdel(&dirs, &del_fileinfo);
		}
	}
}

int			main(int argc, char **argv)
{
	t_ls_data		*ls_data;
	t_list			*file_arguments;
	t_list			*dir_arguments;

	ls_data = (t_ls_data*)malloc(sizeof(t_ls_data));
	init_ls_data(ls_data, argc, argv);
	if (extract_ls_data(ls_data, &file_arguments, &dir_arguments) == -1)
	{
		free(ls_data);
		ft_lstdel(&dir_arguments, &del_fileinfo);
		ft_lstdel(&file_arguments, &del_fileinfo);
		return (EXIT_FAILURE);
	}
	ft_ls(ls_data, file_arguments, dir_arguments);
	free(ls_data);
	return (EXIT_SUCCESS);
}
