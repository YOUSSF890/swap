/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handel2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:33:23 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/21 18:33:24 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_string_array(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	print_error(char **str)
{
	free_string_array(str);
	write (1, "Error\n", 6);
	exit(1);
}

void	free_stack(t_list	**list)
{
	t_list	*free_node;

	free_node = *list;
	while (*list)
	{
		free_node = *list;
		*list = (*list)->next;
		free(free_node);
	}
}