/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:27:21 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:27:23 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_new_node(int number)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		write (1, "Error\n", 6);
		return (NULL);
	}
	new_node->data = number;
	new_node->next = NULL;
	return (new_node);
}

void	append_node_to_list(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst)
		return (free_stack(&new), (void)(0));
	if (!new)
		return (free_stack(lst), (void)(0));
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}
}

void	assign_index_to_nodes(t_list *stack)
{
	t_list	*node1;
	t_list	*node2;
	int		index;

	node1 = stack;
	while (node1)
	{
		index = 1;
		node2 = stack;
		while (node2)
		{
			if (node1->data > node2->data)
				index++;
			node2 = node2->next;
		}
		node1->index = index;
		node1 = node1->next;
	}
}
