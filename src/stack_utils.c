/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaollier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:13:02 by gaollier          #+#    #+#             */
/*   Updated: 2023/06/30 11:32:25 by gaollier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "../include/stack.h"
#include "libft.h"

#define ASC 1
#define DESC 0

int	stack_is_sorted(t_stack *stack, char order)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (order == ASC && stack->nb > stack->next->nb)
			return (0);
		if (order == DESC && stack->nb < stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	print_stack(t_stack *stack)
{
	printf("-----------\n");
	while (stack != NULL)
	{
		printf("%d -> index: %u\n", stack->nb, stack->index);
		stack = stack->next;
	}
	printf("-----------\n");
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (stack == NULL || (*stack) == NULL)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(void)
{
	ft_putendl_fd("Error", 2);
	exit (1);
}
