#pragma once
#include "Vector3.h"
#include "PlayableAudio.h"

struct ga_Handle;
class SoundController;
class Listener;

class Audio3D: public PlayableAudio {
public:
	Audio3D(const char* filePath, SoundController* soundManager, bool stream, bool looping);
	~Audio3D();
	void play();
	void stop();
	Vector3 getPosition();
	Vector3 getSpeed();
	void setPosition(double px, double py, double pz);
	void setSpeed(double px, double py, double pz);
	void update(Listener* listener);
private:
	void updateAttenuation(Listener* listener);
	void updatePanning(Listener* listener);
	void updateDoppler(Listener* listener);


	const char* filePath;
	ga_Handle* handle;
	SoundController* soundManager;
	Vector3 position;
	Vector3 speed;
};