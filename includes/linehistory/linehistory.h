/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linehistory.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 14:10:33 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/27 12:17:24 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEHISTORY_H
# define LINEHISTORY_H

# include <getline/getline.h>
# include <string.h>

typedef struct	s_linehist
{
	char	*value;
	size_t	index;
}				t_linehist;

void			linehist_copy_line(t_line *l, t_linehist *histline);
void			linehist_load_prev(t_line *l);
void			linehist_load_next(t_line *l);
t_linehist		*linehist_get_prevline(void);
t_linehist		*linehist_get_nextline(void);
void			linehist_add(char *command);
void			*linehist_reset_index(void);

#endif
