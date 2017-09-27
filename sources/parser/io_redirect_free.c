/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:38:27 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/27 12:48:09 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			io_redirect_free(union u_node *content)
{
	(void)content;
	/*
	t_io_redirect	*redirect;

	redirect = &content->io_redirect;
	if (redirect->io_file)
	{
		io_file_free(redirect->io_file->content);
		free(redirect->io_file->content);
		free(redirect->io_file);
	}
	if (redirect->io_here)
	{
		io_here_free(redirect->io_here->content);
		free(redirect->io_here->content);
		free(redirect->io_here);
	}
	*/
}
