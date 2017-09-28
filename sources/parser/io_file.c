/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:05:07 by oyagci            #+#    #+#             */
/*   Updated: 2017/09/28 12:13:28 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>
#include <stdlib.h>

void				free_io_file(t_io_file **iofile)
{
	if (!*iofile || *iofile == (void*)ERR_SYNTAX)
		return ;
	free_filename(&(*iofile)->filename);
	free(*iofile);
	*iofile = NULL;
}

enum e_io_type		is_redir_token(enum e_token type)
{
	if (type == T_LESS)
		return (IT_LESS);
	else if (type == T_GREAT)
		return (IT_GREAT);
	else if (type == T_GREATAND)
		return (IT_GREATAND);
	else if (type == T_LESSAND)
		return (IT_LESSAND);
	else if (type == T_DGREAT)
		return (IT_DGREAT);
	return (IT_NONE);
}

t_io_file			*io_file(t_parser *p)
{
	t_io_file		*iofile;
	t_list			*head;
	enum e_io_type	type;

	if ((iofile = ft_memalloc(sizeof(t_io_file))))
	{
		if ((type = is_redir_token(((t_token *)p->tlst->content)->type)) !=
				IT_NONE)
		{
			head = p->tlst;
			p->tlst = p->tlst->next;
			iofile->type = type;
			if (!(iofile->filename = filename(p)))
			{
				free_io_file(&iofile);
				p->tlst = head;
				return ((void *)ERR_SYNTAX);
			}
		}
		else
			free_io_file(&iofile);
	}
	return (iofile);
}
