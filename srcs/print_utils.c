/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:07:36 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 11:39:51 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_utils.h"
#include "worker.h"
#include "error.h"
#include "libft.h"
#include "list_utils.h"
#include "list_utils_3.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

static void			print_stacks_header(t_stacks *stacks)
{
	int				width;

	width = (stacks->nb_col * (stacks->max_digits + 1)) + 1;
	ft_printf("{bold}{underline}%*s%*s{reset}", width / 2 + 1, "A",
			(width - 1) / 2, "");
	ft_printf("{underline}│{reset}");
	ft_printf("{bold}{underline}%*s%*s{reset}\n", (width - 1) / 2 + 1, "B",
			width / 2, "");
}

static void			print_color(t_stacks *stacks, t_list *stack)
{
	int				val;

	if (stacks->nb_elm > 1)
		val = (stacks->nb_elm > 512) ? ((t_node *)stack->content)->index
				/ ((stacks->nb_elm / 512) + 1)
			: ((t_node *)stack->content)->index * (512 / (stacks->nb_elm - 1));
	else
		val = 512;
	if (val <= 255)
		ft_printf("\x1b[38;2;%d;%d;%dm", 0, val, 255);
	else
	{
		val = (val == 512) ? 255 : val % 256;
		ft_printf("\x1b[38;2;%d;%d;%dm", 255, 255 - val, 0);
	}
}

static void			print_row(t_stacks *stacks, t_list **stack)
{
	int				j;

	j = 0;
	ft_putstr(" ");
	while (j < stacks->nb_col)
	{
		if (*stack)
		{
			print_color(stacks, *stack);
			ft_printf("%0 *d{reset}", stacks->max_digits, get_value(*stack));
		}
		else
			ft_printf("%*s", stacks->max_digits, " ");
		++j;
		*stack = (*stack ? (*stack)->next : NULL);
		ft_putstr((j == stacks->nb_col) ? "" : " ");
	}
}

void				print_stacks(t_stacks *stacks, char *action, size_t count)
{
	struct timespec	time;
	struct timespec	time2;
	t_list			*stack_a;
	t_list			*stack_b;

	time.tv_sec = 0;
	time.tv_nsec = (stacks->flags & FL_FAST) ? 40000000L : 500000000L;
	ft_printf(CLEAR_SCREEN "Action: {bold}{magenta}%3s (%zu){reset} \n\n",
			action, count);
	print_stacks_header(stacks);
	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	while (stack_a || stack_b)
	{
		print_row(stacks, &stack_a);
		ft_putstr("  ");
		print_row(stacks, &stack_b);
		ft_printf(" \n");
	}
	nanosleep(&time, &time2);
}

void				print_err(int err_no, t_uint flags)
{
	if (!(flags & FL_ERR))
		ft_dprintf(STDERR_FILENO, "Error\n");
	else if (err_no == E_NBR_ARGS)
		ft_dprintf(STDERR_FILENO, "Error: wrong number of arguments\n");
	else if (err_no == E_INVALID_ARG)
		ft_dprintf(STDERR_FILENO, "Error: invalid argument\n");
	else if (err_no == E_OVERFLOW)
		ft_dprintf(STDERR_FILENO, "Error: overflow\n");
	else if (err_no == E_DUP)
		ft_dprintf(STDERR_FILENO, "Error: duplicated values\n");
	else if (err_no == E_INVALID_CMD)
		ft_dprintf(STDERR_FILENO, "Error: invalid command\n");
	else if (err_no == E_INVALID_FLAG)
		ft_dprintf(STDERR_FILENO, "Error: invalid flag\n");
	else if (err_no == E_NULL)
		ft_dprintf(STDERR_FILENO, "Error: null pointer returned\n");
	else if (err_no == E_VALUE_NOT_FOUND)
		ft_dprintf(STDERR_FILENO, "Error: value not found\n");
	else if (err_no == E_HELP)
		ft_dprintf(STDERR_FILENO, "Usage: ./checher [-evfsh] args\n");
	else
		ft_dprintf(STDERR_FILENO, "Error\n");
}
