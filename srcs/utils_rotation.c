/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:14:05 by gmorange          #+#    #+#             */
/*   Updated: 2021/09/08 16:45:59 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rotate_all(t_all *all)
{
	while (all->op.ra > 0 && all->op.rb > 0)
	{
		operation(all, "rr");
		all->op.ra--;
		all->op.rb--;
	}
	while (all->op.ra-- > 0)
		operation(all, "ra");
	while (all->op.rb-- > 0)
		operation(all, "rb");
	while (all->op.rra > 0 && all->op.rrb > 0)
	{
		operation(all, "rrr");
		all->op.rra--;
		all->op.rrb--;
	}
	while (all->op.rra-- > 0)
		operation(all, "rra");
	while (all->op.rrb-- > 0)
		operation(all, "rrb");
}

void	rotation_a(t_all *all, int i)
{
	if (i > all->data.a_len / 2)
	{
		i = all->data.a_len - i;
		all->op.rra = i;
	}
	else
		all->op.ra = i;
}

void	rotation_b(t_all *all, int i)
{
	if (i > all->data.b_len / 2)
	{
		i = all->data.b_len - i;
		all->op.rrb = i;
	}
	else
		all->op.rb = i;
}
