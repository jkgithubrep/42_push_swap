/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:55:30 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 15:16:27 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insertion_sort.h"
#include "worker.h"
#include "libft.h"
#include "error.h"
#include "algo_utils.h"

static int		handle_first_part_rev_rot(t_stacks *stacks, int i_best,
					int i_next)
{
	int			i;

	i = 0;
	while (i++ < stacks->size_a - i_next)
		if (apply_and_save_action(stacks, "rra"))
			return (E_NULL);
	i = 0;
	while (i++ < i_best - 1)
		if (apply_and_save_action(stacks, "rb"))
			return (E_NULL);
	if (i_best > 0)
		if (apply_and_save_action(stacks, "sb"))
			return (E_NULL);
	if (apply_and_save_action(stacks, "pa"))
		return (E_NULL);
	return (EXIT_OK);
}

static int		handle_first_part_rot(t_stacks *stacks, int i_best, int i_next)
{
	int			i;

	i = -1;
	while (++i < ft_min(i_next - 1, i_best - 1))
		if (apply_and_save_action(stacks, "rr"))
			return (E_NULL);
	while (i < i_next - 1)
	{
		if (apply_and_save_action(stacks, "ra"))
			return (E_NULL);
		i++;
	}
	while (i++ < i_best - 1)
		if (apply_and_save_action(stacks, "rb"))
			return (E_NULL);
	if (i_best > 0)
		if (apply_and_save_action(stacks, "sb"))
			return (E_NULL);
	if (apply_and_save_action(stacks, "pa"))
		return (E_NULL);
	if (i_next > 0)
		if (apply_and_save_action(stacks, "sa"))
			return (E_NULL);
	return (EXIT_OK);
}

int				handle_first_part(t_stacks *stacks, int i_best, int i_next)
{
	if (stacks->size_a - i_next < ft_max(i_next - i_best, 0))
	{
		if (handle_first_part_rev_rot(stacks, i_best, i_next))
			return (E_NULL);
	}
	else if (handle_first_part_rot(stacks, i_best, i_next))
		return (E_NULL);
	return (EXIT_OK);
}

static int		handle_seconde_part_rev_rot(t_stacks *stacks, int i_best,
					int i_next)
{
	int			i;

	i = 0;
	while (i < ft_min(stacks->size_a - i_next,
				stacks->size_b - i_best))
	{
		if (apply_and_save_action(stacks, "rrr"))
			return (E_NULL);
		i++;
	}
	while (i < (stacks->size_a - i_next))
	{
		if (apply_and_save_action(stacks, "rra"))
			return (E_NULL);
		i++;
	}
	while (i < (stacks->size_b - i_best))
	{
		if (apply_and_save_action(stacks, "rrb"))
			return (E_NULL);
		i++;
	}
	return (EXIT_OK);
}

int				handle_second_part(t_stacks *stacks, int i_best, int i_next)
{
	int			i;

	i = 0;
	if (i_next < ft_max((stacks->size_a - i_next)
				- (stacks->size_b - i_best), 0))
	{
		while (i++ < i_next)
			if (apply_and_save_action(stacks, "ra"))
				return (E_NULL);
		i = 0;
		while (i++ < (stacks->size_b - i_best))
			if (apply_and_save_action(stacks, "rrb"))
				return (E_NULL);
	}
	else if (handle_seconde_part_rev_rot(stacks, i_best, i_next))
		return (E_NULL);
	if (apply_and_save_action(stacks, "pa"))
		return (E_NULL);
	return (EXIT_OK);
}
