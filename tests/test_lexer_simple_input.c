/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer_simple_input.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:02:03 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 16:23:13 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <check.h>

struct s_lexer_test
{
	t_token	*expected_tokens;
};

START_TEST(lexer_empty_input)
{
}
