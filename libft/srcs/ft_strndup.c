/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:02:00 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/07 13:14:15 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(char *str, int n)
{
	char *dup;

	dup = ft_strnew(n);
	ft_strncpy(dup, str, n);
	return (dup);
}
