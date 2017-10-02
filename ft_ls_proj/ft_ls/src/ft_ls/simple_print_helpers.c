/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_print_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:10:23 by eterman           #+#    #+#             */
/*   Updated: 2017/01/08 18:29:33 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	***new_list(int columns, int h)
{
	int		i;
	t_list	***buff;

	buff = (t_list***)malloc(sizeof(t_list**) * h);
	i = 0;
	while (i < h)
		buff[i++] = (t_list**)malloc(sizeof(t_list*) * columns);
	return (buff);
}

t_list	***split_in_n_columns(t_list *files, int columns, int file_count)
{
	int		i;
	int		j;
	int		h;
	t_list	***buff;

	h = file_count / columns + (file_count % columns != 0);
	buff = new_list(columns, h);
	j = 0;
	while (j < columns)
	{
		i = 0;
		while (i < h)
		{
			buff[i][j] = files;
			if (files != NULL)
				files = files->next;
			i++;
		}
		j++;
	}
	return (buff);
}

int		get_terminal_width(void)
{
	struct winsize	w;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) < 0)
		return (0);
	else
		return (w.ws_col);
}

void	set_name_should_be_modified(t_list *file)
{
	FINFO(file)->name_should_be_modified = 0;
}
