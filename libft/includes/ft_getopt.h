/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:38:13 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/09 12:48:31 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

extern char	*g_optarg;
extern int	g_optind;
extern int	g_opterr;
extern int	g_optopt;
extern int	g_optreset;

int		ft_getopt(int argc, char *argv[], char *optstring);

#endif
