/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumitra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:47:23 by tdumitra          #+#    #+#             */
/*   Updated: 2018/02/03 15:47:25 by tdumitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>

int		main(int argc, char **argv);
int		block_validator(char *block);
int		input_length(char *path);
char	**input_strings(char *path, int size);
int		print_strings(char **str);
char	***set_up(char *path);
char	***gen_matrices(int size, int m, int n, char c);
int		print_matrices(char ***matrix);
int		fill_matrices(char ***matrix, char **str);
int		clean_row_matrices(char ***matrix);
int		clean_single_column(char ***matrix, int b, int i, int j);
int		clean_column_matrices(char ***matrix);
int		ft_floor_sqrt(int value);
int		num_tetra(char ***tetra);
char	**gen_row(int m, int n, char c);
int		**free_row(char **row);
int		print_row(char **row);
int		insert_tetra_grid(char **row, char **tetra, int x, int y);
int		insert_checker(char **row, char **tetra, int x, int y);
int		insert_check_complete(char **row, char **tetra, int x, int y);
int		bfs_big_fucking_solver(char **row, char ***tetra, int b);
int		solve(char ***matrix);
int		validate_tetro(char **str, int i, int j);
int		tetro_checker(char ***str, int i, int j);

#endif
