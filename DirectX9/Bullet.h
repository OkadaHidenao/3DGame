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

#define Bullet_Speed 0.1f

class Bullet
{
private:
	//弾のモデル
	MeshX bulletModel;
	//モデルに渡す行列を作成
	D3DXMATRIXA16 mat_transform, mat_scale, mat_rotate;
	//弾の座標
	D3DXVECTOR3 bulletPos;
	//弾が発射される角度
	D3DXVECTOR3 bulletShotAngle;

public:
	Bullet();
	~Bullet();

	void Initialize();
	void Draw();

	//弾の場所を決定
	void BulletSet(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle);
	//弾を発射しているかのフラグ
	bool BulletShotFlag;
};