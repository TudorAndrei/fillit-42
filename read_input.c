/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 21:11:59 by tdumitra          #+#    #+#             */
/*   Updated: 2018/02/02 21:12:01 by tdumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		block_validator(char *block)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (i < 20)
	{
		sum += block[i];
		i++;
		if (i % 5 == 0 && block[i - 1] != '\n')
			return (1);
	}
	if (!(block[i] == 0 || block[i] == '\n'))
	{
		return (2);
	}
	if (sum != 732)
		return (3);
	return (0);
}

int		input_length(char *path)
{
	int		fd;
	int		ret;
	char	*buf;
	int		counter;
	int		old_ret;

	counter = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = ft_strnew(21);
	while ((ret = read(fd, buf, 21)))
	{
		if (block_validator(buf) || ret < 20)
			return (0);
		counter++;
		old_ret = ret;
	}
	if (old_ret != 20)
		return (0);
	free(buf);
	if (close(fd) == -1)
		return (0);
	return (counter);
}

char	**input_strings(char *path, int size)
{
	int		fd;
	int		ret;
	int		b;
	char	*buf;
	char	**output;

	b = 0;
	buf = ft_strnew(21);
	output = (char**)malloc(sizeof(char*) * (size + 1));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((ret = read(fd, buf, 21)))
	{
		output[b] = ft_strdup(buf);
		b++;
	}
	free(buf);
	if (close(fd) == -1)
		return (NULL);
	return (output);
}

char	***return_error(void)
{
	ft_putendl("error");
	return (NULL);
}

char	***set_up(char *path)
{
	int		size;
	char	***matrix;
	char	**str;

	size = 0;
	size = input_length(path);
	if (!size)
		return (return_error());
	str = input_strings(path, size);
	if (!str)
		return (return_error());
	matrix = gen_matrices(size, 4, 4, '.');
	if (!matrix)
		return (return_error());
	fill_matrices(matrix, str);
	if (tetro_checker(matrix, 0, 0) == 0)
		return (return_error());
	clean_row_matrices(matrix);
	clean_column_matrices(matrix);
	return (matrix);
}
