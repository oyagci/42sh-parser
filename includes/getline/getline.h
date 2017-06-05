/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:29:05 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 12:18:44 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETLINE_H
# define GETLINE_H

# include <string.h>

typedef struct	s_line
{
	size_t			x;
	size_t			y;

	char			*content;
	size_t			index;
	size_t			len;
	size_t			max_len;
}				t_line;

int				ln_putc(char c, t_line *line_info);
int				ln_putstr(char *s, t_line *line_info);
int				ft_getline(char **line);
int				ft_putc(int c);

int				line_addchar(unsigned int buffer, t_line *l);
void			line_autocomplete(t_line *line);
int				line_grow_if_needed(t_line *l);
void			line_goto_begin(t_line *line);
void			line_next_word(t_line *line);
void			line_prev_word(t_line *line);
void			line_del_word(t_line *line);
void			line_goto_end(t_line *end);
void			line_print(t_line *line);
void			line_paste(t_line *line);
int				line_delchar(t_line *l);
void			line_init(t_line *line);
void			line_down(t_line *line);
void			line_copy(t_line *line);
void			line_up(t_line *line);
size_t			line_size(void);

int				process_key(unsigned int buffer, t_line *l);

void			getline_unsetraw(void);
void			getline_setraw(void);

void			print_prompt(t_line *line_info);

void			sigint_reset_line(int signal);

char			*get_current_word(t_line *line);
char			*find_command(char *begin);

#endif
