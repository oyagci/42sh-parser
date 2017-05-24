/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_prefix_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:21:55 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 12:34:40 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			cmd_prefix_free_redirections(t_list *redirections)
{
	t_ptree			*ptree;
	t_list			*next;

	while (redirections)
	{
		next = redirections->next;
		ptree = redirections->content;
		io_redirect_free(&ptree->content->io_redirect);
		free(ptree->content);
		free(ptree);
		free(redirections);
		redirections = next;
	}
}

void			cmd_prefix_free_assignements(t_list *assign)
{
	t_list			*next;

	while (assign)
	{
		next = assign->next;
		free(assign->content);
		free(assign);
		assign = next;
	}
}

void			cmd_prefix_free(t_cmd_prefix *prefix)
{
	cmd_prefix_free_redirections(prefix->redirections);
	cmd_prefix_free_assignements(prefix->assignements);
}
