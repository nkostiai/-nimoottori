#include "audio3D.h"
#include "SoundController.h"
#include "Listener.h"
#include <gorilla\ga.h>
#include <gorilla\gau.h>


Audio3D::Audio3D(const char * filePath, SoundController * soundManager, bool stream, bool looping):
filePath(filePath)
{
	this->soundManager = soundManager;
	if (stream) {
		this->handle = soundManager->getStreamingHandleFromSoundFile(filePath, looping);
	}
	else {
		this->handle = soundManager->getRegularHandleFromSoundFile(filePath, looping);
	}
}

Audio3D::~Audio3D(){
	ga_handle_destroy(this->handle);
}

void Audio3D::play(){
	ga_handle_play(this->handle);
}

void Audio3D::stop(){
	ga_handle_stop(this->handle);
}

Vector3 Audio3D::getPosition()
{
	return this->position;
}

Vector3 Audio3D::getSpeed()
{
	return this->speed;
}

void Audio3D::setPosition(double px, double py, double pz)
{
	this->position = Vector3(px, py, pz);
}

void Audio3D::setSpeed(double sx, double sy, double sz)
{
	this->speed = Vector3(sx, sy, sz);
}

void Audio3D::update(Listener* listener)
{
	//Update function should be called every frame
	//Update attenuation by distance
	updateAttenuation(listener);
	//Update panning by location
	updatePanning(listener);
	//Update pitch by speed (doppler)
	updateDoppler(listener);
}

void Audio3D::updateAttenuation(Listener * listener)
{
	double distance = this->position.distance(listener->getPosition());
	ga_handle_setParamf(handle, GA_HANDLE_PARAM_GAIN, listener->getAttenuationByDistance(distance));
}

void Audio3D::updatePanning(Listener * listener)
{
	ga_handle_setParamf(handle, GA_HANDLE_PARAM_PAN, listener->getPanningByLocation(this->position));
}

void Audio3D::updateDoppler(Listener * listener){
	ga_handle_setParamf(handle, GA_HANDLE_PARAM_PITCH, listener->getDopplerShift(this->position, this->speed));
}
