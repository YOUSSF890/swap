/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_bones.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:28:46 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:28:48 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_bonus(t_list **sa)
{
	t_list	*second;

	if (!sa || !*sa || !(*sa)->next)
		return ;
	second = (*sa)->next;
	(*sa)->next = (*sa)->next->next;
	second->next = (*sa);
	*sa = second;
}

void	sb_bonus(t_list **sb)
{
	t_list	*second;

	if (!sb || !*sb || !(*sb)->next)
		return ;
	second = (*sb)->next;
	(*sb)->next = (*sb)->next->next;
	second->next = (*sb);
	*sb = second;
}

void	ss_bonus(t_list **sa, t_list **sb)
{
	sa_bonus(sa);
	sb_bonus(sb);
}
