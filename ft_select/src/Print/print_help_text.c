/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 21:41:45 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 23:00:30 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			print_help_text(int fd)
{
	ft_putstr_fd("ft_select help:\n", fd);
	ft_putstr_fd("  del or backspace = delete"
		" element at cursor position\n", fd);
	ft_putstr_fd("  ctr-a = select all. If everything is selected,"
		" unselect all\n", fd);
	ft_putstr_fd("  ctr-f = find mode (ex: *.txt) like in match-nmatch\n", fd);
	ft_putstr_fd("  alt-enter or shift-tab = select matches. Unselect if all"
		" matches are already selected\n", fd);
	ft_putstr_fd("  alt-del or shift-del = delete selected\n", fd);
}
