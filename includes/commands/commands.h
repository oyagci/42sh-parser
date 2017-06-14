/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:59:08 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/07 16:17:21 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include <parser/parser.h>
# include <termios.h>

typedef struct	s_process
{
	struct s_process	*next;
	char				**argv;
	char				completed;
	char				stopped;
	int					status;
}				t_process;

typedef struct	s_job
{
	struct s_process	*first_process;
	struct termios		tmodes;
	int					in;
	int					out;
	int					err;
}				t_job;

typedef struct	s_termcommand
{
	char	*path;
	char	**av;
}				t_termcommand;

int				cmds_exec(t_ptree *ptree);
int				cmds_exec_and_or(t_ptree *andor);
int				cmds_exec_pipeline(t_ptree *pline);
t_process		*cmds_exec_pipe_sequence(t_ptree *pseq);
t_process		*cmds_exec_command(t_ptree *cmd);
t_process		*cmds_simple_command_get_process(t_ptree *spcmd);
int				cmds_exec_compound_command(t_ptree *cpcmd);
void			launch_process(t_process *p, int in, int out, int err);
void			perform_job(t_job *j);
int				execve_pipeline(t_process *p);
int				bin_exists(char *path);
int				cmds_exec_single_command(t_process *p);
int				check_if_signal(int ret);
int				run_builtin(char **argv);
int				find_path(char **name);
int				is_builtin(char *name);

#endif
