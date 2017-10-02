/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 09:25:24 by eterman           #+#    #+#             */
/*   Updated: 2017/05/29 22:20:57 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAP_H
# define FT_TERMCAP_H

# include <termcap.h>
# include <termios.h>
# include "ft_project.h"
# include "libft.h"
# include "ft_errors.h"

# define TERM_MV_LEFT			"le"
# define TERM_MV_RIGT			"nd"
# define TERM_DEL_MODE			"dm"
# define TERM_NO_DEL_MODE		"ed"
# define TERM_DEL_AT_CURSOR		"dc"
# define TERM_INSERT_MODE		"im"
# define TERM_NO_INSERT_MODE	"ei"
# define TERM_INSERT_CHAR		"ic"

# define TERM_CURS_MV_MAX_LEFT	"cr"

# define TERM_SAVE_CURS_POS		"sc"
# define TERM_REST_CURS_POS		"rc"

# define TERM_CLEAR_TO_END_LN	"ce"

typedef struct termios	t_termios;

typedef struct		s_term_data
{
	t_termios		old_term;
}					t_term_data;

t_term_data	*get_term_data(void);
void		setup_terminal(void);
void		ft_tputs(char *attr_name);
void		cursor_goto(int x, int y);
void		cursor_on(int yes);
void		echo_off(void);
void		ft_clear_screen(void);
void		full_screen(int yes);
void		term_restore(void);
int			tputs_putchar(int c);

#endif
