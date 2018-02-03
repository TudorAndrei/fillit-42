/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:51:44 by tdumitra          #+#    #+#             */
/*   Updated: 2018/02/03 14:05:37 by tdumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char ***matrices;

	if (argc < 2)
		ft_putendl("usage: fillit source_file");
	else if (argc > 2)
		ft_putendl("to much input!");
	else
	{
		matrices = set_up(argv[1]);
		if (!matrices)
			return (1);
		solve(matrices);
		return (0);
	}
	return (1);
}
