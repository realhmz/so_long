#include <SDL/SDL.h>

int main() {
    SDL_Init(SDL_INIT_AUDIO);
    SDL_AudioSpec wavSpec;
    Uint8 *wavBuffer;
    Uint32 wavLength;

    if (SDL_LoadWAV("../start.wav", &wavSpec, &wavBuffer, &wavLength) == NULL) {
        printf("Error loading WAV file: %s\n", SDL_GetError());
        return 1;
    }

    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    if (deviceId == 0) {
        printf("Failed to open audio device: %s\n", SDL_GetError());
        SDL_FreeWAV(wavBuffer);
        return 1;
    }

    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    if (success != 0) {
        printf("Failed to queue audio: %s\n", SDL_GetError());
        SDL_CloseAudioDevice(deviceId);
        SDL_FreeWAV(wavBuffer);
        return 1;
    }

    SDL_PauseAudioDevice(deviceId, 0);  // Start playing audio

    // Wait for audio to finish playing
    SDL_Delay((wavLength / (wavSpec.freq * wavSpec.channels)) * 1000);

    // Clean up
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_Quit();

    return 0;
}
