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

class Player
{
private:

	//�J�����̃C���X�^���X���쐬
	Camera camera;
	//�J�����̈ʒu
	D3DXVECTOR3 vEyePt;
	//�����_
	D3DXVECTOR3 vLookatPt;
	//�����
	D3DXVECTOR3 vUpVec;
	//�J�����p�̍s����쐬
	D3DXMATRIXA16 matView;

	//�������̉�]�p�x��[rad]�Ŏw��
	float rad;
	//�����_�̋���
	const float range = 5.0f;
	//�ړ��X�s�[�h
	float Speed;

	//�L�[����p
	DirectInput * pDi = DirectInput::GetInstansce();

public:

	Player();
	~Player();

	void Initialize();
	void Update();
	void Control();

	//Direct3D���Ǘ�����N���X(�V���O���g��)�ւ̎Q�Ƃ��擾
	Direct3D& d3d = Direct3D::GetInstance();

	D3DXVECTOR3 cameraPos() { return vEyePt; }
	D3DXVECTOR3 cameraAngle() { return vLookatPt; }
};