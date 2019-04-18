/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:01:45 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 17:08:06 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "worker.h"
#include "libft.h"
#include "error.h"
#include "print_utils.h"
#include "list_utils.h"
#include "list_utils_3.h"
#include "list_utils_2.h"
#include "input.h"
#include "utils.h"
#include "algo.h"
#include "algo_utils.h"
#include "actions.h"

int		main(int ac, char **av)
{
	int			err_no;
	t_stacks	stacks;

	if (ac < 2)
		return (-1);
	stacks = (t_stacks){NULL, NULL, NULL, 0, 0, 0, 0, 0, 0u, 0};
	stacks.flags |= FL_PUSH_SWAP;
	if ((err_no = check_args(ac, av, &stacks)))
		return (exit_fail(&stacks, err_no));
	ft_lstrev(&stacks.stack_a);
	if ((stacks.nb_elm = ft_lstsize(stacks.stack_a)) < 0)
		return (exit_fail(&stacks, E_GENERIC));
	if (!ft_lstissorted(stacks.stack_a, &lst_elm_ordered)
			&& (err_no = algo(&stacks)))
		return (exit_fail(&stacks, err_no));
	print_actions_list(&stacks.actions);
	del_all(&stacks);
	return (EXIT_OK);
}
