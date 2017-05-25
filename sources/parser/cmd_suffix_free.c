/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_suffix_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:05:15 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 12:35:43 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			cmd_suffix_free_words(t_list *lst)
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		free(lst->content);
		free(lst);
		lst = next;
	}
}

void			cmd_suffix_free_redirections(t_list *redirections)
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

void			cmd_suffix_free(t_cmd_suffix *suffix)
{
	if (suffix == (void *)ERR_SYNTAX)
		return ;
	cmd_suffix_free_words(suffix->words);
	cmd_suffix_free_redirections(suffix->redirections);
}
