/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_prime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:31:19 by thibaud           #+#    #+#             */
/*   Updated: 2024/06/13 17:13:12 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static inline _Bool _is_prime(int num)
{
	int devider;

	devider = 2;
	if (num == 3)
		return (1);
	if (num == 4)
		return (0);
	while (devider * devider <= num)
	{
		if (num % devider == 0)
			return (0);
		++devider;
	}
	return (1);	
}

size_t	_sum_prime(void)
{
	size_t	sum;
	size_t	num;

	sum = 2;
	num = 3;
	while (num < 2000000)
	{
		if (_is_prime(num))
			sum += num;
		++num;
	}
	return (sum);
}

int	main(void)
{
	printf("result is %ld\n", _sum_prime());
	return (1);
}