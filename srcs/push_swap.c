/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:20:43 by gmorange          #+#    #+#             */
/*   Updated: 2021/09/08 15:53:47 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	move(t_all *all)
{
	int	i;

	i = 0;
	while (all->a[i] != all->op.intest)
		i++;
	rotation_a(all, i);
	perfect_spot_at_the_top(all, all->op.intest);
}

void	good_sort(t_all *all)
{
	found_min_max(all);
	if (all->data.a_len == 2 && is_a_sorted(all) == 1)
		operation(all, "sa");
	else if (all->data.a_len == 3 && is_a_sorted(all) == 1)
		three_sort(all);
	else if (all->data.a_len <= 5 && is_a_sorted(all) == 1)
		five_sort(all);
	else if (is_a_sorted(all) == 1)
	{
		operation(all, "pb");
		while (all->data.a_len > 0)
		{
			test_all_bis(all);
			move(all);
			rotate_all(all);
			operation(all, "pb");
		}
		b_max_at_top(all);
		while (all->data.b_len > 0)
			operation(all, "pa");
	}
}

int	main(int ac, char **av)
{
	t_all	all;

	init_all(&all, ac);
	check_pile(ac, av, &all);
	good_sort(&all);
	destroy_all(&all);
}
