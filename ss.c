/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:28:54 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:28:56 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **sa)
{
	t_list	*second;

	second = (*sa)->next;
	if (!sa || !*sa || !(*sa)->next)
		return ;
	(*sa)->next = (*sa)->next->next;
	second->next = (*sa);
	*sa = second;
	write (1, "sa\n", 3);
}

void	swap_b(t_list **sb)
{
	t_list	*second;

	second = (*sb)->next;
	if (!sb || !*sb || !(*sb)->next)
		return ;
	(*sb)->next = (*sb)->next->next;
	second->next = (*sb);
	*sb = second;
	write (1, "sb\n", 3);
}
