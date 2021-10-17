/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <gmorange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:11:38 by gmorange          #+#    #+#             */
/*   Updated: 2021/09/09 10:57:38 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	destroy_all(t_all *all)
{
	if (all->a != 0)
		free(all->a);
	if (all->b != 0)
		free(all->b);
	if (all->a_bis != 0)
		free(all->a_bis);
	if (all->b_bis != 0)
		free(all->b_bis);
	if (all->temp != 0)
		free(all->temp);
	exit(0);
}

void	error_param(t_all *all, int i)
{
	ft_putstr("Error\nWith parameter number ");
	ft_putnbr(i);
	ft_putchar('\n');
	destroy_all(all);
	exit(0);
}

void	add_to_stack_a(t_all *all, int nbr, int i)
{
	i--;
	all->a[i] = nbr;
	i--;
	while (i >= 0)
	{
		if (all->a[i] == nbr)
		{
			ft_putstr("Error\nthe elememt number ");
			ft_putnbr(i + 1);
			ft_putstr(" has a duplicate\n");
			destroy_all(all);
		}
		i--;
	}
	all->data.a_len++;
}

void	init_all(t_all *all, int ac)
{
	all->a = 0;
	all->b = 0;
	all->temp = 0;
	all->data.a_len = 0;
	all->data.b_len = 0;
	all->op.ra = 0;
	all->op.rb = 0;
	all->op.rra = 0;
	all->op.rrb = 0;
	all->a = malloc(sizeof(int) * (ac - 1));
	all->b = malloc(sizeof(int) * (ac - 1));
	all->a_bis = malloc(sizeof(int) * (ac - 1));
	all->b_bis = malloc(sizeof(int) * (ac - 1));
	if (all->a == 0 || all->b == 0)
		destroy_all(all);
}

void	check_pile(int ac, char **av, t_all *all)
{
	int	i;

	i = 1;
	if (ac < 2)
		exit(0);
	while (i < ac)
	{
		all->temp = ft_itoa(ft_atoi(av[i]));
		if (ft_strisonlyc(av[i], "-+0123456789") == -1)
			error_param(all, i);
		if (ft_strisonlyc(&av[i][1], "0123456789") == -1)
			error_param(all, i);
		if (av[i][0] == '+' && \
				ft_strcmp(all->temp, &av[i][1]) != 0)
			error_param(all, i);
		else if (ft_strcmp("-0", av[i]) != 0 && av[i][0] != '+' && \
				ft_strcmp(all->temp, av[i]) != 0)
			error_param(all, i);
		free(all->temp);
		all->temp = 0;
		add_to_stack_a(all, ft_atoi((av[i])), i);
		i++;
	}
}
