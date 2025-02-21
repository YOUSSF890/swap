/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:32:53 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/21 20:18:44 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check1(char *str, char *sre)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (str[i] || sre[i])
	{
		if (str[i] == sre[i])
			a++;
		i++;
	}
	if (a == i)
		return (1);
	return (0);
}

int	check_operations(char *str)
{
	if (!str || !*str)
		return (0);
	if (check1(str, "sa\n") || check1(str, "sb\n")
		|| check1(str, "ss\n") || check1(str, "ra\n")
		|| check1(str, "rb\n") || check1(str, "rr\n")
		|| check1(str, "rra\n") || check1(str, "rrb\n")
		|| check1(str, "rrr\n") || check1(str, "pa\n")
		|| check1(str, "pb\n"))
	{
		return (1);
	}
	else
		return (0);
}

void	application_operations(char *str, t_list **stack_aa, t_list **stack_bb)
{
	if (check1(str, "sa\n"))
		sa_bonus(stack_aa);
	else if (check1(str, "sb\n"))
		sb_bonus(stack_bb);
	else if (check1(str, "ss\n"))
		ss_bonus(stack_aa, stack_bb);
	else if (check1(str, "ra\n"))
		ra_bonus(stack_aa);
	else if (check1(str, "rb\n"))
		rb_bonus(stack_bb);
	else if (check1(str, "rr\n"))
		rr_bonus(stack_aa, stack_bb);
	else if (check1(str, "rra\n"))
		rra_bonus(stack_aa);
	else if (check1(str, "rrb\n"))
		rrb_bonus(stack_bb);
	else if (check1(str, "rrr\n"))
		rrr_bonus(stack_aa, stack_bb);
	else if (check1(str, "pa\n"))
		pa_bonus(stack_bb, stack_aa);
	else if (check1(str, "pb\n"))
		pb_bonus(stack_aa, stack_bb);
}

void	validate(t_list **stack_a, t_list **stack_b, int nbr_input)
{
	int		i;
	int		a;
	int		b;
	t_list	*copy;

	copy = *stack_a;
	b = ft_sizeff(*stack_a);
	i = 0;
	a = 0;
	if (nbr_input != b)
		ft_print_ko2(stack_a, stack_b);
	while (stack_a && (*stack_a)->next)
	{
		if ((*stack_a)->data < (*stack_a)->next->data)
			a++;
		i++;
		(*stack_a) = (*stack_a)->next;
	}
	if (a == i)
		ft_print_ok(copy);
	else
		ft_print_ko(copy);
}

int	main(int ac, char *av[])
{
	char	*line;
	t_list	*stack_a;
	t_list	*stack_b;
	int		nbr_input;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		nbr_input = count_input_words(av);
		if (!nbr_input)
			exit(1);
		convert_to_stack(av, &stack_a);
		line = get_next_line(0);
		while (line)
		{
			if (!check_operations(line))
				ft_free_get_and_stack(line, stack_a);
			application_operations(line, &stack_a, &stack_b);
			free(line);
			line = get_next_line(0);
		}
		validate(&stack_a, &stack_b, nbr_input);
	}
	return (0);
}
;
