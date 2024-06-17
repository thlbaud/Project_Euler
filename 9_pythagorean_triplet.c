/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pythagorean_triplet.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:30:30 by thibaud           #+#    #+#             */
/*   Updated: 2024/06/13 16:33:25 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// a < b < c
// a² + b² = c²
// a + b + c = 1000

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

_Bool	check_order(int *triplet)
{
	if (triplet[0] < triplet[1] < triplet[2])
		return (1);
	return (0);
}

_Bool	check_square(int *triplet)
{
	if (triplet[0] * triplet[0] + triplet[1] * triplet[1] == triplet[2] * triplet[2])
		return (1);
	return (0);
}

_Bool	check_add(int *triplet)
{
	if (triplet[0]  + triplet[1] + triplet[2] == 1000)
		return (1);
	return (0);
}

int	*pythagorean_triplet(void)
{
	int	*triplet;
	
	triplet = malloc(sizeof(int) * 3);
	if (!triplet)
		return (NULL);
	triplet[2] = 2;
	while (triplet[2] < 500)
	{
		triplet[1] = 1;
		while (triplet[1] < triplet[2])
		{
			triplet[0] = 0;
			while (triplet[0] < triplet[1])
			{
				if (check_order(triplet) && check_add(triplet) && check_square(triplet))
					return (triplet);
				triplet[0] += 1;
			}
			triplet[1] += 1;
		}
		triplet[2] += 1;
	}
	return (free (triplet), NULL);
}

int	main(void)
{
	int	*result;

	result = pythagorean_triplet();
	if (!result)
		return (printf("No triplet for these conditions\n"), 0);
	printf("a = %d, b = %d, c = %d\n", result[0], result[1], result[2]);
	printf("result is %d\n", result[0] * result[1] * result[2]);
	free (result);
	return (1);
}