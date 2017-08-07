#include "SoundManager.h"
#include "SoundController.h"
#include "audio2D.h"
#include "audio3D.h"
#include "Listener.h"
#include <iostream>

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
	this->soundController.destroy();
}

Listener * SoundManager::init(double px, double py, double pz, double sx, double sy, double sz)
{
	if (!initialized) {
		this->soundController = SoundController();
		std::cout << "Initing" << std::endl;
		this->soundController.init();
		Listener tmpListener = Listener(px, py, pz, sx, sy, sz);
		this->listener = &tmpListener;
		initialized = true;
	}

	return this->listener;
}


Audio3D SoundManager::getNewAudio3D(const char * filePath, bool stream, bool looping, double px, double py, double pz, double sx, double sy, double sz)
{
	Audio3D tmp = Audio3D(filePath, &this->soundController, stream, looping);
	tmp.setPosition(px, py, pz);
	tmp.setSpeed(sx, sy, sz);
	return tmp;

}

Audio2D SoundManager::getNewAudio2D(const char * filePath, bool stream, bool looping)
{
	return Audio2D(filePath, &this->soundController, stream, looping);
}

void SoundManager::update() {
	this->soundController.update();
}
