#include <shake.h>
#include <stdio.h>

int main()
{
	Shake_Device *device;
	Shake_Effect effect;
	int id;

	Shake_Init();

	if (Shake_NumOfDevices() > 0)
	{
		device = Shake_Open(0);

		Shake_InitEffect(&effect, SHAKE_EFFECT_PERIODIC);
		effect.periodic.waveform		= SHAKE_PERIODIC_SINE;
		effect.periodic.period			= 0.1*0x100;
		effect.periodic.magnitude		= 0x6000;
		effect.periodic.envelope.attackLength	= 0x100;
		effect.periodic.envelope.attackLevel	= 0;
		effect.periodic.envelope.fadeLength	= 0x100;
		effect.periodic.envelope.fadeLevel	= 0;
		effect.direction			= 0x4000;
		effect.length				= 2000;
		effect.delay				= 0;

		id = Shake_UploadEffect(device, &effect);
		Shake_Play(device, id);

		sleep(2);
		Shake_EraseEffect(device, id);
		Shake_Close(device);
	}

	Shake_Quit();

	return 0;
}
