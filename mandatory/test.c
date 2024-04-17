#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

void playMusic() {
    // Initialize SDL audio
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("Failed to initialize SDL audio: %s\n", SDL_GetError());
        return;
    }

    // Load music file
    Mix_Chunk *wav = Mix_LoadWAV("start.wav");
    if (wav == NULL) {
        printf("Error loading WAV file: %s\n", Mix_GetError());
        SDL_Quit();
        return;
    }

    // Open audio device
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("Failed to open audio: %s\n", Mix_GetError());
        Mix_FreeChunk(wav);
        SDL_Quit();
        return;
    }

    // Play audio
    if (Mix_PlayChannel(-1, wav, 0) == -1) {
        printf("Failed to play audio: %s\n", Mix_GetError());
        Mix_FreeChunk(wav);
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }

    // Wait for audio to finish playing
    SDL_Delay(Mix_ChunkLength(wav));

    // Clean up
    Mix_FreeChunk(wav);
    Mix_CloseAudio();
    SDL_Quit();
}


int main() {
    // Initialize MiniLibX and other game initialization here

    // Play music when the game starts
    playMusic();

    // Run the game loop and other game logic here

    return 0;
}
