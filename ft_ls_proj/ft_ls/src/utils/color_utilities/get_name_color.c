/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 14:08:57 by eterman           #+#    #+#             */
/*   Updated: 2017/01/07 14:35:37 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		terminates_with(t_fileinfo *fileinfo, char *str)
{
	char	*addr;

	if (fileinfo == NULL)
		return (0);
	addr = ft_strstr(fileinfo->name, str);
	return (addr != NULL && ft_strlen(addr) == ft_strlen(str));
}

static int		is_executable_file(t_fileinfo *fileinfo)
{
	return (fileinfo->file_type == '-' && ft_strchr(fileinfo->modes, 'x'));
}

static char		*get_special_name_color(t_fileinfo *fileinfo)
{
	char	*clr;

	if (fileinfo == NULL && fileinfo->file_type == '-')
		return (get_type_color(fileinfo, 0));
	if (terminates_with(fileinfo, ".c"))
		clr = CL_C_FILE;
	else if (terminates_with(fileinfo, ".o"))
		clr = CL_O_FILE;
	else if (terminates_with(fileinfo, ".h"))
		clr = CL_H_FILE;
	else if (terminates_with(fileinfo, "Makefile"))
		clr = CL_MAKEFILE;
	else if (is_executable_file(fileinfo))
		clr = CL_EXECUTABLE;
	else
		clr = NULL;
	return (clr);
}

char			*get_name_color(t_fileinfo *fileinfo)
{
	char	*clr;

	clr = NULL;
	if (fileinfo != NULL)
	{
		clr = get_mode_colors(fileinfo);
		if (clr == NULL)
			clr = get_special_name_color(fileinfo);
	}
	if (clr == NULL)
		clr = get_type_color(fileinfo, 1);
	return (clr);
}
