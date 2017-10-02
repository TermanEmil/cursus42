/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_for_existance.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:54:00 by eterman           #+#    #+#             */
/*   Updated: 2017/01/06 21:21:10 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_files_for_existance(int argc, char **argv, int *valid_argv)
{
	int			i;

	i = 1;
	while (i < argc)
	{
		errno = 0;
		if (valid_argv[i] && !ft_file_exists(argv[i]))
		{
			valid_argv[i] = 0;
			print_file_doesnt_ex(argv[i]);
		}
		i++;
	}
}
