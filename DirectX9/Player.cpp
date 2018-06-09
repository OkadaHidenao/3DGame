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
	playerModel.Load(_T("Mesh/catsenkan.x"));
	playerPos.x = 0.0f;
	playerPos.y = 0.0f;
	playerPos.z = 0.0f;
	playerAliveFlag = true;

	//�J�����|�W�V�����ݒ�
	vEyePt.x = 0.0f;
	vEyePt.y = 3.0f;
	vEyePt.z = 0.0f;
	//������ݒ�
	vUpVec.x = 0.0f;
	vUpVec.y = 1.0f;
	vUpVec.z = 0.0f;
	//�J�������ݒ�
	D3DXMatrixLookAtLH(&matView, &vEyePt, &playerPos, &vUpVec);
	//�r���[�s��ݒ�
	d3d.SetViewMatric(matView);

	rad = 0.0f;
	Speed = 0.01f;
}

void Player::Update()
{
	CameraControl();
	Draw();
}

void Player::Draw()
{
	if (playerAliveFlag == true)
	{
		D3DXMatrixTranslation(&mat_transform, playerPos.x, playerPos.y, playerPos.z);	//���W
		D3DXMatrixScaling(&mat_scale, 1.0f, 1.0f, 1.0f);								//�g��
		D3DXMatrixRotationYawPitchRoll(&mat_rotate, rad, 0.0f, 0.0f);					//��]	

		playerModel.Draw(mat_transform, mat_scale, mat_rotate);							//�v���C���[�i���@�j�̕`��
	}
}

void Player::CameraControl()
{

	//�㉟������
	if (pDi->KeyState(DIK_UP))
	{
		vEyePt.x +=(playerPos.x - vEyePt.x)* Speed;
		vEyePt.z +=(playerPos.z - vEyePt.z)* Speed;
	}
	//����������
	if (pDi->KeyState(DIK_DOWN))
	{
		vEyePt.x -= (playerPos.x - vEyePt.x)* Speed;
		vEyePt.z -= (playerPos.z - vEyePt.z)* Speed;
	}
	//����������
	if (pDi->KeyState(DIK_LEFTARROW))
	{
		rad -= 0.01f;
	}
	//�E��������
	if (pDi->KeyState(DIK_RIGHTARROW))
	{
		rad += 0.01f;
	}

	//�J��������]����悤�ȋ���(���_�ŉ�])
	playerPos.x = vEyePt.x + range*sin(rad);
	playerPos.y;
	playerPos.z = vEyePt.z + range*cos(rad);

	//�J�������X�V
	D3DXMatrixLookAtLH(&matView, &vEyePt, &playerPos, &vUpVec);
	d3d.SetViewMatric(matView);
}