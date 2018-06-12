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
	//’e‚Ìƒ‚ƒfƒ‹
	MeshX bulletModel;
	//ƒ‚ƒfƒ‹‚É“n‚·s—ñ‚ğì¬
	D3DXMATRIXA16 mat_transform, mat_scale, mat_rotate;
	//’e‚ÌÀ•W
	D3DXVECTOR3 bulletPos;
	//’e‚ª”­Ë‚³‚ê‚éŠp“x
	D3DXVECTOR3 bulletShotAngle;

public:
	Bullet();
	~Bullet();

	void Initialize();
	void Update();
	void Draw();

	//’e‚ÌêŠ‚ğŒˆ’è
	void BulletSet(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle);
	//’e‚ğ”­Ë‚µ‚Ä‚¢‚é‚©‚Ìƒtƒ‰ƒO
	bool BulletShotFlag;
};