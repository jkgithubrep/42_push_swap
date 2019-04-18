/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:16:04 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/05 14:48:49 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include "worker.h"
#include "libft.h"

static void		swap(t_list **stack)
{
	t_list		*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void			sa(t_stacks *stacks)
{
	swap(&stacks->stack_a);
}

void			sb(t_stacks *stacks)
{
	swap(&stacks->stack_b);
}

void			ss(t_stacks *stacks)
{
	swap(&stacks->stack_a);
	swap(&stacks->stack_b);
}
