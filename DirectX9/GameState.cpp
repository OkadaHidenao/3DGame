#include"GameState.h"

GameState::GameState()
{
	//コンストラクタ
}
GameState::~GameState()
{
	//デストラクタ
}

void GameState::Initialize()
{
	//メインループ前に呼ぶ
	//ゲームの初期情報を読み込み

	//タイトル,ゲームオーバー,ゲームクリア画面のテクスチャ,スプライト
	messageSprite.SetAlpha(1);
	messageSprite.SetAngle(0);
	messageSprite.SetSize(WindowWidth, WindowHeight);
	messageSprite.SetPos(WindowWidth / 2, WindowHeight / 2);

	titleTexture.Load(_T("Graphic/2DTitle.png"));
	titleTexture.SetDivide(1, 1);
	titleTexture.SetNum(0, 0);
	clearTexture.Load(_T("Graphic/2DClear.png"));
	clearTexture.SetDivide(1, 1);
	clearTexture.SetNum(0, 0);
	overTexture.Load(_T("Graphic/2DOver.png"));
	overTexture.SetDivide(1, 1);
	overTexture.SetNum(0, 0);

	player.Initialize();
}

void GameState::SetUpGame()
{
	//ゲームの設定を初期化
	//リトライするときなどに呼びます
}

void GameState::Update()
{
	//実際の動き
	switch (gameSeq)
	{
	case GAME_TITLE:
		GameTitle();
		break;

	case GAME_MAIN:
		GameMain();
		break;

	case GAME_CLEAR:
		GameClear();
		break;

	case GAME_OVER:
		GameOver();
		break;

	default:
		break;
	}
}

void GameState::GameTitle()
{
	//タイトル

	messageSprite.Draw(titleTexture);
	if (pDi->KeyJustPressed(DIK_RETURN))
	{
		gameSeq = GAME_MAIN;
	}
}

void GameState::GameMain()
{
	//メイン
	player.Update();
}

void GameState::GameClear()
{
	//クリア

	messageSprite.Draw(clearTexture);
	if (pDi->KeyJustPressed(DIK_RETURN))
	{
		gameSeq = GAME_OVER;
	}
}

void GameState::GameOver()
{
	//オーバー

	messageSprite.Draw(overTexture);
	if (pDi->KeyJustPressed(DIK_RETURN))
	{
		gameSeq = GAME_TITLE;
	}
}