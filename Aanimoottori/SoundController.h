#pragma once
struct gau_Manager;
struct ga_Mixer;
struct ga_StreamManager;
struct ga_Handle;

class SoundController {
	
public:
	SoundController();
	~SoundController();
	void destroy();
	void update();
	ga_Handle* getRegularHandleFromSoundFile(const char* filePath, bool looping);
	ga_Handle* getStreamingHandleFromSoundFile(const char* filePath, bool looping);
	void init();
private:
	gau_Manager* mgr;
	ga_Mixer* mixer;
	ga_StreamManager* streamMgr;

};