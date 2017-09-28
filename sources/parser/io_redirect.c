/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:51:34 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 13:32:55 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void			free_io_redirect(t_io_redirect **ioredir)
{
	if (!*ioredir || *ioredir == (void*)ERR_SYNTAX)
		return ;
	free_io_file(&(*ioredir)->io_file);
	free_io_here(&(*ioredir)->io_here);
	free(*ioredir);
	*ioredir = NULL;
}

int				get_io_number(t_parser *p, t_io_redirect *ioredir)
{
	if (((t_token *)p->tlst->content)->type == T_IO_NUMBER)
	{
		ioredir->io_number = ft_atoi(((t_token *)p->tlst->content)->data);
		ioredir->is_default = 0;
		p->tlst = p->tlst->next;
	}
	else
		ioredir->is_default = 1;
	return (0);
}

t_io_redirect	*io_redirect(t_parser *p)
{
	t_io_file		*iofile;
	t_io_here		*iohere;
	t_io_redirect	*ioredir;
	t_list			*head;
	int				ionumber;

	ionumber = 0;
	iofile = NULL;
	iohere = NULL;
	if ((ioredir = ft_memalloc(sizeof(t_io_redirect))))
	{
		head = p->tlst;
		get_io_number(p, ioredir);
		if (NULL == (iofile = io_file(p)))
			iohere = io_here(p);
		if (iofile == (void*)ERR_SYNTAX || iohere == (void*)ERR_SYNTAX)
			free_io_redirect(&ioredir);
		else if (iofile == NULL && iohere == NULL)
		{
			free_io_redirect(&ioredir);
			return (NULL);
		}
		else
		{
			ioredir->io_here = iohere;
			ioredir->io_file = iofile;
		}
	}
	return ((iofile == (void*)ERR_SYNTAX)
			|| iohere == (void*)ERR_SYNTAX ? (void *)ERR_SYNTAX : ioredir);
}
