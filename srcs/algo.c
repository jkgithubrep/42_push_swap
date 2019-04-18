/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:00:25 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 17:35:09 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "algo_2.h"
#include "error.h"
#include "algo_utils.h"
#include "insertion_sort.h"
#include "list_utils.h"
#include "list_utils_2.h"
#include "list_utils_3.h"
#include "print_utils.h"
#include <stdlib.h>

static int		insert_value(t_stacks *stacks, int i_best, int i_next)
{
	if (i_best < (stacks->size_b - i_best))
	{
		if (handle_first_part(stacks, i_best, i_next))
			return (E_NULL);
	}
	else
	{
		if (handle_second_part(stacks, i_best, i_next))
			return (E_NULL);
	}
	return (EXIT_OK);
}

static int		insertion_sort(t_stacks *stacks)
{
	int			i_best;
	int			i_next;

	while (stacks->size_b)
	{
		i_best = get_best_move(stacks, stacks->stack_b, &i_next);
		if (insert_value(stacks, i_best, i_next))
			return (E_NULL);
	}
	return (EXIT_OK);
}

static int		sort_under_3_elm(t_stacks *stacks)
{
	int			a;
	int			b;
	int			c;

	if (stacks->size_a == 2)
		return (apply_and_save_action(stacks, "sa"));
	a = get_value(stacks->stack_a);
	b = get_value(stacks->stack_a->next);
	c = get_value(stacks->stack_a->next->next);
	if ((a < b) && (b > c))
		if (apply_and_save_action(stacks, "rra"))
			return (E_NULL);
	if ((a > b) && (a > c))
	{
		if (apply_and_save_action(stacks, "ra"))
			return (E_NULL);
		if (b > c)
			return (apply_and_save_action(stacks, "sa"));
	}
	if (a < c)
		return (apply_and_save_action(stacks, "sa"));
	return (EXIT_SUCCESS);
}

static int		sort_under_5_elm(t_stacks *stacks)
{
	while (stacks->size_a > 3)
		if (apply_and_save_action(stacks, "pb"))
			return (E_NULL);
	if (!ft_lstissorted(stacks->stack_a, &lst_elm_ordered)
			&& sort_under_3_elm(stacks))
		return (E_NULL);
	if (insertion_sort(stacks))
		return (E_NULL);
	if (reorder_stack(stacks, stacks->stack_a))
		return (E_NULL);
	return (EXIT_SUCCESS);
}

int				algo(t_stacks *stacks)
{
	int			err_no;

	if (stacks->size_a < 6)
		return (sort_under_5_elm(stacks));
	while (!ft_lstissorted(stacks->stack_a, &lst_elm_ordered))
		if ((err_no = split_stack_a(stacks)))
			return (err_no);
	if (insertion_sort(stacks))
		return (E_NULL);
	if (reorder_stack(stacks, stacks->stack_a))
		return (E_NULL);
	return (EXIT_SUCCESS);
}
