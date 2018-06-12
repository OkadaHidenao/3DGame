#include"Player.h"

Player::Player()
{
	//コンストラクタ
}

Player::~Player()
{
	//デストラクタ
}

void Player::Initialize()
{
	//カメラポジション設定
	vEyePt.x = 13.0f;
	vEyePt.y = 0.0f;
	vEyePt.z = 13.0f;
	//注視点設定
	vLookatPt.x = 0.0f;
	vLookatPt.y = 0.1f;
	vLookatPt.z = 0.0f;
	//上方向設定
	vUpVec.x = 0.0f;
	vUpVec.y = 1.0f;
	vUpVec.z = 0.0f;
	//カメラ情報設定
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
	//ビュー行列設定
	d3d.SetViewMatric(matView);

	rad = 0.0f;
	Speed = 0.1f;
}

void Player::Update()
{
	Control();
}

void Player::Control()
{
	//上押したら
	if (pDi->KeyState(DIK_UP))
	{
		vEyePt.x += (vLookatPt.x - vEyePt.x)* Speed;
		vEyePt.z += (vLookatPt.z - vEyePt.z)* Speed;
	}
	//下押したら
	if (pDi->KeyState(DIK_DOWN))
	{
		vEyePt.x -= (vLookatPt.x - vEyePt.x)* Speed;
		vEyePt.z -= (vLookatPt.z - vEyePt.z)* Speed;
	}
	//左押したら
	if (pDi->KeyState(DIK_LEFTARROW))
	{
		rad -= 0.02f;
	}
	//右押したら
	if (pDi->KeyState(DIK_RIGHTARROW))
	{
		rad += 0.02f;
	}

	//カメラが回転するような挙動(原点で回転)
	vLookatPt.x = vEyePt.x + range*sin(rad);
	vLookatPt.y;
	vLookatPt.z = vEyePt.z + range*cos(rad);

	//カメラ情報更新
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);
	d3d.SetViewMatric(matView);
}