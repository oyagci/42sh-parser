/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:58:01 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/08 10:15:10 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>
#include <libft.h>

/*
t_ptree			*io_file(t_token *t)
{
	t_ptree *node;

	if (t->type == TT_LESS)
	{
		if ((node = ptree_new(NT_IO_FILE)))
		{
			if ((node->content.io_file = ft_memalloc(sizeof(t_io_file))))
			{
			}
			else
				free(node);
		}
	}
	return (NULL);
}

t_ptree			*filename(t_token *t)
{
	t_ptree	*node;

	if (t->type == TT_WORD)
	{
		if (!(node = ft_memalloc(sizeof(t_ptree))))
			return (NULL);
		node->type = NT_FILENAME;
		if (!(node->content.cmd_name = ft_memalloc(sizeof(t_filename))))
		{
			free(node);
			return (NULL);
		}
		if (!(node->content.cmd_name->data = ft_strdup(t->data)))
		{
			free(node->content.cmd_name);
			free(node);
			return (NULL);
		}
		return (node);
	}
	return (NULL);
}

t_ptree			*cmd_name(t_token *t)
{
	t_ptree	*node;

	if (t->type == TT_WORD)
	{
		if (!(node = ft_memalloc(sizeof(t_ptree))))
			return (NULL);
		node->type = NT_CMD_NAME;
		if (!(node->content.cmd_name = ft_memalloc(sizeof(t_cmd_name))))
		{
			free(node);
			return (NULL);
		}
		if (!(node->content.cmd_name->data = ft_strdup(t->data)))
		{
			free(node->content.cmd_name);
			free(node);
			return (NULL);
		}
		return (node);
	}
	return (NULL);
}
*/
