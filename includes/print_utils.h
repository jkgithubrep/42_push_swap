/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:08:52 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/13 11:34:33 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_UTILS_H
# define PRINT_UTILS_H

# define ARRAY_NB_ROWS 50
# define CLEAR_SCREEN "\e[1;1H\e[2J"

# include "worker.h"

void			print_stacks(t_stacks *stacks, char *action, size_t count);
void			print_err(int err_no, t_uint flags);

#endif
