/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:12:40 by varodrig          #+#    #+#             */
/*   Updated: 2024/09/11 11:58:11 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	count_words(char *s, char c)
{
	int	outside_word;
	int	count;

	count = 0;
	while (*s)
	{
		outside_word = 1;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (outside_word)
			{
				count++;
				outside_word = 0;
			}
			s++;
		}
	}
	return (count);
}

static	char	*get_next_word(char *s, char c)
{
	static int	cursor;
	int			i;
	int			len;
	char		*word;

	i = 0;
	len = 0;
	while (s[cursor] == c)
		cursor++;
	while (s[cursor + len] != c && s[cursor + len])
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
		word[i++] = s[cursor++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	int		words_number;
	int		i;
	char	**result_string;

	i = 0;
	words_number = count_words(s, c);
	if (!words_number)
		return (NULL);
	result_string = malloc(sizeof(char *) * (words_number + 1));
	if (!result_string)
		return (NULL);
	while (words_number-- > 0)
	{
		result_string[i] = get_next_word(s, c);
		if (!result_string[i++])
		{
			while (--i >= 0)
				free(result_string[i]);
			free(result_string);
			return (NULL);
		}
	}
	result_string[i] = NULL;
	return (result_string);
}

int	main(void)
{
	char	*str;
	char	**split_res;
	int		i;

	str = "hello Paris";
	split_res = ft_split(str, ' ');
	i = 0;
	while (split_res[i])
	{
		printf("%s", split_res[i]);
		i++;
	}
	while (--i >= 0)
		free(split_res[i]);
	free(split_res);
	return (0);
}
