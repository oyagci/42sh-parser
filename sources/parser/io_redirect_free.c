/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:38:27 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 15:49:43 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			io_redirect_free(t_io_redirect *redirect)
{
	io_file_free(&redirect->io_file->content->io_file);
	free(redirect->io_file->content);
	free(redirect->io_file);
	io_here_free(&redirect->io_here->content->io_here);
	free(redirect->io_here->content);
	free(redirect->io_here);
}
