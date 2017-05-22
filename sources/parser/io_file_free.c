/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:42:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 17:22:26 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>
#include <stdio.h>

void			io_file_free(t_io_file *f)
{
	if (f->filename)
	{
		filename_free(&f->filename->content->filename);
		free(f->filename->content);
		free(f->filename);
	}
}
