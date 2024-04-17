#include "get_next_line.h"
 



void play_song()
{
	int id = fork();
    if (id == 0) {
        execl("/usr/bin/afplay", "afplay", "riseup.mp3", NULL);
        // perror("execl");
    // } else {
        // printf("Parent process\n");
    }	
}

void play_kill()
{
	int id = fork();
	if (id == 0) {
		execl("/usr/bin/afplay", "afplay", "ha9.mp3", NULL);
		// perror("execl");
	// } else {
		// printf("Parent process\n");
	}
	
}
void play_open_door()
{
	int id = fork();
	if (id == 0) {
		execl("/usr/bin/afplay", "afplay", "door.mp3", NULL);
		// perror("execl");
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
	// } else {
		// printf("Parent process\n");
	}
	
}
void stop_audio()
{
	system("killall afplay");
}