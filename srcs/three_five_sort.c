/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:03:07 by gmorange          #+#    #+#             */
/*   Updated: 2021/09/08 16:39:15 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	three_sort(t_all *all)
{
	if (all->a[0] == all->data.a_max)
		operation(all, "ra");
	if (all->a[1] == all->data.a_max)
		operation(all, "rra");
	if (all->a[0] > all->a[1])
		operation(all, "sa");
}

int	push_to_b(t_all *all, int i)
{
	rotation_a(all, i);
	rotate_all(all);
	operation(all, "pb");
	return (i);
}

void	five_sort(t_all *all)
{
	int	i;

	i = 0;
	found_min_max(all);
	while (i < all->data.a_len)
	{
		if (all->a[i] == all->data.a_min)
			i = push_to_b(all, i);
		i++;
	}
	if (all->data.a_len == 4)
	{
		i = 0;
		found_min_max(all);
		while (i < all->data.a_len)
		{
			if (all->a[i] == all->data.a_min)
				i = push_to_b(all, i);
			i++;
		}
	}
	three_sort(all);
	while (all->data.b_len > 0)
		operation(all, "pa");
}
