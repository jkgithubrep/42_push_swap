/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:40:41 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 15:05:45 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_UTILS_H
# define ALGO_UTILS_H

# include "libft.h"
# include "worker.h"

int				get_index_min(t_list *stack);
int				apply_and_save_action(t_stacks *stacks, char *action_name);
int				index_next_value(t_list *stack, int value_ref, int size);
int				index_last_value_under_median(t_list *stack, int median);
int				index_last_value_above_median(t_list *stack, int median);

#endif
