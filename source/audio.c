#include "get_next_line.h"
 
void	sound_assets(t_sound *s)
{
	s->start = malloc(sizeof(char *) * 6);
	s->start[0] = "./sound/start/1.mp3";
	s->start[1] = "./sound/start/2.mp3";
	s->start[2] = "./sound/start/3.mp3";
	s->start[3] = "./sound/start/4.mp3";
	s->start[4] = "./sound/start/5.mp3";
	s->start[5] = NULL;
	s->walk = "./sound/walk.mp3";
	s->kill = malloc(sizeof(char *) * 4);
	s->kill[0] = "./sound/kill/1.mp3";
	s->kill[1] = "./sound/kill/2.mp3";
	s->kill[2] = "./sound/kill/3.mp3";
	s->kill[3] = NULL;
	s->open_door = "./sound/door.mp3";
	s->enemy = malloc(sizeof(char *) * 4);
	s->enemy[0] = "./sound/enemy/enemy/1.mp3";
	s->enemy[1] = "./sound/enemy/enemy/2.mp3";
	s->enemy[2] = "./sound/enemy/enemy/3.mp3";
	s->enemy[3] = NULL;
	s->end = malloc(sizeof(char *) * 3);
	s->end[0] = "./sound/end/2.mp3";
	s->end[1] = "./sound/end/3.mp3";
	s->end[2] = NULL;
	s->walk = malloc(sizeof(char) * 16);
	s->walk = "./sound/walk.mp3";
	
}

void play_song(t_sound *s)
{
	int id = fork();
	int i = 0;
	sound_assets(s);
    srand(time(NULL));
    i = rand();
    i = i % 5;
    if (id == 0) {
        execl("/usr/bin/afplay", "afplay", s->start[i], NULL);
    }	
}
void play_walk(t_sound *s)
{
	int id = fork();
	sound_assets(s);
	srand(time(NULL));
	if (id == 0) {
		execl("/usr/bin/afplay", "afplay",s->walk, NULL);
	}
	
}

void play_kill(t_sound *s)
{
	int id = fork();
	int i = 0;
	sound_assets(s);
	srand(time(NULL));
	i = rand();
	i = i % 3;
	if (id == 0) {
		execl("/usr/bin/afplay", "afplay", s->kill[i], NULL);
	}
	
}
void play_open_door(t_sound *s)
{
	int id = fork();
	sound_assets(s);
	if (id == 0) {
		execl("/usr/bin/afplay", "afplay", s->open_door, NULL);
	}
	
}
void play_enemy(t_sound *s)
{
	int id = fork();
	int i = 0;
	sound_assets(s);
	srand(time(NULL));
	i = rand();
	i = i % 5;
	if (id == 0) {
		execl("/usr/bin/afplay", "afplay", s->enemy[i], NULL);
	}
	
}
void play_end(t_sound *s)
{
	int id = fork();
	int i = 0;
	sound_assets(s);
	srand(time(NULL));
	i = rand();
	i = i % 3;
	if (id == 0) {
		execl("/usr/bin/afplay", "afplay", s->end[i], NULL);
	}
	
}

void stop_audio()
{
	system("killall afplay");
}