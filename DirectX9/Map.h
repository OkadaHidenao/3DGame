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

class Map
{
private:
	//���̃��f��
	MeshX floorModel;
	//���̃��f���ɓn���s����쐬
	D3DXMATRIXA16 mat_transform, mat_scale, mat_rotate;
	//���̍��W(�Œ�)
	D3DXVECTOR3 floorPos;


	//�ǂ̃��f��
	MeshX wallModel;
	//�ǂ̃��f���ɓn���s����쐬
	D3DXMATRIXA16 mat_wall_transform, mat_wall_scale, mat_wall_rotate;
	//�ǂ̍��W
	D3DXVECTOR3 wallPos[4];

public:
	Map();
	~Map();
	void Initialize();
	void Draw();

	//�����蔻��p
	void Hit();
};