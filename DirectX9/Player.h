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
	//�v���C���[�̃��f��
	MeshX playerModel;
	//���f���ɓn���s����쐬
	D3DXMATRIXA16 mat_transform, mat_scale, mat_rotate;
	//���L���������t���O
	bool playerAliveFlag;
	//�v���C���[�̃|�W�V����
	D3DXVECTOR3 playerPos;
	//�ړ��X�s�[�h
	float Speed;


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
};