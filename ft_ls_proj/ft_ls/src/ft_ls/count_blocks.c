/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:03:17 by eterman           #+#    #+#             */
/*   Updated: 2017/01/04 15:29:37 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ull	count_blocks(t_list *files)
{
	t_ull	count;

	count = 0;
	while (files)
	{
		count += FINFO(files)->stat.st_blocks;
		files = files->next;
	}
	return (count);
}
