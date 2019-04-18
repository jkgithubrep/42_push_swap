/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:43:54 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 11:39:01 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKER_H
# define WORKER_H

# include "libft.h"

# define EXIT_OK    0
# define EXIT_FAIL  -1

enum				e_flags{
	FL_VISU = 0x1,
	FL_ERR = 0x2,
	FL_CHECKER = 0x4,
	FL_PUSH_SWAP = 0x8,
	FL_FAST = 0x10,
	FL_SLOW = 0x20,
	FL_HELP = 0x40
};

typedef struct		s_node{
	int				value;
	int				block;
	int				index;
}					t_node;

typedef struct		s_stacks{
	t_list			*stack_a;
	t_list			*stack_b;
	t_list			*actions;
	int				size_a;
	int				size_b;
	int				nb_elm;
	int				nb_col;
	int				max_digits;
	t_uint			flags;
	char			stack_select;
}					t_stacks;

#endif
