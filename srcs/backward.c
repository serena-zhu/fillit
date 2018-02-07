/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:42:29 by pzhang            #+#    #+#             */
/*   Updated: 2017/12/07 12:33:05 by pzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

static int	reset_board(char *board, int *pos, char id)
{
	int i;

	i = 0;
	while (board[i])
	{
		if (board[i] == id)
			break ;
		i++;
	}
	board[i + pos[0]] = '.';
	board[i + pos[1]] = '.';
	board[i + pos[2]] = '.';
	board[i + pos[3]] = '.';
	return (i + 1);
}

void		backward(char *board, t_block *block, int *c)
{
	int	*pos;
	int	i;

	if (!(pos = (int*)malloc(sizeof(int) * 4)))
		exit_with_error('g');
	i = 0;
	c[2]--;
	while (i < 4)
	{
		pos[i] = ((block[c[2]].loc[i] / 5) * (c[3] + 1)) +
			(block[c[2]].loc[i] % 5) - block[c[2]].loc[0];
		i++;
	}
	c[1] = reset_board(board, pos, block[c[2]].id);
	free(pos);
}
