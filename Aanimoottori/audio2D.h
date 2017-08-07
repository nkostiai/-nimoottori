#pragma once
#include <string>
#include "PlayableAudio.h"

struct ga_Handle;
class SoundController;

class Audio2D: public PlayableAudio{
public:
	Audio2D(const char* filePath, SoundController* soundManager, bool stream, bool looping);
	~Audio2D();
	void play();
	void stop();
	void update(Listener * listener);
	void setVolume(double volume);
	void setPanning(double panning);
	void setPitch(double pitch);
private:
	std::string filePath;
	ga_Handle* handle;
	SoundController* soundController;
};