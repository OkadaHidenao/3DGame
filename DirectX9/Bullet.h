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

#define Bullet_Speed 1.0f

class Bullet
{
private:
	//�e�̃��f��
	MeshX bulletModel;
	//���f���ɓn���s����쐬
	D3DXMATRIXA16 mat_transform, mat_scale, mat_rotate;
	//�e�̍��W
	D3DXVECTOR3 bulletPos;
	//�e�����˂����p�x
	D3DXVECTOR3 bulletShotAngle;

public:
	Bullet();
	~Bullet();

	void Initialize();
	void Update();
	void Draw();

	//�e�̏ꏊ������
	void BulletSet(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle);
	//�e�𔭎˂��Ă��邩�̃t���O
	bool BulletShotFlag;
};