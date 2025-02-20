/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:27:49 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:27:52 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_list_sorted(t_list	*stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// int	main(int ac, char *av[])
// {
// 	t_list	*a;
// 	t_list	*b;
// 	int		count_word;

// 	if (ac == 1)
// 		return (0);
// 	a = NULL;
// 	b = NULL;
// 	count_word = count_input_words(av);
// 	if (!count_word)
// 		exit(1);
// 	convert_to_stack(av, &a);
// 	if (is_list_sorted(a))
// 		return (free_stack(&a), 0);
// 	if (a)
// 		assign_index_to_nodes(a);
// 	if (count_word <= 3)
// 		sort_three_numbers(&a);
// 	else if (count_word == 4)
// 		sort_four_numbers (&a, &b);
// 	else if (count_word == 5)
// 		sort_five_numbers(&a, &b);
// 	else
// 		sort_large_stack(&a, &b);
// 	free_stack(&a);
// }
