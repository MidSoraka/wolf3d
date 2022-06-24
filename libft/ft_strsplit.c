/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:51:56 by vlaine            #+#    #+#             */
/*   Updated: 2021/11/25 13:51:56 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **tab, size_t word)
{
	size_t	index;

	index = 0;
	if (tab[word] == NULL)
	{
		while (tab[index] != NULL)
		{
			free(tab[index]);
			index++;
		}
		free(tab);
		return (0);
	}
	else
		return (1);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	index;
	size_t	word;
	size_t	letter;

	index = 0;
	word = 0;
	while (s[index])
	{
		if (s[index] == c && letter > 0)
		{
			word++;
			letter = 0;
		}
		if (s[index] != c)
			letter++;
		index++;
	}
	if (letter > 0)
		word++;
	if (word == 0 && index != 0)
		word++;
	return (word);
}

static void	ft_csplit(char const *s, char **tab, char c)
{
	size_t	letter;
	size_t	index;
	size_t	word;

	letter = 0;
	index = 0;
	word = 0;
	while (s[index])
	{
		if (s[index] == c)
		{
			if (letter != 0)
				tab[word++][letter] = '\0';
			letter = 0;
		}
		if (s[index] && s[index] != c)
		{
			tab[word][letter] = s[index];
			tab[word][letter + 1] = '\0';
			letter++;
		}
		index++;
	}
	if (ft_strlen(s) == 0 || (letter == 0 && word == 0))
		tab[word] = NULL;
}

static int	ft_malloc(char **tab, char const *s, char c)
{
	size_t	letter;
	size_t	index;
	size_t	word;

	letter = 0;
	index = 0;
	word = 0;
	while (s[index])
	{
		if (s[index] == c && letter > 0)
		{
			tab[word] = (char *) malloc(letter * sizeof(char) + 1);
			if (ft_free(tab, word++) == 0)
				return (0);
			letter = 0;
		}
		if (s[index++] != c)
			letter++;
	}
	if (letter > 0 || word == 0)
		tab[word++] = (char *) malloc(letter * sizeof(char) + 1);
	if (ft_free(tab, (word - 1)) == 0)
		return (0);
	tab[word] = NULL;
	return (1);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;

	tab = (char **) malloc((ft_countwords(s, c)) * sizeof(char *) + 1);
	if (tab == NULL)
		return (NULL);
	if (ft_malloc(tab, s, c) == 0)
		return (NULL);
	ft_csplit(s, tab, c);
	return (tab);
}
