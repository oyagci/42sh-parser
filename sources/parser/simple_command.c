/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:51:26 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/17 16:11:59 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <parser/parser.h>

t_ptree			*simple_command_new(void)
{
	t_ptree	*node;

	if ((node = ft_memalloc(sizeof(t_ptree))))
	{
		node->type = NT_SIMPLE_COMMAND;
		if (!(node->content.sp_command = ft_memalloc(sizeof(t_spcommand))))
		{
			del_node(node);
			return (NULL);
		}
	}
	return (node);
}

int				simple_command_add_cmdprefix(t_parser *p, t_ptree *node)
{
	t_list	*elem;
	t_ptree	*cmdprefix;

	if ((cmdprefix = cmd_prefix(p)))
	{
		elem = ft_lstnew(NULL, 0);
		elem->content = cmdprefix;
		ft_lstpush(&node->content.sp_command->prefix, elem);
	}
	return (1);
}

int				simple_command_add_cmdsuffix(t_parser *p, t_ptree *node)
{
	(void)p; (void)node;
	return (0);
}

int				simple_command_add_cmdword(t_parser *p, t_ptree *node)
{
	(void)p; (void)node;
	return (0);
}

int				simple_command_add_cmdname(t_parser *p, t_ptree *node)
{
	(void)p; (void)node;
	return (0);
}

t_ptree			*simple_command(t_parser *p)
{
	t_ptree	*node;

	if ((node = simple_command_new()))
	{
		if (simple_command_add_cmdprefix(p, node))
		{
			while (simple_command_add_cmdword(p, node))
				;
			while (simple_command_add_cmdsuffix(p, node))
				;
		}
		else if (simple_command_add_cmdname(p, node))
		{
			while (simple_command_add_cmdsuffix(p, node))
				;
		}
		else
		{
			del_node(node);
			return (NULL);
		}
	}
	return (node);
}
