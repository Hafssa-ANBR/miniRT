/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:07:37 by hanebaro          #+#    #+#             */
/*   Updated: 2025/03/08 13:07:51 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	separator(char ch, char *separators)
{
	while (*separators)
	{
		if (ch == *separators)
			return (1);
		separators++;
	}
	return (0);
}

static int	cnt_words(char *str, char *separators)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!separator(str[i], separators) \
		&& (separator(str[i + 1], separators) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*n_word(char *s, int *i, char *separators)
{
	int		j;
	int		start;
	char	*word;

	start = *i;
	while (s[*i] && !separator(s[*i], separators))
		(*i)++;
	word = (char *)malloc((*i - start) + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (start < *i)
		word[j++] = s[start++];
	word[j] = '\0';
	return (word);
}

static char	**f_words(char **words, int j)
{
	while (j >= 0)
	{
		free(words[j]);
		j--;
	}
	free(words);
	return (NULL);
}

char	**multi_split(char *s, char *separators)
{
	int		i;
	int		j;
	char	**words;

	if (!s || !separators)
		return (NULL);
	words = malloc((cnt_words(s, separators) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	j = 0;
	while (j < cnt_words(s, separators) && s[i])
	{
		if (!separator(s[i], separators))
		{
			words[j] = n_word(s, &i, separators);
			if (!words[j])
				return (f_words(words, j - 1));
			j++;
		}
		else
			i++;
	}
	words[j] = NULL;
	return (words);
}