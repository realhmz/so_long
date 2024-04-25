/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:38 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/25 17:30:50 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	sound_assets(t_sound *s)
{
	s->kill = malloc(sizeof(char *) * 4);
	s->kill[0] = "./sound/kill/1.mp3";
	s->kill[1] = "./sound/kill/2.mp3";
	s->kill[2] = "./sound/kill/3.mp3";
	s->kill[3] = NULL;
	s->enemy = malloc(sizeof(char *) * 4);
	s->enemy[0] = "./sound/enemy/1.mp3";
	s->enemy[1] = "./sound/enemy/2.mp3";
	s->enemy[2] = "./sound/enemy/3.mp3";
	s->enemy[3] = NULL;
	s->end = malloc(sizeof(char *) * 3);
	s->end[0] = "./sound/end/2.mp3";
	s->end[1] = "./sound/end/3.mp3";
	s->end[2] = NULL;
}

void	play_song(void)
{
	int	id;
	int	i;

	id = fork();
	i = 0;
	srand(time(NULL));
	i = rand();
	i = i % 5;
	if (id == 0)
	{
		execl("/usr/bin/afplay", "afplay", "./sound/start.wav", NULL);
	}
}

void	play_walk(void)
{
	static int i  = 0;
	int	id;

	id = fork();
	srand(time(NULL));
	if (id == 0)
	{
		if (i % 2 == 0)
			execl("/usr/bin/afplay", "afplay", "./sound/walk/1.mp3", NULL);
		else
			execl("/usr/bin/afplay", "afplay", "./sound/walk/2.mp3", NULL);
		i++;
	}
}

void	play_kill(t_sound *s)
{
	int	id;
	int	i;

	id = fork();
	i = 0;
	srand(time(NULL));
	i = rand();
	i = i % 3;
	if (id == 0)
	{
		execl("/usr/bin/afplay", "afplay", s->kill[i], NULL);
	}
}

void	play_open_door(void)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		execl("/usr/bin/afplay", "afplay", "./sound/door.mp3", NULL);
	}
}

void	play_menu(void)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		execl("/usr/bin/afplay", "afplay","./sound/menu.mp3", NULL);
	}
}

void	play_enemy(t_sound *s)
{
	int	id;
	int	i;

	id = fork();
	i = 0;
	srand(time(NULL));
	i = rand();
	i = i % 3;
	if (id == 0)
	{
		execl("/usr/bin/afplay", "afplay", s->enemy[i], NULL);
	}
}

void	play_end(t_sound *s)
{
	int	id;
	int	i;

	id = fork();
	i = 0;
	srand(time(NULL));
	i = rand();
	i = i % 2;
	printf("%d\n\n", i);
	if (id == 0)
	{
		execl("/usr/bin/afplay", "afplay", s->end[i], NULL);
	}
}

void	stop_audio(void)
{
	system("killall afplay");
}