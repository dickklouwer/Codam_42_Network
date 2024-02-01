/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 10:24:07 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/10/25 10:55:36 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack, int stack_in)
{
	t_stack	*s_next;

	s_next = (*stack)->next;
	if (s_next->next != NULL && (*stack)->next != NULL)
	{
		(*stack)->next = s_next->next;
		s_next->next = *stack;
		*stack = s_next;
	}
	if (stack_in == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	return ;
}

void	rotate_ab(t_stack **stack, int stack_in)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack)
		return ;
	first = *stack;
	last = ft_stcklast(*stack);
	*stack = first->next;
	last->next = first;
	first->next = NULL;
	if (stack_in == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	r_rotate_ab(t_stack **stack, int stack_in)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*temp;

	last = *stack;
	first = *stack;
	while (last->next->next != NULL)
		last = last->next;
	temp = last->next;
	temp->next = first;
	*stack = temp;
	last->next = NULL;
	if (stack_in == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	push_ab(t_stack **src, t_stack **dst, int stack_in)
{
	t_stack	*temp;

	temp = (*src);
	if (!(*src))
		return ;
	if (temp->next)
		(*src) = temp->next;
	else
		(*src) = NULL;
	temp->next = *dst;
	(*dst) = temp;
	if (stack_in == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	return ;
}
