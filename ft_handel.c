/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:26:32 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:30:21 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_input_words(char **str)
{
	int		i;
	int		j;
	int		a;
	char	**t;

	i = 1;
	a = 0;
	while (str[i])
	{
		j = 0;
		t = ft_split(str[i], 32);
		if (!t || !(*t))
			return (free_string_array(t), write(1, "Error\n", 6), 0);
		while (t[j])
		{
			a++;
			j++;
		}
		free_string_array(t);
		i++;
	}
	return (a);
}

void	check(char **str, int i, int j)
{
	if ((str[i][j] == '+' || str[i][j] == '-' ) &&
		(str[i][j + 1] == '+' || str[i][j + 1] == '-'))
		print_error(str);
	else if ((str[i][j] >= '0' || str[i][j] <= '9' ) &&
		(str[i][j + 1] == '+' || str[i][j + 1] == '-'))
		print_error(str);
	else if ((str[i][j] == '+' || str[i][j] == '-' ) &&
		str[i][j + 1] == '\0')
		print_error(str);
}

void	validate_input(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] >= '0' && str[i][j] <= '9')
				|| (str[i][j] == '+' || str[i][j] == '-'))
			{
				check(str, i, j);
			}
			else
				print_error(str);
			j++;
		}
		i++;
	}
}

void	check_duplicate_numbers(t_list **stack_a)
{
	t_list	*node;
	t_list	*node_2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	node = *stack_a;
	node_2 = *stack_a;
	while (node_2)
	{
		j = 0;
		node = *stack_a;
		while (node)
		{
			if (node_2->data == node->data && i != j)
				return (write (1, "Error\n", 6), free_stack(stack_a), exit(1));
			node = node->next;
			j++;
		}
		node_2 = node_2->next;
		i++;
	}
}

void	convert_to_stack(char	**str, t_list	**a)
{
	t_list	*ff;
	int		i;
	long	num;
	char	**str_split;

	i = 0;
	ff = NULL;
	str_split = split_input(str);
	if (!str_split)
		return (exit(1));
	validate_input(str_split);
	while (str_split[i])
	{
		num = ft_atoi(str_split[i]);
		if (num > 2147483647 || num < -2147483648)
			return (free_stack(a), print_error(str_split));
		ff = create_new_node(num);
		if (!ff)
			return (free_stack(a), exit(1));
		append_node_to_list(a, ff);
		i++;
	}
	free_string_array(str_split);
	check_duplicate_numbers(a);
}
