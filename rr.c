/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:28:24 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:28:26 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list	**ra)
{
	t_list	*a;
	t_list	*second;
	t_list	*last;

	if (*ra == NULL || (*ra)->next == NULL)
		return ;
	a = *ra;
	second = (*ra)->next;
	last = *ra;
	while (last->next != NULL)
		last = last->next;
	last->next = a;
	a->next = NULL;
	*ra = second;
	write (1, "ra\n", 3);
}

void	rotate_b(t_list	**rb)
{
	t_list	*a;
	t_list	*second;
	t_list	*last;

	if (*rb == NULL || (*rb)->next == NULL)
		return ;
	a = *rb;
	second = (*rb)->next;
	last = *rb;
	while (last->next != NULL)
		last = last->next;
	last->next = a;
	a->next = NULL;
	*rb = second;
	write (1, "rb\n", 3);
}
