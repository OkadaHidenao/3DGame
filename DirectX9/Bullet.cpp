#include"Bullet.h"

Bullet::Bullet()
{
	//コンストラクタ
}
Bullet::~Bullet()
{
	//デストラクタ
}

void Bullet::Initialize()
{
	//モデルロード
	bulletModel.Load(_T("Mesh/ball.x"));
	//座標初期化
	bulletPos.x = bulletPos.y = bulletPos.z = 0.0f;
	//発射したらtrue
	BulletShotFlag = false;
}

void Bullet::Draw()
{
	if (BulletShotFlag)
	{
		D3DXMatrixTranslation(&mat_transform, bulletPos.x, bulletPos.y, bulletPos.z); //座標
		D3DXMatrixScaling(&mat_scale, 1.0f, 1.0f, 1.0f);							  //拡大
		D3DXMatrixRotationYawPitchRoll(&mat_rotate, 0.0f, 0.0f, 0.0f);				  //回転

		bulletModel.Draw(mat_transform, mat_scale, mat_rotate);						  //描画
	}
}

//弾の位置を決めます
void Bullet::BulletSet(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle)
{
	if (BulletShotFlag)
	{
		//前に飛ばす
		bulletPos += bulletShotAngle*Bullet_Speed;
	}
	else
	{
		bulletShotAngle = Angle - Pos;
		bulletPos = Pos;
	}
}