/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:55:52 by tdumitra          #+#    #+#             */
/*   Updated: 2018/02/02 20:56:13 by tdumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int		validate_tetro(char **str, int i, int j)
{
	int		k;

	k = 0;
	if (j < 3)
	{
		if (str[i][j + 1] == str[i][j])
			k++;
	}
	if (i < 3)
	{
		if (str[i + 1][j] == str[i][j])
			k++;
	}
	if (j > 0)
	{
		if (str[i][j - 1] == str[i][j])
			k++;
	}
	if (i > 0)
	{
		if (str[i - 1][j] == str[i][j])
			k++;
	}
	return (k);
}

int		tetro_checker(char ***str, int i, int j)
{
	int		b;
	int		k;

	b = 0;
	k = 0;
	while (str[b] != 0)
	{
		while (str[b][i] != 0)
		{
			while (str[b][i][j] != 0)
			{
				if (str[b][i][j] >= 65 && str[b][i][j] <= 90)
					k += validate_tetro(str[b], i, j);
				j++;
			}
			j = 0;
			i++;
		}
		if (k < 6)
			return (0);
		k = 0;
		i = 0;
		b++;
	}
	return (1);
}
