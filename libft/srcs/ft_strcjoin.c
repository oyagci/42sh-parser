/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:26:39 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/20 14:28:06 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strcjoin(const char *str, char c)
{
	char	*tmp;
	size_t	len;

	tmp = NULL;
	len = ft_strlen(str);
	if ((tmp = ft_strnew(len + 1)) != NULL)
	{
		ft_strcpy(tmp, str);
		tmp[len] = c;
	}
	return (tmp);
}
