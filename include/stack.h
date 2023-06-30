/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:09:14 by gaollier          #+#    #+#             */
/*   Updated: 2023/06/30 11:14:28 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

struct	s_stack
{
	int				nb;
	int				index;
	struct s_stack	*next;
};

typedef struct s_stack	t_stack;

t_stack	*stack_new_element(int nb, int index);
int		stack_add_front(t_stack **stack, t_stack *new_element);
t_stack	*last_element(t_stack *stack);
int		stack_add_back(t_stack **stack, t_stack *new_element);
int		stack_size(t_stack *stack);
int		stack_swap(t_stack **stack);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		stack_push(t_stack **stack_src, t_stack **stack_dest);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		stack_rotate(t_stack **stack);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		stack_reverse_rotate(t_stack **stack);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);
int		reverse_stack(t_stack **stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
int		stack_init(int argc, char **argv, t_stack **stack_a);
int		stack_is_sorted(t_stack *stack, char order);
void	print_stack(t_stack *stack);
void	free_stack(t_stack **stack);
void	exit_error(void);
void	ft_sort_3(t_stack **stack);
void	ft_sort_5(t_stack **stack_a, t_stack **stack_b);
#endif
