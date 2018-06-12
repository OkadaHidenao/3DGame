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
	//プレイヤーのモデル
	MeshX playerModel;
	//モデルに渡す行列を作成
	D3DXMATRIXA16 mat_transform, mat_scale, mat_rotate;
	//自キャラ生存フラグ
	bool playerAliveFlag;
	//プレイヤーのポジション
	D3DXVECTOR3 playerPos;
	//移動スピード
	float Speed;


	//カメラのインスタンスを作成
	Camera camera;
	//カメラの位置
	D3DXVECTOR3 vEyePt;
	//注視点
	D3DXVECTOR3 vLookatPt;
	//上方向
	D3DXVECTOR3 vUpVec;
	//カメラ用の行列を作成
	D3DXMATRIXA16 matView;

	//基準軸からの回転角度を[rad]で指定
	float rad;
	//注視点の距離
	const float range = 5.0f;

	//キー操作用
	DirectInput * pDi = DirectInput::GetInstansce();

public:
	Player();
	~Player();

	void Initialize();
	void Update();
	void Control();

	//Direct3Dを管理するクラス(シングルトン)への参照を取得
	Direct3D& d3d = Direct3D::GetInstance();
};