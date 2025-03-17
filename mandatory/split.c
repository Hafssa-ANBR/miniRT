/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:10:24 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/08 13:29:39 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_words(const char *str, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i] != '\n')
		{
			if (!in_word) 
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

char	*new_word(const char *s, int *i, char c)
{
	int		j;
	int		start;
	char	*words;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	words = (char *)malloc ((*i - start) + 1);
	if (words == NULL)
		return (NULL);
	j = 0;
	while (start < *i)
	{
		words[j] = s[start];
		start++;
		j++;
	}
	words[j] = '\0';
	return (words);
}

static char	**free_words(char **words, int j)
{
	while (j >= 0)
	{
		free(words[j]);
		j--;
	}
	free(words);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	char	**words;

	i = 0;
	if (s == NULL)
		return (NULL);
	words = malloc ((count_words(s, c) + 1) * sizeof (char *));
	if (words == NULL)
		return (NULL);
	j = 0;
	while (j < count_words(s, c) && s[i])
	{
		if (s[i] != c)
		{
			words[j] = new_word(s, &i, c);
			if (words[j] == NULL)
				return (free_words(words, (j - 1)));
			j++;
		}
		i++;
	}
	words[j] = NULL;
	return (words);
}