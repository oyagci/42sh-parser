/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:23:15 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/18 15:13:20 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H

# include <libft.h>

typedef struct	s_environ_var
{
	char		*name;
	char		*value;
}				t_environ_var;

t_list			*environ_get(void);
t_list			*environ_dup();
int				environ_load(void);
void			environ_print(void);
int				environ_add_var(t_environ_var *var);
t_environ_var	*environ_getvar(char *name);
char			*environ_getvalue(char *name);
char			**environ_get_str(void);
void			environ_setvalue(char *name, char *val);
int				environ_remove(char *name);
char			**environ_get_str_custom(t_list *env);

#endif
