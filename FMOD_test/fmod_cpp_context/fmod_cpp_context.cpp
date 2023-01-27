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
	FMOD::Sound		 *hitSound[3];
	FMOD::Channel    *channel(nullptr);
	FMOD::Channel	 *channel1(nullptr);
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

	result = system->createSound("Generdyn - HITS - 04.wav", FMOD_LOOP_OFF, 0, &hitSound[0]);
	if (result != FMOD_OK) return -1;

	result = system->createSound("Generdyn - HITS - 05.wav", FMOD_LOOP_OFF, 0, &hitSound[1]);
	if (result != FMOD_OK) return -1;

	result = system->createSound("Generdyn - HITS - 06.wav", FMOD_LOOP_OFF, 0, &hitSound[2]);
	if (result != FMOD_OK) return -1;

	result = system->playSound(backgrounSound, 0, false, &channel);
	if (result != FMOD_OK) return -1;

	result = system->playSound(hitSound[0], 0, false, &channel1);
	if (result != FMOD_OK) return -1;

	result = system->playSound(hitSound[1], 0, false, &channel1);
	if (result != FMOD_OK) return -1;

	result = system->playSound(hitSound[2], 0, false, &channel1);
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

		cout << "Press 0 to pause, 1 to resume, and x to exit" << endl;
		
		int i = getch(); // i is ASCII code

		if (i == '0')
		{
			channel->setPaused(true);
	
		}
		else if (i == '1')
			channel->setPaused(false);
		else if (i == 'x')
			break;
	} 

	system->release();	
}
