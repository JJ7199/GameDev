//#include "fmod.h"  // c-context
#include "fmod.hpp"
#include <iostream>
#include <conio.h>

/*
	fmod api documentation
	https://www.fmod.com/resources/documentation-api
*/

using namespace std;

int main()
{
	cout << "FMOD cpp conext example" << endl;

	FMOD::System     *system(nullptr);
	FMOD::Sound      *backgrounSound(nullptr);
	FMOD::Sound		 *hitSound1(nullptr), * hitSound2(nullptr), * hitSound3(nullptr);
	FMOD::Channel    *backGroundChannel(nullptr);
	FMOD::Channel	 *hitChannel1(nullptr), * hitChannel2(nullptr), * hitChannel3(nullptr);
	FMOD_RESULT       result;
	unsigned int      version;
	void             *extradriverdata(nullptr);

	result = FMOD::System_Create(&system);
	if (result != FMOD_OK) return -1;
	
	result = system->getVersion(&version);
	if (result != FMOD_OK) return -1;
	else printf("FMOD version %08x\n", version);

	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
	if (result != FMOD_OK) return -1;

	//result = system->createSound("singing.wav", FMOD_LOOP_NORMAL, 0, &sound);
	result = system->createSound("Generdyn - ATMOS - 10.wav", FMOD_LOOP_NORMAL, 0, &backgrounSound); // .mp3 files work!
	if (result != FMOD_OK) return -1;

	result = system->createSound("Generdyn - HITS - 04.wav", FMOD_LOOP_OFF, 0, &hitSound1);
	if (result != FMOD_OK) return -1;

	result = system->createSound("Generdyn - HITS - 05.wav", FMOD_LOOP_OFF, 0, &hitSound2);
	if (result != FMOD_OK) return -1;

	result = system->createSound("Generdyn - HITS - 06.wav", FMOD_LOOP_OFF, 0, &hitSound3);
	if (result != FMOD_OK) return -1;

	result = system->playSound(backgrounSound, 0, false, &backGroundChannel);
	if (result != FMOD_OK) return -1;


	while (true)
	{
		result = system->update();
		if (result != FMOD_OK) return -1;

		/*if (channel)
		{
			bool playing = false;
			result = channel->isPlaying(&playing);
			if (!playing) break;
		}*/

		cout << "Press q to play hit sound1, w to play hit sound2, e to play hit sound3  and x to exit" << endl;
		
		int i = getch(); // i is ASCII code

		if (i == 'q')
		{
			result = system->playSound(hitSound1, 0, false, &hitChannel1);
			if (result != FMOD_OK) return -1;
		}
		else if (i == 'w')
		{
			result = system->playSound(hitSound2, 0, false, &hitChannel2);
			if (result != FMOD_OK) return -1;
		}
		else if (i == 'e')
		{
			result = system->playSound(hitSound3, 0, false, &hitChannel3);
			if (result != FMOD_OK) return -1;
		}
		else if (i == 'x')
			break;
	} 

	system->release();	
}
