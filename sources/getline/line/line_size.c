/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:41:08 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/29 11:45:44 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

size_t			line_size(void)
{
	struct winsize	w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}
