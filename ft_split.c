/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:48:44 by yel-hadd          #+#    #+#             */
/*   Updated: 2022/11/10 20:54:58 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i ++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

void	free_all(char **s, size_t index)
{
	while (index)
	{
		free(s[index]);
		index --;
	}
	free(s);
}

char	**allocate(char **result, size_t i, char const *s, char c)
{
	result[i] = (char *) malloc((word_len(s, c) + 1) * sizeof(char));
	if (!result[i])
	{
		free_all(&result[i], i);
		return (NULL);
	}
	ft_memcpy(result[i], s, word_len(s, c));
	result[i][word_len(s, c)] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	i;
	char	**result;

	i = 0;
	if (!s)
		return ((char **) NULL);
	count = count_words(s, c);
	result = (char **) malloc((count + 1) * sizeof(char *));
	if (!result)
		return (result);
	while (i < count)
	{
		while (*s == c && *s)
			s ++;
		result = allocate(result, i, s, c);
		if (!result)
			return (NULL);
		i ++;
		while (*s != c && *s)
			s++;
	}
	result[i] = (char *) NULL;
	return (result);
}
