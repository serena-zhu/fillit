/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:50:18 by pzhang            #+#    #+#             */
/*   Updated: 2017/12/07 12:32:18 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

static int	verify_fit(char *board, int *pos)
{
	int c;

	c = 0;
	while (c < 4)
	{
		if (board[pos[c]] != '.')
			return (0);
		c++;
	}
	return (1);
}

static void	put_block(char *board, int *pos, char c)
{
	int i;

	i = 0;
	while (i < 4)
	{
		board[pos[i]] = c;
		i++;
	}
}

static int	fill_help(char *board, t_block b, int s)
{
	int *pos;
	int c;

	c = 0;
	if (!(pos = (int*)malloc(sizeof(int) * 4)))
		exit_with_error('g');
	while (c < 4)
	{
		pos[c] = ((b.loc[c] / 5) * (s + 1)) + (b.loc[c] % 5) - b.loc[0];
		c++;
	}
	if (verify_fit(board, pos) == 1)
	{
		put_block(board, pos, b.id);
		free(pos);
		return (1);
	}
	free(pos);
	return (0);
}

int			fill_board(char *board, t_block *blocks, int *c)
{
	if (c[2] == c[0])
		return (1);
	else if (board[c[1]])
	{
		if (board[c[1]] == '.')
		{
			if (fill_help(board + c[1], blocks[c[2]], c[3]) == 1)
			{
				c[2]++;
				c[1] = 0;
			}
			else
				c[1]++;
		}
		else
			c[1]++;
		return (2);
	}
	else if (c[2] == 0)
		return (0);
	else
		return (3);
}
