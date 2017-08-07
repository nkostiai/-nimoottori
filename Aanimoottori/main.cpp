#include <iostream>
#include "audio2D.h"
#include "audio3D.h"
#include "SoundManager.h"
#include "SoundController.h"
#define Log(X) std::cout << X << std::endl

int main() {

	SoundManager manager = SoundManager();
	manager.init(0,0,0,0,0,0);
	const char* filePath = "Sounds/seloop.wav";
	Audio3D audio = manager.getNewAudio3D(filePath, false, false, 0, 0, 0, 0, 0, 0);

	audio.play();

	while (true) {
		manager.update();
	}
	
	return 0;
}