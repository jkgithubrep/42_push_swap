/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:08:16 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/06 17:57:48 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "worker.h"

typedef struct		s_actions{
	char			*name;
	void			(*f)();
}					t_actions;

typedef void		(*t_fptr)();

t_fptr				get_action(char *line, int ret);
int					get_actions_from_stdin(t_stacks *stacks);
void				print_actions_list(t_list **actions);

#endif
