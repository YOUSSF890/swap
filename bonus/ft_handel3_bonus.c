/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handel3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:33:30 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/21 18:48:27 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**allocate_result_array(int word_count)
{
	char	**t;

	t = malloc(sizeof(char *) * (word_count + 1));
	if (!t)
		write(1, "Error\n", 6);
	return (t);
}

char	**split_and_store(char *input, char **t, int *a)
{
	char	**split_result;
	int		j;

	j = 0;
	split_result = ft_split(input, ' ');
	if (!split_result)
		return (free_string_array(t), write(1, "Error\n", 6), NULL);
	while (split_result[j])
	{
		t[*a] = ft_strdup(split_result[j]);
		if (!t[*a])
		{
			free_string_array(t);
			free_string_array(split_result);
			write(1, "Error\n", 6);
			return (NULL);
		}
		(*a)++;
		j++;
	}
	free_string_array(split_result);
	return (t);
}

char	**split_input(char **str)
{
	int		i;
	int		k;
	int		word_count;
	char	**t;

	k = 0;
	i = 1;
	word_count = count_input_words(str);
	if (!word_count)
		return (NULL);
	t = allocate_result_array(word_count);
	if (!t)
		return (NULL);
	while (str[i])
	{
		t = split_and_store(str[i], t, &k);
		if (!t)
			return (NULL);
		i++;
	}
	t[k] = NULL;
	return (t);
}
