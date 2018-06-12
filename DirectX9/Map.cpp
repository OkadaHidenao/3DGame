#include"Map.h"

Map::Map()
{
	//コンストラクタ
}
Map::~Map()
{
	//デストラクタ
}

void Map::Initialize()
{
	//床描画設定
	floorModel.Load(_T("Mesh/Map/floor.x"));
	floorPos.x = 58.0f;
	floorPos.y = -2.0f;
	floorPos.z = 58.0f;

	//壁描画設定

	wallModel.Load(_T("Mesh/Map/cube.x"));

	//-x側の壁
	wallPos[0].x = 10.7f;
	wallPos[0].y = -3.0f;
	wallPos[0].z = 10.0f;

	//+x側の壁
	wallPos[1].x = 107.0f;
	wallPos[1].y = -3.0f;
	wallPos[1].z = 10.0f;

	//+z側の壁
	wallPos[2].x = 146.5f;
	wallPos[2].y = -3.0f;
	wallPos[2].z = 105.0f;

	//-z側の壁
	wallPos[3].x = 146.5f;
	wallPos[3].y = -3.0f;
	wallPos[3].z = 10.0f;
}

void Map::Draw()
{
	//フロア描画
	{
		D3DXMatrixTranslation(&mat_transform, floorPos.x, floorPos.y, floorPos.z);//座標
		D3DXMatrixScaling(&mat_scale, 8.0f, 8.0f, 8.0f);						  //拡大
		D3DXMatrixRotationYawPitchRoll(&mat_rotate, 0.0f, 0.0f, 0.0f);			  //回転

		floorModel.Draw(mat_transform, mat_scale, mat_rotate);					  //描画
	}

	//壁描画
	{
		D3DXMatrixTranslation(&mat_transform, wallPos[0].x, wallPos[0].y, wallPos[0].z);
		D3DXMatrixScaling(&mat_scale, 0.2f, 1.0f, 24.3f);
		D3DXMatrixRotationYawPitchRoll(&mat_rotate, 0.0f, 0.0f, 0.0f);

		wallModel.Draw(mat_transform, mat_scale, mat_rotate);

		D3DXMatrixTranslation(&mat_transform, wallPos[1].x, wallPos[1].y, wallPos[1].z);
		D3DXMatrixScaling(&mat_scale, 0.2f, 1.0f, 24.3f);
		D3DXMatrixRotationYawPitchRoll(&mat_rotate, 0.0f, 0.0f, 0.0f);

		wallModel.Draw(mat_transform, mat_scale, mat_rotate);

		D3DXMatrixTranslation(&mat_transform, wallPos[2].x, wallPos[2].y, wallPos[2].z);
		D3DXMatrixScaling(&mat_scale, 24.3f, 1.0f, 0.2f);
		D3DXMatrixRotationYawPitchRoll(&mat_rotate, 0.0f, 0.0f, 0.0f);

		wallModel.Draw(mat_transform, mat_scale, mat_rotate);

		D3DXMatrixTranslation(&mat_transform, wallPos[3].x, wallPos[3].y, wallPos[3].z);
		D3DXMatrixScaling(&mat_scale, 24.3f, 1.0f, 0.2f);
		D3DXMatrixRotationYawPitchRoll(&mat_rotate, 0.0f, 0.0f, 0.0f);

		wallModel.Draw(mat_transform, mat_scale, mat_rotate);
	}
}