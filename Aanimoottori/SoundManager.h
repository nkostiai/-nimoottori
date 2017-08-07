#pragma once
#include <vector>
#include "SoundController.h"

class Listener;
class Audio3D;
class Audio2D;

class SoundManager {
public:
	SoundManager();
	~SoundManager();
	Listener* init(double px, double py, double pz, double sx, double sy, double sz);
	Audio3D getNewAudio3D(const char* filePath, bool stream, bool looping, double px, double py, double pz, double sx, double sy, double sz);
	Audio2D getNewAudio2D(const char* filePath, bool stream, bool looping);
	void update();
	
private:
	bool initialized = false;
	Listener* listener;
	SoundController soundController;


};