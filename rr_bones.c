/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_bones.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:28:17 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:28:20 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_bonus(t_list	**ra)
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
}

void	rb_bonus(t_list	**rb)
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
}

void	rr_bonus(t_list **ra, t_list **rb)
{
	ra_bonus(ra);
	rb_bonus(rb);
}
