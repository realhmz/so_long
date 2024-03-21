#include <CoreAudio/CoreAudio.h>
#include <AudioToolbox/AudioToolbox.h>

void audioQueueOutputCallback(void *inUserData, AudioQueueRef inAQ, AudioQueueBufferRef inBuffer) {
	// This is the callback function that will be called when the audio queue needs more data to play.
	// You can fill inBuffer with audio data here.
}

int sound() {
	// Specify the audio file path
	CFURLRef fileURL = CFURLCreateWithFileSystemPath(kCFAllocatorDefault, CFSTR("start.wav"), kCFURLPOSIXPathStyle, false);

	// Initialize an audio file
	AudioFileID audioFile;
	OSStatus status = AudioFileOpenURL(fileURL, kAudioFileReadPermission, 0, &audioFile);
	if (status != noErr) {
		// Handle error
		printf("Error opening audio file\n");
		return 1;
	}

	// Get the audio file format
	AudioStreamBasicDescription audioFormat;
	UInt32 propertySize = sizeof(audioFormat);
	status = AudioFileGetProperty(audioFile, kAudioFilePropertyDataFormat, &propertySize, &audioFormat);
	if (status != noErr) {
		// Handle error
		printf("Error getting audio file format\n");
		AudioFileClose(audioFile);
		return 1;
	}

	// Create a new audio queue
	AudioQueueRef audioQueue;
	status = AudioQueueNewOutput(&audioFormat, audioQueueOutputCallback, NULL, NULL, NULL, 0, &audioQueue);
	if (status != noErr) {
		// Handle error
		printf("Error creating audio queue\n");
		AudioFileClose(audioFile);
		return 1;
	}

	// Define a buffer for audio data
	const int bufferSize = 4096;
	AudioQueueBufferRef buffer;
	AudioQueueAllocateBuffer(audioQueue, bufferSize, &buffer);

	// Read audio data into the buffer
	UInt32 numBytesRead = bufferSize;
	status = AudioFileReadBytes(audioFile, false, 0, &numBytesRead, buffer->mAudioData);
	if (status != noErr) {
		// Handle error
		printf("Error reading audio data\n");
		AudioQueueDispose(audioQueue, true);
		AudioFileClose(audioFile);
		return 1;
	}

	// Enqueue the buffer
	buffer->mAudioDataByteSize = numBytesRead;
	AudioQueueEnqueueBuffer(audioQueue, buffer, 0, NULL);

	// Start the audio queue
	AudioQueueStart(audioQueue, NULL);

	// Wait for the audio to finish playing
	sleep(5); // Adjust the sleep duration according to the audio duration

	// Cleanup
	AudioQueueDispose(audioQueue, true);
	AudioFileClose(audioFile);
	CFRelease(fileURL);

	return 0;
}
