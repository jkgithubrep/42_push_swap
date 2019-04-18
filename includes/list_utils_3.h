/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_3.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:55:35 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/10 19:09:25 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_3_H
# define LIST_UTILS_3_H

# include "libft.h"
# include "worker.h"

int				get_value(t_list *stack);
int				get_block(t_list *stack);
int				get_min(t_list *stack);
int				get_max(t_list *stack);
void			update_block(t_list *stack, int value);

#endif
