/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 09:36:07 by eterman           #+#    #+#             */
/*   Updated: 2017/06/22 18:50:06 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

void		ft_err_init_proj_name(char *proj_name);
char		*ft_err_get_proj_name(char *proj_name);
void		ft_err(const char *msg);
void		ft_fatal(const char *msg);
void		ft_err_mem(int exit_program);
int			ft_proj_err(const char *msg, int exit_program);

#endif
