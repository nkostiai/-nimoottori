#include "SoundController.h"

#include <gorilla\ga.h>
#include <gorilla\gau.h>


ga_Handle * SoundController::getStreamingHandleFromSoundFile(const char * filePath, bool looping)
{
	ga_Handle* handle;
	if (looping) {
		gau_SampleSourceLoop* loopSrc;
		handle = gau_create_handle_buffered_file(mixer, streamMgr, filePath, "wav", 0, 0, &loopSrc);
		gau_sample_source_loop_set(loopSrc, -1, 0);
	}
	else {
		handle = gau_create_handle_buffered_file(mixer, streamMgr, filePath, "wav", 0, 0, 0);
	}
	return handle;
}

void SoundController::init() {
		gc_initialize(0);
		this->mgr = gau_manager_create();
		this->mixer = gau_manager_mixer(mgr);
		this->streamMgr = gau_manager_streamManager(mgr);
	}

	SoundController::SoundController(){
	}

	SoundController::~SoundController() {
		
	}

	void SoundController::destroy() {
		ga_stream_manager_destroy(this->streamMgr);
		ga_mixer_destroy(this->mixer);
		gau_manager_destroy(this->mgr);
		gc_shutdown();
	}

	void SoundController::update() {
		gau_manager_update(mgr);
	}

	ga_Handle* SoundController::getRegularHandleFromSoundFile(const char* filePath, bool looping) {
		ga_Sound* sound;
		sound = gau_load_sound_file(filePath, "wav");
		ga_Handle* handle;
		if (looping) {
			gau_SampleSourceLoop* loopSrc;		
			handle = gau_create_handle_sound(mixer, sound, 0, 0, &loopSrc);
			gau_sample_source_loop_set(loopSrc, -1, 0);
		}
		else {
			handle = gau_create_handle_sound(mixer, sound, 0, 0, 0);
		}
		return handle;
	}