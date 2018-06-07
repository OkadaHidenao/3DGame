#pragma once

#include"Camera.h"
#include"Direct3D.h"
#include"DirectInput.h"
#include"DirectSound.h"
#include"MeshX.h"
#include"OrientedBoundingBox.h"
#include"SoundBuffer.h"
#include"Sprite.h"
#include"Texture.h"
#include"Vector2D.h"
#include"wave.h"

#include"Player.h"

#define WindowWidth 640
#define WindowHeight 480

//enum�ŃQ�[���𕪊�
enum Sequence
{
	GAME_TITLE,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER
};

class GameState
{
private:
	//�^�C�g��,�N���A,�I�[�o�[��ʂ�`�悷�邽�߂̐ݒ�
	//�X�v���C�g�͈ʒu�������Ȃ̂Ŏg���܂킷��
	Sprite messageSprite;
	Texture titleTexture;
	Texture clearTexture;
	Texture overTexture;

	//�Q�[������p
	Sequence gameSeq = GAME_TITLE;

	//�L�[����p
	DirectInput * pDi = DirectInput::GetInstansce();

	//�C���X�^���X�쐬�Q
	Player player;

public:
	GameState();
	~GameState();

	void Initialize();

	void SetUpGame();//�Q�[�����e�̏��������s��

	void Update();
	void GameTitle();
	void GameMain();
	void GameOver();
	void GameClear();
};
