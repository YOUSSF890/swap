/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:28:37 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:28:39 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list	**rra)
{
	t_list	*second_last;
	t_list	*current;

	if (!rra || !(*rra) || !(*rra)->next)
		return ;
	second_last = NULL;
	current = *rra;
	while (current->next)
	{
		second_last = current;
		current = current->next;
	}
	second_last->next = NULL;
	current->next = *rra;
	*rra = current;
	write (1, "rra\n", 4);
}

void	reverse_rotate_b(t_list	**rrb)
{
	t_list	*last;
	t_list	*second_last;
	t_list	*current;

	if (!rrb || !(*rrb) || !(*rrb)->next)
		return ;
	last = NULL;
	second_last = NULL;
	current = *rrb;
	while (current->next)
	{
		second_last = current;
		current = current->next;
	}
	last = current;
	second_last->next = NULL;
	last->next = *rrb;
	*rrb = last;
	write (1, "rrb\n", 4);
}
