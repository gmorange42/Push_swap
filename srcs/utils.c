/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:36:42 by gmorange          #+#    #+#             */
/*   Updated: 2021/09/08 16:40:22 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	move_up(int *pile, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		pile[i] = pile[i + 1];
		i++;
	}
}

void	move_down(int *pile, int len)
{
	int	i;

	i = len - 1;
	while (i > 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
}

int	is_a_sorted(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data.a_len - 1)
	{
		if (all->a[i] > all->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	is_b_sorted(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data.b_len - 1)
	{
		if (all->b[i] < all->b[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	b_max_at_top(t_all *all)
{
	int	i;

	i = 0;
	found_min_max(all);
	if (all->data.b_len > 0)
	{
		while (all->b[i] != all->data.b_max)
			i++;
		rotation_b(all, i);
	}
	rotate_all(all);
}
