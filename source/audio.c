#include "get_next_line.h"
 



int play_song(int i)
{
	int id = fork();
    if (id == 0) {
        execl("/usr/bin/afplay", "afplay", "start.wav", NULL);
        perror("execl");
        return 1;
    } else {
        printf("Parent process\n");
    }
	
}

int play_kill(int i)
{
	int id = fork();
	if (id == 0) {
		execl("/usr/bin/afplay", "afplay", "kill.mp3", NULL);
		perror("execl");
		return 1;
	} else {
		printf("Parent process\n");
	}
	
}
void play_open_door()
{
	int id = fork();
	if (id == 0) {
		execl("/usr/bin/afplay", "afplay", "door.mp3", NULL);
		perror("execl");
		exit(1);
	} else {
		printf("Parent process\n");
	}
	
}	
void stop_audio()
{
	system("killall afplay");
}