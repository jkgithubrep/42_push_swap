/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:54:48 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 11:44:17 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "worker.h"
#include "libft.h"
#include "error.h"
#include "input.h"
#include "actions.h"
#include "print_utils.h"
#include "list_utils.h"
#include "list_utils_2.h"
#include "utils.h"

int				print_final(t_stacks *stacks, int exit_status)
{
	if (exit_status == EXIT_OK)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	del_all(stacks);
	return (EXIT_OK);
}

int				main(int ac, char **av)
{
	int			err_no;
	t_stacks	stacks;

	if (ac < 2)
		return (EXIT_FAIL);
	stacks = (t_stacks){NULL, NULL, NULL, 0, 0, 0, 0, 0, 0u, 0};
	stacks.flags |= FL_CHECKER;
	if ((err_no = check_args(ac, av, &stacks)))
		return (exit_fail(&stacks, err_no));
	ft_lstrev(&stacks.stack_a);
	if ((stacks.nb_elm = ft_lstsize(stacks.stack_a)) < 0)
		return (exit_fail(&stacks, E_GENERIC));
	stacks.nb_col = stacks.nb_elm / ARRAY_NB_ROWS
		+ ((stacks.nb_elm % ARRAY_NB_ROWS) ? 1 : 0);
	ft_lstget(stacks.stack_a, &stacks.max_digits, &lst_elm_max_digits);
	if (stacks.flags & FL_VISU)
		print_stacks(&stacks, "init", 0);
	if ((err_no = get_actions_from_stdin(&stacks)))
		return (exit_fail(&stacks, err_no));
	if (ft_lstissorted(stacks.stack_a, &lst_elm_ordered) && !stacks.size_b)
		return (print_final(&stacks, EXIT_OK));
	else
		return (print_final(&stacks, EXIT_FAIL));
}
