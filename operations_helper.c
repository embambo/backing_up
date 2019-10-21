/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embambo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:59:14 by embambo           #+#    #+#             */
/*   Updated: 2019/10/01 13:25:01 by embambo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		operations_h(t_array *array)
{
	ft_rra(array);
	ft_pa(array);
	ft_ra(array);
	ft_ra(array);
}

void		operations_h2(t_array *array)
{
	ft_rra(array);
	ft_rra(array);
	ft_pa(array);
	ft_ra(array);
	ft_ra(array);
	ft_ra(array);
}

void		operations_h1(t_array *array)
{
	ft_pa(array);
	ft_ra(array);
}

void		operations_h3(t_array *array)
{
	ft_pa(array);
	ft_sa(array);
}
