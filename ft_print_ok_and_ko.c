/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ok_and_ko.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:47:39 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 15:51:43 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_ko(t_list *copy)
{
	write(1, "KO\n", 3);
	free_stack(&copy);
	exit(1);
}

void	ft_print_ko2(t_list	**stack_a, t_list	**stack_b)
{
	write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(1);
}

void	ft_print_ok(t_list	*copy)
{
	write(1, "OK\n", 3);
	free_stack(&copy);
	exit(1);
}

int	ft_sizeff(t_list *stack)
{
	int		a;
	t_list	*node;

	a = 0;
	node = stack;
	while (node)
	{
		a++;
		node = node->next;
	}
	return (a);
}

void	ft_free_get_and_stack(char *line, t_list *stack_a)
{
	get_next_line(-1);
	write (1, "Error\n", 6);
	free_stack(&stack_a);
	free(line);
	exit(1);
}
