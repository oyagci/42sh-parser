/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:24:00 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/13 10:24:14 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_stradd(char *s1, char *s2)
{
	char *new;

	if (!(new = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	return (new);
}
