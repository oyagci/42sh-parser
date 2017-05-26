/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:28:19 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 13:48:50 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			and_or_free(union u_node *content)
{
	t_and_or	*aor;
	t_list		*next;

	aor = &content->and_or;
	while (aor->pipelines)
	{
		next = aor->pipelines->next;
		ptree_free((t_ptree **)&aor->pipelines->content);
		free(aor->pipelines);
		aor->pipelines = next;
	}
}
