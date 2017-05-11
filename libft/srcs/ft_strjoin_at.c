/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:55:48 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/07 13:18:16 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

/*
** Concatenates two strings at a given position
*/

char			*ft_strjoin_at(char *dst, char *src, unsigned int pos)
{
	char	*begin;
	char	*end;
	char	*tmp;
	char	*new;

	begin = ft_strndup(dst, pos);
	end = ft_strdup(dst + pos);
	tmp = ft_strjoin(begin, src);
	new = ft_strjoin(tmp, end);
	free(tmp);
	free(end);
	free(begin);
	return (new);
}
