/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 11:44:39 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/10/25 11:00:19 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_index(t_stack **s, int position, int index)
{
	t_stack	*temp;

	temp = (*s);
	while (position > 0)
	{
		temp = temp->next;
		position--;
	}
	temp->index = index;
}

static int	get_index_position(t_stack **s)
{
	t_stack	*temp;
	int		current;
	int		position;
	int		min;

	current = 0;
	min = INT_MIN;
	temp = (*s);
	while (temp != NULL)
	{
		if (temp->index == -1)
		{
			if (temp->content >= min)
			{
				min = temp->content;
				position = current;
			}
		}
		temp = temp->next;
		current++;
	}
	return (position);
}

void	index_stack(t_stack **s)
{
	int	s_len;
	int	position;

	s_len = stack_len(*s);
	while (s_len > 0)
	{
		position = get_index_position(s);
		if (position == -1)
			break ;
		set_index(s, position, s_len);
		s_len--;
	}
}
