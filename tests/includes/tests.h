/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:15:59 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 13:29:27 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <lexer/lexer.h>
# include <parser/parser.h>
# include <libft.h>
# include <check.h>

t_list			*get_tlst(t_token *tarr, size_t sz);
void			check_io_file(t_ptree *io, enum e_io_type type, char *expected);

/* Test suites */
Suite	*test_suite_here_end();
Suite	*test_suite_filename();
Suite	*test_suite_io_here();
Suite	*test_suite_io_file();
Suite	*test_suite_redirect_list();
Suite	*test_suite_cmd_prefix();
Suite	*test_suite_cmd_suffix();
Suite	*test_suite_io_redirect();

#endif
