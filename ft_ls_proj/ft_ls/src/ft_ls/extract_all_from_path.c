/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_all_from_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:42:31 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 16:03:51 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	*new_fileinfo_listcell(t_fileinfo *fileinfo)
{
	return (ft_lstnew((void*)fileinfo, sizeof(t_fileinfo)));
}

static t_list	*extract_list_element(
					char *path,
					t_dirent *dirent,
					t_ls_data *ls_data)
{
	t_list		*result;
	char		*file_path;
	t_fileinfo	*fileinfo_aux;

	errno = 0;
	if ((file_path = get_dirent_name(path, dirent->d_name)) == NULL)
		return (NULL);
	if (ft_strchr(ls_data->options, 'a') == NULL &&
		*point_to_last(file_path) == '.')
	{
		free(file_path);
		return (NULL);
	}
	fileinfo_aux = new_formed_fileinfo(file_path, 0);
	free(file_path);
	if (fileinfo_aux == NULL)
		return (NULL);
	if ((result = new_fileinfo_listcell(fileinfo_aux)) == NULL)
	{
		del_fileinfo(fileinfo_aux, 0);
		return (NULL);
	}
	return (result);
}

static t_list	*extract_all_from_dir(char *path, DIR *dir, t_ls_data *ls_data)
{
	t_dirent	*dirent;
	t_list		*result;
	t_list		*aux_element;

	result = NULL;
	while (dir)
	{
		if ((dirent = readdir(dir)) == NULL)
			return (result);
		if ((aux_element = extract_list_element(path, dirent, ls_data)) == NULL)
		{
			if (errno == ENOMEM)
			{
				ft_lstdel(&result, &del_fileinfo);
				return (NULL);
			}
			else
				continue ;
		}
		ft_lst_pushback(&result, aux_element);
	}
	return (result);
}

/*
** Returns a list of fileinfo from a given path.
*/

t_list			*extract_all_from_path(char *path, t_ls_data *ls_data)
{
	DIR			*dir;
	t_list		*result;

	errno = 0;
	if ((dir = opendir(path)) == NULL)
	{
		if (errno == ENOENT)
			ft_fprintf(FT_STDERR, "{red}ls: cannot access '%s': %s\n",
				path, strerror(errno));
		else
		{
			ft_fprintf(FT_STDERR, "{red}ls: cannot open directory '%s': %s\n",
				path, strerror(errno));
		}
		return (NULL);
	}
	result = extract_all_from_dir(path, dir, ls_data);
	closedir(dir);
	if (errno == ENOENT)
		ft_fprintf(FT_STDERR, "{red}ls: cannot access '%s': %s\n",
					path, strerror(errno));
	else if (errno == ENOMEM)
		print_malloc_err();
	return (result);
}
