/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:31:39 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 22:07:41 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "worker.h"
#include "libft.h"
#include "parser.h"
#include "error.h"
#include "list_utils.h"
#include "list_utils_3.h"

static int		get_index_from_value(t_list *stack, int value)
{
	int			i;

	i = 0;
	while (stack)
	{
		if (get_value(stack) == value)
			return (i);
		++i;
		stack = stack->next;
	}
	return (EXIT_FAIL);
}

static int		index_stack(t_list *stack)
{
	t_list		*stack_dup;

	stack_dup = NULL;
	if (stack && !(stack_dup = ft_lstmap(stack, &lst_elm_cpy, &lst_elm_del)))
		return (E_NULL);
	ft_lstmergesort(&stack_dup, &lst_elm_compare);
	while (stack)
	{
		if ((((t_node *)stack->content)->index = get_index_from_value(stack_dup,
			get_value(stack))) < 0)
		{
			ft_lstdel(&stack_dup, &lst_elm_del);
			return (E_VALUE_NOT_FOUND);
		}
		stack = stack->next;
	}
	ft_lstdel(&stack_dup, &lst_elm_del);
	return (EXIT_OK);
}

static int		check_duplicated_values(t_stacks *stacks)
{
	int			err_no;

	if ((err_no = ft_lsthasdup(&stacks->stack_a, &lst_elm_compare,
					&lst_elm_del)))
		return (E_DUP);
	if (stacks->size_a && (err_no = index_stack(stacks->stack_a)))
		return (err_no);
	return (EXIT_OK);
}

int				check_args(int ac, char **av, t_stacks *stacks)
{
	int			err_no;

	if ((err_no = parse_args_list(ac, av, stacks)))
		return (err_no);
	if ((err_no = check_duplicated_values(stacks)))
		return (err_no);
	return (EXIT_OK);
}
