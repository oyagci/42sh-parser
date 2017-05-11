/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:28:39 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/17 17:28:57 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char					*ft_strcdup(char *str, char c)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i += 1;
	dup = ft_strndup(str, i);
	return (dup);
}
