/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muturk <muturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 03:32:07 by ogunesog          #+#    #+#             */
/*   Updated: 2025/04/21 06:20:07 by muturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>



// void	*ft_pthread_sleep(void *arg)
// {
	// 	printf("aaaaa \n");
	// }
	
	// void	ft_createthread(int number_of_philosophers, pthread_t *thread)
	// {
		// 	int	i;
		
		// 	i = 0;
		// 	while (i < number_of_philosophers)
		// 	{
			// 		if (pthread_create(&thread[i], NULL, ft_pthread_sleep, NULL) != 0)
			// 			return ;
			// 		i++;
			// 	}
			// 	i = 0;
			// 	while (i < number_of_philosophers)
			// 		pthread_join(thread[i++], NULL);
			// }
			
			// int main(int argc, char **argv)
			// {
				// 	pthread_t	*thread = malloc(sizeof(long) * atoi(argv[1]));
				
				
				// 	ft_createthread(atoi(argv[1]), thread);
				// 	//printf("%ld", *thread);
				// }
				
				
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct philosophers
{
	double	ph_time_to_sleep;
	double	ph_time_to_eat;
} ph;

void* ft_pthread_sleep(void* arg)
{
	if (!arg)
		return NULL;
	usleep(arg);
	printf("Thread uyudu! ID: %ld\n", (long)arg);
	return NULL;
}

void* ft_pthread_eat(void* arg)
{
	if (!arg)
		return NULL;
	usleep(arg);
	printf("Thread yedi! ID: %ld\n", (long)arg);
	return NULL;
}

void ft_createthread(int number_of_philosophers, pthread_t *threads)
{
	int i;

	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_create(&threads[i], NULL, NULL, NULL))
		{
			perror("Thread oluşturulamadı");
			return;
		}
		i++;
	}
	// Thread'lerin bitmesi bekleniyor
	for (int j = 0; j < number_of_philosophers; j++)
		pthread_join(threads[j], NULL);
}

int main(int argc, char **argv)
{
	int number_of_philosophers = atoi(argv[1]);
	// int	time_to_die = atof(argv[2]);
	// int	time_to_eat = atof(argv[3]);
	// int	time_to_sleep = atof(argv[4]);

	pthread_t *threads = malloc(sizeof(pthread_t) * number_of_philosophers);

	if (!threads)
	{
		perror("malloc hatası");
		return 1;
	}

	ft_createthread(number_of_philosophers, threads);
	int i = 0;
	while (i < 6)
	{
		ft_pthread_sleep(time_to_sleep);
		ft_pthread_eat(time_to_eat);
	}
	free(threads);
	return 0;
}

waiter
threadlerimiz izleyecek
threadlerin yemek yiyip yemeyeceğine karar vercek
threadler waitera çatalları alıp alamayacağını soracak
sorana cevap olarak izin verip ya da vermeyecek 

if ()
	ft_pthread_eat(thread[i]);


	void		waiter(strtcut thread)


adress ==== bu uygun;
	while (tüm threadleri dön)
	{time_to_die flag}
	if (flag == 1)
	{
		ft_pthread_eat
		waiter();
	}
	if




	i