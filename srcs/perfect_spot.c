/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_spot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:50:39 by gmorange          #+#    #+#             */
/*   Updated: 2021/09/08 16:11:06 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	found_perfect_spot(t_all *all, int i, int to_test)
{
	if (i < all->data.b_len)
	{
		while (to_test > all->b[i])
		{
			i++;
			if (i >= all->data.b_len)
				break ;
		}
	}
	if (i < all->data.b_len)
	{
		while (to_test < all->b[i])
		{
			i++;
			if (i >= all->data.b_len)
				break ;
		}
	}
	return (i);
}

void	perfect_spot_at_the_top(t_all *all, int to_test)
{
	int	i;

	i = 0;
	found_min_max(all);
	if (all->data.b_len > 0)
	{
		if (to_test > all->data.b_max)
			while (all->b[i] != all->data.b_max)
				i++;
		else if (to_test < all->data.b_min)
		{
			while (all->b[i] != all->data.b_min)
				i++;
			i++;
		}
		else
			i = found_perfect_spot(all, i, to_test);
	}
	rotation_b(all, i);
}
