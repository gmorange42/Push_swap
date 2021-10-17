/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:06:03 by gmorange          #+#    #+#             */
/*   Updated: 2021/07/29 14:20:54 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	swap(int *tab)
{
	int	temp;

	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
	return (1);
}

void	s_swap(t_all *all, char *instruction)
{
	int	ret;

	ret = 0;
	if (ft_strcmp(instruction, "sa") == 0 && all->data.a_len > 1)
		ret = swap(all->a);
	else if (ft_strcmp(instruction, "sb") == 0 && all->data.b_len > 1)
		ret = swap(all->b);
	else if (ft_strcmp(instruction, "ss") == 0 \
			&& all->data.a_len > 1 && all->data.b_len > 1)
	{
		ret = swap(all->a);
		ret = swap(all->b);
	}
	if (ret == 1)
	{
		ft_putstr(instruction);
		ft_putchar('\n');
	}
}
