/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:26:55 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/20 13:26:56 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freeup(char **strs, int i)
{
	while (i-- > 0)
	{
		free(strs[i]);
	}
	free(strs);
}

int	ft_wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

void	ft_strcpy(char *word, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != c && str[j + i] != '\0')
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = '\0';
}

char	*ft_stralloc(char *str, char c, int *k)
{
	char	*word;
	int		start;
	int		len;

	start = *k;
	len = 0;
	while (str[*k] && str[*k] == c)
		(*k)++;
	start = *k;
	while (str[*k] && str[*k] != c)
	{
		len++;
		(*k)++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strcpy(word, str, c, start);
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (str == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_wordcount((char *)str, c);
	strs = malloc(sizeof(char *) * (j + 1));
	if (!strs)
		return (NULL);
	while (i < j)
	{
		strs[i] = ft_stralloc((char *)str, c, &pos);
		if (!strs[i])
		{
			ft_freeup(strs, i);
			return (NULL);
		}
		i++;
	}
	strs[j] = NULL;
	return (strs);
}
