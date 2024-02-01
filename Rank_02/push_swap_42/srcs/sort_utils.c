/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 08:42:42 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/10/25 11:14:52 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (EXIT_SUCCESS);
		stack = stack->next;
	}
	return (EXIT_FAILURE);
}

int	get_min_int(t_stack *s)
{
	t_stack	*temp;
	int		min;

	temp = (s);
	min = INT_MAX;
	while (temp)
	{
		if (min >= temp->content)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

int	get_max_int(t_stack *s)
{
	t_stack	*temp;
	int		max;

	temp = s;
	max = INT_MIN;
	while (temp->next != NULL)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	if (temp->content > max)
		max = temp->content;
	return (max);
}

int	stack_len(t_stack *s)
{
	int	i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}
