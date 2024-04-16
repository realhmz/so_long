#include "get_next_line.h"
 



int play_song(int i)
{
	int id = fork();
    if (id == 0) {
        execl("/usr/bin/afplay", "afplay –quiet", "tg3d.mp3", NULL);
        // perror("execl");
    // } else {
        // printf("Parent process\n");
    }
    return 1;
	
}

int play_kill(int i)
{
	int id = fork();
	if (id == 0) {
		execl("/usr/bin/afplay", "afplay", "ha9.mp3", NULL);
		// perror("execl");
	// } else {
		// printf("Parent process\n");
	}
	i++;
	return 1;
	
}
void play_open_door()
{
	int id = fork();
	if (id == 0) {
		execl("/usr/bin/afplay", "afplay", "door.mp3", NULL);
		// perror("execl");
		exit(1);
	// } else {
		// printf("Parent process\n");
	}
	
}
void play_end()
{
	int id = fork();
	if (id == 0) {
		execl("/usr/bin/afplay", "afplay", "end.mp3", NULL);
		// perror("execl");
		exit(1);
	// } else {
		// printf("Parent process\n");
	}
	return;
	
}
void stop_audio()
{
	system("killall afplay");
}