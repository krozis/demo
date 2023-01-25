/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:11:38 by stelie            #+#    #+#             */
/*   Updated: 2023/01/25 17:11:05 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	wesh = 42;

void	*routine_one(void *p_data)
{
	(void)p_data;
	while (1)
	{
		wesh++;
		//usleep(30000);
		printf("COUCOU! JE SUIS LE THREAD NUMERO UN ! %i\n",  wesh);
	}
	return (NULL);
}

void	*routine_two(void *p_data)
{
	(void)p_data;
	while (1)
	{
		wesh--;
		//usleep(30000);
		printf("SALUT! JE SUIS LE THREAD NUMERO DEUX !%i\n", wesh);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	one;
	pthread_t	two;

	if (pthread_create(&one, NULL, routine_one, NULL) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pthread_create(&two, NULL, routine_two, NULL) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	printf("Hello world\n");
	pthread_join (one, NULL);
	pthread_join (two, NULL);
	return (EXIT_SUCCESS);
}
