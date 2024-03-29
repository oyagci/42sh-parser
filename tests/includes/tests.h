/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:15:59 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 17:26:45 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <lexer/lexer.h>
# include <parser/parser.h>
# include <libft.h>
# include <check.h>

t_parser	*prepare_parser(t_token *tarr, size_t sz, t_ptree *(*f)(t_parser *));
t_list		*get_tlst(t_token *tarr, size_t sz);
void		check_io_file(t_ptree *io, enum e_io_type type, char *expected);

Suite		*test_suite_lexer();
Suite		*test_suite_lexer_simple_command();
Suite		*test_suite_command(void);
Suite		*test_suite_here_end();
Suite		*test_suite_filename();
Suite		*test_suite_io_here();
Suite		*test_suite_io_file();
Suite		*test_suite_redirect_list();
Suite		*test_suite_cmd_prefix();
Suite		*test_suite_cmd_suffix();
Suite		*test_suite_io_redirect();
Suite		*test_suite_simple_command(void);

#endif
