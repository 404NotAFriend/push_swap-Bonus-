/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:41:22 by bramalho@st       #+#    #+#             */
/*   Updated: 2025/10/20 02:30:50 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*extract_word(char const *s, int start, int len)
{
	return (ft_substr(s, start, len));
}

static char	**free_split(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**fill_split(char **result, char const *str, char c)
{
	int	i;
	int	wordi;
	int	wordstart;

	i = 0;
	wordi = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			wordstart = i;
			while (str[i] && str[i] != c)
				i++;
			result[wordi] = extract_word(str, wordstart, i - wordstart);
			if (!result[wordi])
				return (free_split(result, wordi));
			wordi++;
		}
	}
	result[wordi] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (fill_split(result, s, c));
}
