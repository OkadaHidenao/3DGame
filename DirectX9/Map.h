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
	//床のモデル
	MeshX floorModel;
	//床のモデルに渡す行列を作成
	D3DXMATRIXA16 mat_transform, mat_scale, mat_rotate;
	//床の座標(固定)
	D3DXVECTOR3 floorPos;


	//壁のモデル
	MeshX wallModel;
	//壁のモデルに渡す行列を作成
	D3DXMATRIXA16 mat_wall_transform, mat_wall_scale, mat_wall_rotate;
	//壁の座標
	D3DXVECTOR3 wallPos[4];

public:
	Map();
	~Map();
	void Initialize();
	void Draw();

	//あたり判定用
	void Hit();
};