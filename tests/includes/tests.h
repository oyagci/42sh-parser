/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:15:59 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 10:18:34 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <lexer/lexer.h>
# include <libft.h>
# include <check.h>

t_list			*get_tlst(t_token *tarr, size_t sz);

/* Test suites */
Suite	*test_suite_here_end();
Suite	*test_suite_filename();
Suite	*test_suite_io_here();
Suite	*test_suite_io_file();

#endif
