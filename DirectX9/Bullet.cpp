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
	bulletModel.Load(_T("Mesh/Bullet.x"));
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
		D3DXMatrixScaling(&mat_scale, 0.1f, 0.1f, 0.1f);							  //拡大
		D3DXMatrixRotationYawPitchRoll(&mat_rotate, 0.0f, 0.0f, 0.0f);				  //回転

		bulletModel.Draw(mat_transform, mat_scale, mat_rotate);						  //描画
	}
}

void Bullet::Update()
{

}

//弾の位置を決めます
void Bullet::BulletSet(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle)
{
	if (BulletShotFlag)
	{
		bulletPos += bulletShotAngle*Bullet_Speed;
	}
	else
	{
		bulletShotAngle = Angle;
		bulletPos = Pos;
	}
}