/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_best_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:22:06 by gmorange          #+#    #+#             */
/*   Updated: 2021/09/09 10:35:16 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	copy_to_bis(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data.a_len)
	{
		all->a_bis[i] = all->a[i];
		i++;
	}
	i = 0;
	while (i < all->data.b_len)
	{
		all->b_bis[i] = all->b[i];
		i++;
	}
}

void	rotate_all_bis(t_all *all)
{
	while (all->op.ra > 0 && all->op.rb > 0)
	{
		operation_bis(all, "rr");
		all->op.ra--;
		all->op.rb--;
	}
	while (all->op.ra-- > 0)
		operation_bis(all, "ra");
	while (all->op.rb-- > 0)
		operation_bis(all, "rb");
	while (all->op.rra > 0 && all->op.rrb > 0)
	{
		operation_bis(all, "rrr");
		all->op.rra--;
		all->op.rrb--;
	}
	while (all->op.rra-- > 0)
		operation_bis(all, "rra");
	while (all->op.rrb-- > 0)
		operation_bis(all, "rrb");
}

void	test_all_bis(t_all *all)
{
	int	i;
	int	to_test;

	i = 0;
	all->op.least_op = -1;
	while (i < all->data.a_len)
	{
		all->op.count = 0;
		copy_to_bis(all);
		to_test = all->a[i];
		rotation_a(all, i);
		perfect_spot_at_the_top(all, to_test);
		rotate_all_bis(all);
		if (all->op.least_op < 0)
		{
			all->op.least_op = all->op.count;
			all->op.intest = to_test;
		}
		if (all->op.count < all->op.least_op)
		{
			all->op.least_op = all->op.count;
			all->op.intest = to_test;
		}
		i++;
	}
}
