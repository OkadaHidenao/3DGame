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

#include"Player.h"

#define WindowWidth 640
#define WindowHeight 480

//enumでゲームを分岐
enum Sequence
{
	GAME_TITLE,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER
};

class GameState
{
private:
	//タイトル,クリア,オーバー画面を描画するための設定
	//スプライトは位置が同じなので使いまわすよ
	Sprite messageSprite;
	Texture titleTexture;
	Texture clearTexture;
	Texture overTexture;

	//ゲーム分岐用
	Sequence gameSeq = GAME_TITLE;

	//キー操作用
	DirectInput * pDi = DirectInput::GetInstansce();

	//インスタンス作成群
	Player player;

public:
	GameState();
	~GameState();

	void Initialize();

	void SetUpGame();//ゲーム内容の初期化を行う

	void Update();
	void GameTitle();
	void GameMain();
	void GameOver();
	void GameClear();
};
