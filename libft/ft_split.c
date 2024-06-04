/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:05:55 by kytan             #+#    #+#             */
/*   Updated: 2024/03/05 12:58:07 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
			words++;
		s++;
	}
	return (words);
}

static char	*new_word(char *s, char c)
{
	char	*word;
	int		chrs;
	int		i;

	i = -1;
	chrs = 0;
	while (s[chrs] != c && s[chrs])
		chrs++;
	word = malloc(chrs + 1);
	if (!word)
		return (0);
	while (++i < chrs)
		word[i] = s[i];
	word[chrs] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**word_list;
	size_t		words;
	char		*p;
	int			i;

	if (!s)
		return (0);
	i = 0;
	p = (char *)s;
	words = count_words(s, c);
	word_list = malloc((words + 1) * sizeof(char *));
	if (!word_list)
		return (0);
	while (p)
	{
		while (*p == c && c)
			p++;
		if (!*p)
			break ;
		word_list[i++] = new_word(p, c);
		p = ft_strchr(p, c);
	}
	word_list[words] = 0;
	return (word_list);
}
