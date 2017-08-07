#pragma once
#include <string>

class ga_Handle;
class SoundController;
class Listener;

class PlayableAudio {

public:
	virtual void update(Listener* listener) = 0;
	virtual void play() = 0;
	virtual void stop() = 0;
private:
	std::string filePath;
	ga_Handle* handle;
	SoundController* soundController;
protected:
	PlayableAudio();

};