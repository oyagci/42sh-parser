/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_list_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:50:04 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 15:57:47 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			redirect_list_free(t_redirect_list *redirect)
{
	t_list	*next;
	t_ptree	*ptree;

	while (redirect->list)
	{
		next = redirect->list->next;
		ptree = redirect->list->content;
		io_redirect_free(&ptree->content->io_redirect);
		free(ptree->content);
		free(ptree);
		free(redirect->list);
		redirect->list = next;
	}
}
