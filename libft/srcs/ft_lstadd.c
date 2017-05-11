/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:21:46 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/30 16:06:21 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *save;

	if (*alst)
	{
		save = *alst;
		*alst = new;
		new->next = save;
	}
	else
	{
		*alst = new;
	}
}
