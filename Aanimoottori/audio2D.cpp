#include "audio2D.h"
#include "SoundController.h"
#include <gorilla\ga.h>
#include <gorilla\gau.h>
#include "Listener.h"

Audio2D::Audio2D(const char* filePath, SoundController* soundController, bool stream, bool looping):
filePath(filePath)
{
	this->soundController = soundController;
	if (stream) {
		this->handle = soundController->getStreamingHandleFromSoundFile(filePath, looping);
	}
	else {
		this->handle = soundController->getRegularHandleFromSoundFile(filePath, looping);
	}
}

Audio2D::~Audio2D(){
	ga_handle_destroy(handle);
}

void Audio2D::play()
{
	ga_handle_play(handle);
}

void Audio2D::stop()
{
	ga_handle_stop(handle);
}

void Audio2D::update(Listener* listener)
{

}

void Audio2D::setVolume(double volume)
{
	if (0 <= volume <= 1) {
		ga_handle_setParamf(handle, GA_HANDLE_PARAM_GAIN, volume);
	}
}

void Audio2D::setPanning(double panning)
{
	if (-1 <= panning <= 1) {
		ga_handle_setParamf(handle, GA_HANDLE_PARAM_PAN, panning);
	}
}

void Audio2D::setPitch(double pitch)
{
	if (0 <= pitch <= 16) {
		ga_handle_setParamf(handle, GA_HANDLE_PARAM_PITCH, pitch);
	}
}
}
