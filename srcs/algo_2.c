/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:17:43 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 17:19:34 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_2.h"
#include "libft.h"
#include "list_utils.h"
#include "list_utils_2.h"
#include "list_utils_3.h"
#include "error.h"
#include "algo_utils.h"
#include "print_utils.h"
#include <stdlib.h>

static int	get_nb_moves(t_stacks *stacks, t_list *stack, int i, int *j)
{
	int		nb_moves;

	if (get_index(stack) == stacks->nb_elm - 1)
		*j = get_index_min(stacks->stack_a);
	else
		*j = index_next_value(stacks->stack_a, get_value(stack),
								stacks->size_a);
	nb_moves = ft_min(i, stacks->size_b - i);
	if (i < (stacks->size_b - i))
		nb_moves += ft_min(ft_max(*j - i, 0), stacks->size_a - *j);
	else
		nb_moves += ft_min(ft_max((stacks->size_a - *j)
					- (stacks->size_b - i), 0), *j);
	return (nb_moves);
}

int			get_best_move(t_stacks *stacks, t_list *stack_b, int *i_next)
{
	int		i;
	int		j;
	int		i_best;
	int		min_dist;
	int		nb_moves;

	i = 0;
	min_dist = stacks->nb_elm;
	i_best = stacks->nb_elm;
	while (stack_b)
	{
		nb_moves = get_nb_moves(stacks, stack_b, i, &j);
		if (nb_moves < min_dist)
		{
			min_dist = nb_moves;
			i_best = i;
			*i_next = j;
		}
		stack_b = stack_b->next;
		++i;
	}
	return (i_best);
}

int			reorder_stack(t_stacks *stacks, t_list *stack)
{
	int		index_min;
	int		i;

	index_min = get_index_min(stack);
	i = 0;
	if (index_min < stacks->size_a - index_min)
	{
		while (i++ < index_min)
			if (apply_and_save_action(stacks, "ra"))
				return (E_NULL);
	}
	else
	{
		while (i++ < stacks->size_a - index_min)
			if (apply_and_save_action(stacks, "rra"))
				return (E_NULL);
	}
	return (EXIT_OK);
}

static int	update_stacks_state(t_stacks *stacks, int pivot)
{
	int		median_b;

	median_b = 0;
	if (get_value(stacks->stack_a) < pivot)
	{
		if (stacks->size_b)
		{
			if (ft_lstmedian(stacks->stack_b, &get_value, &median_b))
				return (E_NULL);
			if (get_value(stacks->stack_b) < median_b)
				if (apply_and_save_action(stacks, "rb"))
					return (E_NULL);
		}
		if (apply_and_save_action(stacks, "pb"))
			return (E_NULL);
	}
	else if (apply_and_save_action(stacks, "ra"))
		return (E_NULL);
	return (EXIT_SUCCESS);
}

int			split_stack_a(t_stacks *stacks)
{
	t_list	*stack;
	int		pivot;
	int		index_last;
	int		i;

	pivot = 0;
	stack = stacks->stack_a;
	if (ft_lstmedian(stack, &get_value, &pivot))
		return (E_NULL);
	index_last = index_last_value_under_median(stack, pivot);
	i = -1;
	while (++i <= index_last)
		if (update_stacks_state(stacks, pivot))
			return (E_NULL);
	return (EXIT_SUCCESS);
}
