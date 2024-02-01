/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 10:55:36 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/10/25 10:54:30 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stcknew(int content)
{
	t_stack	*new;

	new = (void *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stcklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_stckadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_stcklast(*stack);
	last->next = new;
}

void	ft_putstack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->content, 1);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	write(1, "-----", 5);
	write(1, "\n\n", 3);
}
