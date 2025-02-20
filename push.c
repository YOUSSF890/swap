/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:28:10 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:28:12 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*node;

	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = *stack_b;
	*stack_b = node;
	write (1, "pb\n", 3);
}

void	push_a(t_list	**stack_b, t_list	**stack_a)
{
	t_list	*node;

	node = *stack_b;
	*stack_b = (*stack_b)->next;
	node->next = *stack_a;
	*stack_a = node;
	write (1, "pa\n", 3);
}
