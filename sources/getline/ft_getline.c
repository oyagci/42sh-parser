/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:28:20 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 14:55:05 by oyagci           ###   ########.fr       */
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
	*g_line_info.content = 0;
	ft_putchar('\n');
	print_prompt(&g_line_info);
}

int				getline_process_buffer(unsigned int buffer, t_line *l)
{
	int ret;

	if ((ret = process_key(buffer, l)) == -2)
		return (-2);
	line_print(l);
	return (ret);
}

int				ft_getline(char **line)
{
	unsigned int	c;
	int				ret;

	getline_setraw();
	line_init(&g_line_info);
	print_prompt(&g_line_info);
	while (42)
	{
		c = 0;
		if (read(STDIN_FILENO, &c, sizeof(unsigned int)) <= 0)
			return (-1);
		if ((ret = getline_process_buffer(c, &g_line_info)) == 0)
			break ;
		else if (ret == -2)
		{
			free(g_line_info.content);
			g_line_info.content = 0;
			return (-1);
		}
	}
	getline_unsetraw();
	ft_putchar('\n');
	*line = g_line_info.content;
	return (0);
}
