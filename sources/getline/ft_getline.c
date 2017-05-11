/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:28:20 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/26 14:52:41 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linehistory/linehistory.h>
#include <getline/getline.h>
#include <environ/environ.h>
#include <getline/key.h>
#include <termcap.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

struct termios	g_tattr_save;
t_line			g_line_info;

void			sigint_reset_line(int signal)
{
	(void)signal;
	ft_strclr(g_line_info.content);
	ft_putchar('\n');
	print_prompt(&g_line_info);
}

int				getline_process_buffer(unsigned char *buffer, t_line *l)
{
	int ret;

	if ((ret = process_key(buffer, l)) == -2)
		return (-2);
	line_print(l);
	return (ret);
}

int				ft_getline(char **line)
{
	unsigned char	buffer[8];
	int				ret;

	getline_setraw();
	line_init(&g_line_info);
	print_prompt(&g_line_info);
	while (42)
	{
		ft_bzero(buffer, sizeof(buffer));
		if (read(STDIN_FILENO, buffer, 8) <= 0)
			return (-1);
		ret = getline_process_buffer(buffer, &g_line_info);
		if (ret == 0)
			break ;
		if (ret == -2)
		{
			ft_strdel(&g_line_info.content);
			return (-1);
		}
	}
	getline_unsetraw();
	ft_putchar('\n');
	*line = g_line_info.content;
	linehist_add(g_line_info.content);
	return (0);
}
