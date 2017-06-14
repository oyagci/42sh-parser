/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:19:20 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 14:21:22 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			term_free(union u_node *content)
{
	t_list	*next;
	t_list	*head;

	head = content->term.andlst;
	while (head)
	{
		next = head->next;
		ptree_free((t_ptree **)&head->content);
		free(head);
		head = next;
	}
}
