/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:22:11 by gmorange          #+#    #+#             */
/*   Updated: 2021/09/09 10:40:46 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_data
{
	int	a_max;
	int	a_min;
	int	b_max;
	int	b_min;
	int	a_len;
	int	b_len;
}				t_data;

typedef struct s_op
{
	int	count;
	int	intest;
	int	least_op;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}				t_op;

typedef struct s_all
{
	t_data	data;
	t_op	op;
	int		*a;
	int		*b;
	int		*a_bis;
	int		*b_bis;
	char	*temp;
}				t_all;

void	copy_to_bis(t_all *all);
void	rotate_all_bis(t_all *all);
void	test_all_bis(t_all *all);
void	min_max_a(t_all *all);
void	min_max_b(t_all *all);
void	operation(t_all *all, char *instruction);
void	operation_bis(t_all *all, char *instruction);
void	found_min_max(t_all *all);
void	destroy_all(t_all *all);
void	error_param(t_all *all, int i);
void	add_to_stack_a(t_all *all, int nbr, int i);
void	init_all(t_all *all, int ac);
void	check_pile(int ac, char **av, t_all *all);
int		found_perfect_spot(t_all *all, int i, int to_test);
void	perfect_spot_at_the_top(t_all *all, int to_test);
void	push(int *taker, int *taker_len, int *receiver, int *receiver_len);
void	p_push(t_all *all, char *instruction);
void	move(t_all *all);
void	good_sort(t_all *all);
int		main(int ac, char **av);
void	reverse_rotade(int *pile, int len);
void	r_reverse_rotade(t_all *all, char *instruction);
void	reverse_rotade_bis(int *pile, int len);
void	r_reverse_rotade_bis(t_all *all, char *instruction);
void	rotade(int *pile, int len);
void	r_rotade(t_all *all, char *instruction);
void	rotade_bis(int *pile, int len);
void	r_rotade_bis(t_all *all, char *instruction);
int		swap(int *tab);
void	s_swap(t_all *all, char *instruction);
void	three_sort(t_all *all);
int		push_to_b(t_all *all, int i);
void	five_sort(t_all *all);
void	move_up(int *pile, int len);
void	move_down(int *pile, int len);
int		is_a_sorted(t_all *all);
int		is_b_sorted(t_all *all);
void	b_max_at_top(t_all *all);
void	rotate_all(t_all *all);
void	rotation_a(t_all *all, int i);
void	rotation_b(t_all *all, int i);

#endif
