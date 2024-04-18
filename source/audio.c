// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   audio.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/04/18 14:52:38 by het-taja          #+#    #+#             */
// /*   Updated: 2024/04/18 14:52:39 by het-taja         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// void	sound_assets(t_sound *s)
// {
// 	s->start = malloc(sizeof(char *) * 6);
// 	s->start[0] = "./sound/start/1.mp3";
// 	s->start[1] = "./sound/start/2.mp3";
// 	s->start[2] = "./sound/start/3.mp3";
// 	s->start[3] = "./sound/start/4.mp3";
// 	s->start[4] = "./sound/start/5.mp3";
// 	s->start[5] = NULL;
// 	s->walk = "./sound/walk.mp3";
// 	s->kill = malloc(sizeof(char *) * 4);
// 	s->kill[0] = "./sound/kill/1.mp3";
// 	s->kill[1] = "./sound/kill/2.mp3";
// 	s->kill[2] = "./sound/kill/3.mp3";
// 	s->kill[3] = NULL;
// 	s->open_door = "./sound/door.mp3";
// 	s->enemy = malloc(sizeof(char *) * 4);
// 	s->enemy[0] = "./sound/enemy/1.mp3";
// 	s->enemy[1] = "./sound/enemy/2.mp3";
// 	s->enemy[2] = "./sound/enemy/3.mp3";
// 	s->enemy[3] = NULL;
// 	s->end = malloc(sizeof(char *) * 3);
// 	s->end[0] = "./sound/end/2.mp3";
// 	s->end[1] = "./sound/end/3.mp3";
// 	s->end[2] = NULL;
// 	s->walk = malloc(sizeof(char) * 16);
// 	s->walk = "./sound/walk.mp3";
// }

// void	play_song(t_sound *s)
// {
// 	int	id;
// 	int	i;

// 	id = fork();
// 	i = 0;
// 	srand(time(NULL));
// 	i = rand();
// 	i = i % 5;
// 	if (id == 0)
// 	{
// 		execl("/usr/bin/afplay", "aplay", s->start[i], NULL);
// 	}
// }
// void	play_walk(t_sound *s)
// {
// 	int	id;

// 	id = fork();
// 	srand(time(NULL));
// 	if (id == 0)
// 	{
// 		execl("/usr/bin/afplay", "aplay", s->walk, NULL);
// 	}
// }

// void	play_kill(t_sound *s)
// {
// 	int	id;
// 	int	i;

// 	id = fork();
// 	i = 0;
// 	srand(time(NULL));
// 	i = rand();
// 	i = i % 3;
// 	if (id == 0)
// 	{
// 		execl("/usr/bin/afplay", "aplay", s->kill[i], NULL);
// 	}
// }
// void	play_open_door(t_sound *s)
// {
// 	int	id;

// 	id = fork();
// 	if (id == 0)
// 	{
// 		execl("/usr/bin/afplay", "aplay", s->open_door, NULL);
// 	}
// }
// void	play_enemy(t_sound *s)
// {
// 	int	id;
// 	int	i;

// 	id = fork();
// 	i = 0;
// 	srand(time(NULL));
// 	i = rand();
// 	i = i % 3;
// 	if (id == 0)
// 	{
// 		execl("/usr/bin/afplay", "aplay", s->enemy[i], NULL);
// 	}
// }
// void	play_end(t_sound *s)
// {
// 	int	id;
// 	int	i;

// 	id = fork();
// 	i = 0;
// 	srand(time(NULL));
// 	i = rand();
// 	i = i % 2;
// 	printf("%d\n\n", i);
// 	if (id == 0)
// 	{
// 		execl("/usr/bin/afplay", "aplay", s->end[i], NULL);
// 	}
// }

// void	stop_audio(void)
// {
// 	system("killall afplay");
// }