#include <math.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>


// Maximum data buffers we will need.
#define NUM_BUFFERS 2

// Maximum emissions we will need.
#define NUM_SOURCES 2

// These index the buffers and sources.
#define explosao 0
#define musica  1

// Buffers hold sound data.
ALuint Buffers[NUM_BUFFERS];

// Sources are points of emitting sound.
ALuint Sources[NUM_SOURCES];

// Position of the source sounds.
ALfloat SourcesPos[NUM_SOURCES][3];

// Velocity of the source sounds.
ALfloat SourcesVel[NUM_SOURCES][3];

// Position of the listener.
ALfloat ListenerPos[] = { 0.0, 0.0, 0.0 };

// Velocity of the listener.
ALfloat ListenerVel[] = { 0.0, 0.0, 0.0 };

// Orientation of the listener. (first 3 elements are "at", second 3 are "up")
ALfloat ListenerOri[] = { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0 };

/*
 * ALboolean LoadALData()
 *
 *	This function will load our sample data from the disk using the alut
 *	utility and send the data into OpenAL as a buffer. A source is then
 *	also created to play that buffer.
 */
ALboolean LoadALData(){
	// Variables to load into.
	ALenum format;
	ALsizei size;
	ALvoid* data;
	ALsizei freq;
	ALboolean loop;

	// Load wav data into buffers.
	alGenBuffers(NUM_BUFFERS, Buffers);

	if(alGetError() != AL_NO_ERROR)	return AL_FALSE;

	alutLoadWAVFile("explosao.wav", &format, &data, &size, &freq, &loop);
	alBufferData(Buffers[explosao], format, data, size, freq);
	alutUnloadWAV(format, data, size, freq);

	alutLoadWAVFile("CepoMadeiraREMIX.wav", &format, &data, &size, &freq, &loop);
	alBufferData(Buffers[musica], format, data, size, freq);
	alutUnloadWAV(format, data, size, freq);

	// Bind buffers into audio sources.
	alGenSources(NUM_SOURCES, Sources);

	if(alGetError() != AL_NO_ERROR) return AL_FALSE;

	alSourcei (Sources[explosao], AL_BUFFER,   Buffers[explosao]   );
	alSourcef (Sources[explosao], AL_PITCH,    1.0f              );
	alSourcef (Sources[explosao], AL_GAIN,     1.0f              );
	alSourcefv(Sources[explosao], AL_POSITION, SourcesPos[explosao]);
	alSourcefv(Sources[explosao], AL_VELOCITY, SourcesVel[explosao]);
	alSourcei (Sources[explosao], AL_LOOPING,  AL_FALSE          );

	alSourcei (Sources[musica], AL_BUFFER,   Buffers[musica]   );
	alSourcef (Sources[musica], AL_PITCH,    1.0f            );
	alSourcef (Sources[musica], AL_GAIN,     1.0f            );
	alSourcefv(Sources[musica], AL_POSITION, SourcesPos[musica]);
	alSourcefv(Sources[musica], AL_VELOCITY, SourcesVel[musica]);
	alSourcei (Sources[musica], AL_LOOPING,  AL_FALSE        );

	// Do another error check and return.
	if(alGetError() != AL_NO_ERROR) return AL_FALSE;

	return AL_TRUE;
}

/*
 * void SetListenerValues()
 *
 *	We already defined certain values for the listener, but we need
 *	to tell OpenAL to use that data. This function does just that.
 */
void SetListenerValues(){
	alListenerfv(AL_POSITION,    ListenerPos);
	alListenerfv(AL_VELOCITY,    ListenerVel);
	alListenerfv(AL_ORIENTATION, ListenerOri);
}

/*
 * void KillALData()
 *
 *	We have allocated memory for our buffers and sources which needs
 *	to be returned to the system. This function frees that memory.
 */
void KillALData(){
	alDeleteBuffers(NUM_BUFFERS, Buffers);
	alDeleteSources(NUM_SOURCES, Sources);
	alutExit();
}
