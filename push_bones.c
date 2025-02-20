/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bones.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:27:40 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:30:06 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_bonus(t_list **stack_b, t_list **stack_a)
{
	t_list	*node;

	if (!stack_b || !*stack_b)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	node->next = *stack_a;
	*stack_a = node;
}

void	pb_bonus(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	if (!stack_a || !*stack_a)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = *stack_b;
	*stack_b = node;
}
