/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_hundred_argerment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:27:34 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/21 18:20:50 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list	*stack, int k)
{
	int		i;
	int		a;
	int		b;
	t_list	*node;

	i = 0;
	a = 0;
	b = 0;
	node = stack;
	while (node)
	{
		a++;
		node = node->next;
	}
	if (k == 1)
		return (a);
	while (i < a / 2 && stack->next)
	{
		if (stack->data > stack->next->data)
			b++;
		stack = stack->next;
		i++;
	}
	return (b);
}

void	push_to_stack_b(t_list **stack_a, t_list **stack_b, int size, int rang)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push_b(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + rang)
		{
			push_b(stack_a, stack_b);
			if (*stack_b && (*stack_b)->next)
				rotate_b(stack_b);
			i++;
		}
		else if (size)
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
}

int	find_max_index(t_list **stack, int i)
{
	int		j;
	t_list	*temp;

	j = 0;
	temp = *stack;
	while (temp && temp->index != i)
	{
		temp = temp->next;
		j++;
	}
	return (j);
}

void	push_to_stack_a(t_list **stacka, t_list **stackb, int nbr_input)
{
	int		j;

	while (*stackb)
	{
		j = find_max_index(stackb, nbr_input);
		if (j <= nbr_input / 2)
		{
			while (j != 0)
			{
				rotate_b(stackb);
				j--;
			}
			push_a(stackb, stacka);
		}
		else if (j > nbr_input / 2)
		{
			while (j != nbr_input)
			{
				reverse_rotate_b(stackb);
				j++;
			}
			push_a(stackb, stacka);
		}
		nbr_input--;
	}
}

void	sort_large_stack(t_list **stack_a, t_list **stack_b)
{
	int		nbr_input;
	int		rang1;
	int		size1;

	size1 = 0;
	nbr_input = stack_size(*stack_a, 1);
	if (nbr_input <= 100)
		rang1 = 12;
	else
		rang1 = 34;
	size1 = stack_size(*stack_a, 0) > (nbr_input / 3);
	push_to_stack_b(stack_a, stack_b, size1, rang1);
	push_to_stack_a(stack_a, stack_b, nbr_input);
}
