/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:32:05 by kmira             #+#    #+#             */
/*   Updated: 2019/06/26 02:40:58 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define DEBUG 1
#define UNIT (float)100

int		points_converge(float real_value, float imaginary_value, int print, float actual_real, float actual_imaginary)
{
	float result;


	if (-1.3 < 2 * imaginary_value * real_value + actual_imaginary && 2 * imaginary_value * real_value + actual_imaginary < 1.3)
	{
		result = real_value * real_value - imaginary_value * imaginary_value + real_value;
		if (print && DEBUG)
		{
			printf(" VAL1: (%.2f, %.2f) PASSED: (%.2f, %.2f)",
			result,
			2 * imaginary_value * real_value + imaginary_value,
			real_value,
			imaginary_value);
			print++;
		}
		if (-1.3 < result && result < 1.3)
			return (1);
	}
	if (print && DEBUG)
		printf(" VAL2: (%.2f, %.2f)",
		real_value * real_value - imaginary_value * imaginary_value + actual_imaginary,
		2 * imaginary_value * real_value + imaginary_value);
	(void)print;
	return (0);
}

int		fractal_function(int real_value, int imaginary_value, int print)
{
	int		result;
	int		record;
	float	real_value_copy;
	float	imaginary_value_copy;
	float	real_value_copy_copy;

	result = 0;

	record = 0;
	real_value_copy = real_value / UNIT;
	imaginary_value_copy = imaginary_value / UNIT;
	while (real_value_copy * real_value_copy + imaginary_value_copy * imaginary_value_copy < 4 && result < 10)
	{
		if (points_converge(real_value_copy, imaginary_value_copy, print, real_value / UNIT, imaginary_value / UNIT) == 0)
		{
			return (result * 4);
		}
		real_value_copy_copy = real_value_copy;
		real_value_copy = real_value_copy * real_value_copy - imaginary_value_copy * imaginary_value_copy + real_value / UNIT;
		imaginary_value_copy = 2 * real_value_copy_copy * imaginary_value_copy + imaginary_value / UNIT;
		result++;
	}
	return (result * 4);
}

int main(void)
{
	float a;
	float b;
	a = 30;
	b = 0;

	printf("AT: (%.2f, %.2f)", a / UNIT, b / UNIT);
	fractal_function(a, b, 1);
}
