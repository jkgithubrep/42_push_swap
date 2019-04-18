/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:16:35 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 15:00:59 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_2_H
# define ALGO_2_H

# include "worker.h"
# include "libft.h"

int		split_stack_a(t_stacks *stacks);
int		reorder_stack(t_stacks *stacks, t_list *stack);
int		get_best_move(t_stacks *stacks, t_list *stack_b, int *i_next);

#endif
