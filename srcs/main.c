/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:59:02 by yazhu             #+#    #+#             */
/*   Updated: 2017/12/07 13:58:13 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		main(int argc, char **argv)
{
	char	*buf;
	t_block	*blocks;
	int		fd;
	int		r;
	int		n;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			exit_with_error('g');
		if (!(buf = (char *)malloc(546 * sizeof(char))))
			exit_with_error('g');
		if ((r = read(fd, buf, 546)) > 545 || r < 20 || ((r + 1) % 21 != 0))
			exit_with_error('g');
		buf[r] = '\0';
		if (close(fd) != 0)
			exit_with_error('g');
		n = (r + 1) / 21;
		if (!(blocks = (t_block *)malloc(n * sizeof(t_block))))
			exit_with_error('g');
		format_blocks(buf, blocks);
		solve(blocks, n);
		return (0);
	}
	exit_with_error('u');
}
