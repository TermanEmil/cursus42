/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:10:29 by eterman           #+#    #+#             */
/*   Updated: 2017/02/19 21:31:59 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

const t_dex		*get_dex(void)
{
	static const t_dex	dex[20] = {
							{ARROW_UP, &key_cmd_up},
							{ARROW_DOWN, &key_cmd_down},
							{ARROW_LEFT, &key_cmd_left},
							{ARROW_RIGHT, &key_cmd_right},
							{DEL_KEY, &key_cmd_del},
							{"\033", &key_cmd_esc},
							{" ", &key_cmd_space},
							{"\b", &key_cmd_del},
							{BACKSPACE, &key_cmd_bakspace},
							{"\n", &key_cmd_enter},
							{CTRL_A, &key_cmd_ctrl_a},
							{CTR_F, &key_enter_find_mode},
							{ALT_ENTER, &key_cmd_alt_enter},
							{SHIFT_TAB, &key_cmd_alt_enter},
							{ALT_DEL, &delete_selected},
							{SHIFT_DEL, &delete_selected},
							{"\t", &show_help},
							{NULL, NULL}};

	return (dex);
}
