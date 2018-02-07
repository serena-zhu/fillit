/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:07:32 by pzhang            #+#    #+#             */
/*   Updated: 2017/12/07 13:08:33 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

static int		board_size(int n)
{
	int		a;
	int		b;

	a = 4 * n;
	b = 2;
	while (b * b < a)
		b++;
	return (b);
}

static char		*make_board(int b)
{
	char	*str;
	int		c;

	if (!(str = (char*)malloc(sizeof(char) * ((b * (b + 1)) + 1))))
		exit_with_error('g');
	c = 0;
	while (c < (b * (b + 1)))
	{
		if ((c % (b + 1)) != b)
			str[c] = '.';
		else
			str[c] = '\n';
		c++;
	}
	str[c] = '\0';
	return (str);
}

static void		free_help(t_block *blocks, int *num, char *str)
{
	int c;
	int n;

	c = 0;
	n = num[0];
	free(num);
	free(str);
	while (c < n)
	{
		free(blocks[c].loc);
		c++;
	}
	free(blocks);
}

/*
** num[0] = # of blocks			num[1] = index of board
** num[2] = index of blocks		num[3] = board size
*/

static int		fill_arrays(int *num, int n)
{
	num[0] = n;
	num[1] = 0;
	num[2] = 0;
	num[3] = board_size(n);
	return (0);
}

void			solve(t_block *blocks, int n)
{
	char	*board;
	int		c;
	int		*num;

	if (!(num = (int*)malloc(4 * sizeof(int))))
		exit_with_error('g');
	c = fill_arrays(num, n);
	board = make_board(num[3]);
	while (c != 1)
	{
		c = fill_board(board, blocks, num);
		if (c == 0)
		{
			free(board);
			num[1] = 0;
			num[2] = 0;
			num[3]++;
			board = make_board(num[3]);
		}
		else if (c == 3)
			backward(board, blocks, num);
	}
	write(1, board, num[3] * (num[3] + 1));
	free_help(blocks, num, board);
}
