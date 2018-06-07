#include"GameState.h"

GameState::GameState()
{
	//�R���X�g���N�^
}
GameState::~GameState()
{
	//�f�X�g���N�^
}

void GameState::Initialize()
{
	//���C�����[�v�O�ɌĂ�
	//�Q�[���̏�������ǂݍ���

	//�^�C�g��,�Q�[���I�[�o�[,�Q�[���N���A��ʂ̃e�N�X�`��,�X�v���C�g
	messageSprite.SetAlpha(1);
	messageSprite.SetAngle(0);
	messageSprite.SetSize(WindowWidth, WindowHeight);
	messageSprite.SetPos(WindowWidth / 2, WindowHeight / 2);

	titleTexture.Load(_T("Graphic/2DTitle.png"));
	titleTexture.SetDivide(1, 1);
	titleTexture.SetNum(0, 0);
	clearTexture.Load(_T("Graphic/2DClear.png"));
	clearTexture.SetDivide(1, 1);
	clearTexture.SetNum(0, 0);
	overTexture.Load(_T("Graphic/2DOver.png"));
	overTexture.SetDivide(1, 1);
	overTexture.SetNum(0, 0);

	player.Initialize();
}

void GameState::SetUpGame()
{
	//�Q�[���̐ݒ��������
	//���g���C����Ƃ��ȂǂɌĂт܂�
}

void GameState::Update()
{
	//���ۂ̓���
	switch (gameSeq)
	{
	case GAME_TITLE:
		GameTitle();
		break;

	case GAME_MAIN:
		GameMain();
		break;

	case GAME_CLEAR:
		GameClear();
		break;

	case GAME_OVER:
		GameOver();
		break;

	default:
		break;
	}
}

void GameState::GameTitle()
{
	//�^�C�g��

	messageSprite.Draw(titleTexture);
	if (pDi->KeyJustPressed(DIK_RETURN))
	{
		gameSeq = GAME_MAIN;
	}
}

void GameState::GameMain()
{
	//���C��
	player.Update();
}

void GameState::GameClear()
{
	//�N���A

	messageSprite.Draw(clearTexture);
	if (pDi->KeyJustPressed(DIK_RETURN))
	{
		gameSeq = GAME_OVER;
	}
}

void GameState::GameOver()
{
	//�I�[�o�[

	messageSprite.Draw(overTexture);
	if (pDi->KeyJustPressed(DIK_RETURN))
	{
		gameSeq = GAME_TITLE;
	}
}