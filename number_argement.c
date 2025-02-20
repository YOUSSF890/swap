/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_argement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:27:28 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:27:30 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_of_value(t_list *a, int b)
{
	int	index;

	index = 0;
	while (a)
	{
		index++;
		if (a->data == b)
			break ;
		a = a->next;
	}
	return (index);
}

int	find_min_value(t_list	*t)
{
	int	b;

	b = t->data;
	while (t)
	{
		if (t->data < b)
			b = t->data;
		t = t->next;
	}
	return (b);
}

void	sort_three_numbers(t_list **stack_a)
{
	int		b;
	int		index;
	t_list	*t;

	t = *stack_a;
	b = t->data;
	while (t)
	{
		if (t->data > b)
			b = t->data;
		t = t->next;
	}
	index = find_index_of_value(*stack_a, b);
	if (index == 1)
		rotate_a(stack_a);
	else if (index == 2)
		reverse_rotate_a(stack_a);
	if (((*stack_a)->data) > ((*stack_a)->next->data))
		swap_a(stack_a);
}

void	sort_four_numbers(t_list	**stack_a, t_list	**stack_b)
{
	int		index;
	int		b;
	t_list	*a;
	t_list	*t;

	a = *stack_a;
	t = *stack_a;
	b = find_min_value(t);
	index = find_index_of_value(a, b);
	if (index == 2)
		rotate_a(stack_a);
	else if (index == 3)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (index == 4)
		reverse_rotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_three_numbers(stack_a);
	push_a(stack_b, stack_a);
}

void	sort_five_numbers(t_list	**stack_a, t_list	**stack_b)
{
	int		index;
	int		b;

	b = find_min_value(*stack_a);
	index = find_index_of_value(*stack_a, b);
	if (index == 2)
		rotate_a(stack_a);
	if (index == 3)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	if (index == 4)
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	if (index == 5)
		reverse_rotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_four_numbers(stack_a, stack_b);
	push_a(stack_b, stack_a);
}
