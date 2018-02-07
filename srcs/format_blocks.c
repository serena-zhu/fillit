/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_blocks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:37:20 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/25 16:37:29 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

static int		is_valid_piece(char *buf, int i)
{
	int	j;

	j = 0;
	if ((i + 1) < 20 && buf[i + 1] == '#')
		j++;
	if ((i + 5) < 20 && buf[i + 5] == '#')
		j++;
	if ((i - 1) >= 0 && buf[i - 1] == '#')
		j++;
	if ((i - 5) >= 0 && buf[i - 5] == '#')
		j++;
	if (j == 0)
		return (0);
	else if (j >= 2)
		return (2);
	else
		return (1);
}

static void		shift_loc(int *loc, int offset)
{
	int i;

	i = 0;
	if (!(offset = loc[0] - (loc[0] % 5 - offset)))
		return ;
	while (i < 4)
	{
		loc[i] -= offset;
		i++;
	}
}

/*
** count[0] counts number of rows
** count[1] counts number of '#' pieces
*/

static int		*verify_block(char *buf, int *loc)
{
	VB_VARS;
	i = 0;
	count[0] = 0;
	count[1] = 0;
	offset = 0;
	all_pieces_touch = 0;
	while (i < 20)
	{
		tmp = 1;
		if (buf[i] == '\n' && (tmp = ((i + 1) % 5 == 0 && i != 0)))
			count[0]++;
		else if (buf[i] == '#' && (tmp = (!tmp) ? 0 : is_valid_piece(buf, i)))
		{
			all_pieces_touch = (tmp == 2 || all_pieces_touch) ? 1 : 0;
			offset = ((i % 5) < offset || count[1] == 0) ? i % 5 : offset;
			loc[count[1]++] = i;
		}
		else if (buf[i] != '.' || !tmp || count[1] > 4)
			exit_with_error('g');
		i++;
	}
	if (count[0] != 4 || count[1] != 4 || !all_pieces_touch)
		exit_with_error('g');
	shift_loc(loc, offset);
	return (loc);
}

void			format_blocks(char *buf, t_block *blocks)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] != '\0')
	{
		if (!(blocks[j].loc = (int *)malloc(4 * sizeof(int))))
			exit_with_error('g');
		blocks[j].loc = verify_block(buf + i, blocks[j].loc);
		blocks[j].id = 'A' + j;
		j++;
		i += 20;
		if (buf[i] != '\n' && buf[i] != '\0')
			exit_with_error('g');
		i++;
	}
}
