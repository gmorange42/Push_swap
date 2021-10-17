/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:29:27 by gmorange          #+#    #+#             */
/*   Updated: 2021/09/08 16:24:31 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	min_max_a(t_all *all)
{
	int	i;

	i = 0;
	if (all->data.a_len > 0)
	{
		all->data.a_min = all->a[0];
		all->data.a_max = all->a[0];
		while (i < all->data.a_len)
		{
			if (all->a[i] < all->data.a_min)
				all->data.a_min = all->a[i];
			if (all->a[i] > all->data.a_max)
				all->data.a_max = all->a[i];
			i++;
		}
	}
}

void	min_max_b(t_all *all)
{
	int	i;

	i = 0;
	if (all->data.b_len > 0)
	{
		all->data.b_min = all->b[0];
		all->data.b_max = all->b[0];
		i = 0;
		while (i < all->data.b_len)
		{
			if (all->b[i] < all->data.b_min)
				all->data.b_min = all->b[i];
			if (all->b[i] > all->data.b_max)
				all->data.b_max = all->b[i];
			i++;
		}
	}
}

void	found_min_max(t_all *all)
{
	min_max_a(all);
	min_max_b(all);
}
