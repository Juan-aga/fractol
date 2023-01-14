/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:17:49 by juan-aga          #+#    #+#             */
/*   Updated: 2022/11/16 09:24:46 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_check(char const *s, char c, size_t row);
static	char		**ft_fill(char const *s, char c, size_t row, char **new);
static	void		*ft_free(char **new, int i);

char	**ft_split(char const *s, char c)
{
	size_t	row;
	char	**new;

	row = 0;
	if (!s)
		return (NULL);
	row = ft_check(s, c, row);
	new = (char **) ft_calloc(row + 1, sizeof(char *));
	if (!new)
		return (NULL);
	return (ft_fill(s, c, row, new));
}

static	size_t	ft_check(char const *s, char c, size_t row)
{
	size_t	i;

	row = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
		}
		else if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			row++;
		}
	}
	return (row);
}

static	char	**ft_fill(char const *s, char c, size_t row, char **new)
{
	size_t	i;
	size_t	i2;
	size_t	len;

	i = 0;
	i2 = 0;
	len = 0;
	while (i2 < row)
	{
		while (s[i] == c && s[i])
			i++;
		len = i;
		while (s[i] != c && s[i])
			i++;
		new[i2] = ft_substr(s, len, i - len);
		if (!new[i2])
			return (ft_free(new, (int) i2));
		i2++;
		i++;
	}
	return (new);
}

static	void	*ft_free(char **new, int i)
{
	while (i <= 0)
	{
		free(new[i]);
		i--;
	}
	free(new);
	return (NULL);
}
