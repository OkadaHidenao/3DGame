#include"Player.h"

Player::Player()
{
	//�R���X�g���N�^
}

Player::~Player()
{
	//�f�X�g���N�^
}

void Player::Initialize()
{
	//�J�����|�W�V�����ݒ�
	vEyePt.x = 13.0f;
	vEyePt.y = 0.0f;
	vEyePt.z = 13.0f;
	//�����_�ݒ�
	vLookatPt.x = 0.0f;
	vLookatPt.y = 0.1f;
	vLookatPt.z = 0.0f;
	//������ݒ�
	vUpVec.x = 0.0f;
	vUpVec.y = 1.0f;
	vUpVec.z = 0.0f;
	//�J�������ݒ�
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
	//�r���[�s��ݒ�
	d3d.SetViewMatric(matView);

	rad = 0.0f;
	Speed = 0.1f;
}

void Player::Update()
{
	Control();
}

void Player::Control()
{
	//�㉟������
	if (pDi->KeyState(DIK_UP))
	{
		vEyePt.x += (vLookatPt.x - vEyePt.x)* Speed;
		vEyePt.z += (vLookatPt.z - vEyePt.z)* Speed;
	}
	//����������
	if (pDi->KeyState(DIK_DOWN))
	{
		vEyePt.x -= (vLookatPt.x - vEyePt.x)* Speed;
		vEyePt.z -= (vLookatPt.z - vEyePt.z)* Speed;
	}
	//����������
	if (pDi->KeyState(DIK_LEFTARROW))
	{
		rad -= 0.02f;
	}
	//�E��������
	if (pDi->KeyState(DIK_RIGHTARROW))
	{
		rad += 0.02f;
	}

	//�J��������]����悤�ȋ���(���_�ŉ�])
	vLookatPt.x = vEyePt.x + range*sin(rad);
	vLookatPt.y;
	vLookatPt.z = vEyePt.z + range*cos(rad);

	//�J�������X�V
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
	d3d.SetViewMatric(matView);
}