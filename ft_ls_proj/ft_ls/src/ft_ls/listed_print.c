/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listed_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:09:45 by eterman           #+#    #+#             */
/*   Updated: 2017/01/04 15:41:35 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	listed_print(t_list *file_infos, t_ls_data *ls_data)
{
	t_max_len	max_lens;

	if (file_infos == NULL)
		return ;
	get_max_lenghts(file_infos, &max_lens);
	while (file_infos)
	{
		print_aligned_fileinfo(L_CONTENT(t_fileinfo*, file_infos),
			&max_lens, ls_data);
		file_infos = file_infos->next;
	}
}
