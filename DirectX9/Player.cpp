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
	playerModel.Load(_T("Mesh/catsenkan.x"));
	playerPos.x = 0.0f;
	playerPos.y = 0.0f;
	playerPos.z = 5.0f;
	playerAliveFlag = true;

	//カメラポジション設定
	vEyePt.x = 0.0f;
	vEyePt.y = 0.0f;
	vEyePt.z = 0.0f;
	//上方向設定
	vUpVec.x = 0.0f;
	vUpVec.y = 1.0f;
	vUpVec.z = 0.0f;
	//カメラ情報設定
	D3DXMatrixLookAtLH(&matView, &vEyePt, &playerPos, &vUpVec);
	//ビュー行列設定
	d3d.SetViewMatric(matView);

	rad = 0.0f;
	Speed = 0.1f;
}

void Player::Update()
{
	CameraControl();
	Draw();
}

void Player::Draw()
{
	if (playerAliveFlag == true)
	{
		D3DXMatrixTranslation(&mat_transform, playerPos.x, playerPos.y, playerPos.z);	//座標
		D3DXMatrixScaling(&mat_scale, 1.0f, 1.0f, 1.0f);								//拡大
		D3DXMatrixRotationYawPitchRoll(&mat_rotate, rad, 0.0f, 0.0f);					//回転	

		playerModel.Draw(mat_transform, mat_scale, mat_rotate);							//プレイヤー（自機）の描画
	}
}

void Player::CameraControl()
{
	//カメラが回転するような挙動(原点で回転)
	playerPos.x = vEyePt.x + range*sin(rad);
	playerPos.y = vEyePt.y + 0.0f;
	playerPos.z = vEyePt.z + range*cos(rad);

	if (pDi->KeyState(DIK_UP))
	{
		vEyePt.x +=playerPos.x - vEyePt.x* Speed;
		vEyePt.z +=playerPos.z - vEyePt.z* Speed;
	}
	if (pDi->KeyState(DIK_LEFTARROW))
	{
		rad -= 0.01f;
	}
	if (pDi->KeyState(DIK_RIGHTARROW))
	{
		rad += 0.01f;
	}

	//カメラ情報更新
	D3DXMatrixLookAtLH(&matView, &vEyePt, &playerPos, &vUpVec);
	d3d.SetViewMatric(matView);
}