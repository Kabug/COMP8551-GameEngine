#pragma once

#include <Bass\bass.h>
#include "Sound.h"

struct AudioSource {
	AudioSource(Sound* sound) : sound(sound), name(sound->name) {}

	Sound* sound;
	const char* name;
	float volume = 1;
	string tag;

	void setVolume(float vol) {
		volume = vol;
	}

	bool getIfLoop() {
		return sound->ifLoop;
	}

	void setifLoop(bool loop) {
		sound->setIfLoop(loop);
	}

	string getTag() {
		return tag;
	}

	void setTag(string t) {
		tag = t;
	}

	void cleanUp() {
		sound->cleanUp();
		delete sound;
		tag == "";
	}
};