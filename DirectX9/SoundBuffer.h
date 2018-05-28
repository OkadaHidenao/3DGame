#pragma once

#pragma comment(lib,"dsound.lib")

#include <dsound.h>	

class WaveFile;

class SoundBuffer
{
private:
	IDirectSoundBuffer *pBuffer;

public:
	//�R���X�g���N�^
	SoundBuffer();
	//�f�X�g���N�^
	~SoundBuffer();

	bool Create(WaveFile& waveFile);

	//�Đ��@��~
	void Play(bool loop);
	void Stop();

	//���
	void Release();
};