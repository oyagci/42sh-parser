/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:56:51 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/10 16:58:35 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int				builtin_env(char **av);
int				builtin_setenv(char **av);
int				builtin_unsetenv(char **av);
int				builtin_echo(char **av);
int				builtin_exit(char **av);
int				builtin_cd(char **av);

#endif
