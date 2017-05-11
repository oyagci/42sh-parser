/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:20:58 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/26 13:46:13 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_ENV_H
# define BUILTIN_ENV_H

# include <shell/builtins/builtins.h>
# include <libft.h>

t_list			*get_custom_env(int empty_env, t_list *assignments);
int				env_cmd(t_list *assignments, char *av[], int empty_env);
void			cmd_find_path(char **av);
void			print_env(t_list *assignments, int empty_env);
void			del_env(void *content, size_t content_size);

#endif
