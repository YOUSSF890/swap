/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:26:39 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:26:41 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// char	*ft_strdup(const char *s1)
// {
// 	int		i;
// 	int		a;
// 	int		len;
// 	char	*dst;

// 	a = 0;
// 	while (s1[a])
// 		a++;
// 	len = a + 1;
// 	dst = malloc (sizeof(char) * len);
// 	if (!dst)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		dst[i] = s1[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (dst);
// }
