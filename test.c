/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:11:38 by stelie            #+#    #+#             */
/*   Updated: 2023/01/25 17:26:35 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	wesh = 42;
static bool exit_status = false;

//SOUS FONCTION POUR SIGNALS
static void	_trigger(int sig)
{
	if (sig == SIGQUIT)
		exit_status = true;
}

//FONCTION POUR ARRETER PROPREMENT LE PROGRAMME
static void	_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGQUIT, _trigger);
}

//THREAD UN
static void	*routine_one(void *p_data)
{
	(void)p_data;
	while (exit_status == false)
	{
		wesh++;
		//usleep(30000);
		printf("COUCOU! JE SUIS LE THREAD NUMERO UN ! %i\n",  wesh);
	}
	return (NULL);
}

//THREAD DEUX
static void	*routine_two(void *p_data)
{
	(void)p_data;
	while (exit_status == false)
	{
		wesh--;
		//usleep(30000);
		printf("SALUT! JE SUIS LE THREAD NUMERO DEUX !%i\n", wesh);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	one; //on créé un thread
	pthread_t	two; //on créé un thread

	_signal();  //Pour utiliser les signaux définis (ici c'est 'CTRL + \')
	if (pthread_create(&one, NULL, routine_one, NULL) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pthread_create(&two, NULL, routine_two, NULL) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	pthread_join (one, NULL);    //dit au main d'attendre la fin du thread "one"
	pthread_join (two, NULL);    //dit au main d'attendre la fin du thread "two"
	printf("\nHello World!\n");
	return (EXIT_SUCCESS);
}
