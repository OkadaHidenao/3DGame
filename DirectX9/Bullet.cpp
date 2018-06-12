#include"Bullet.h"

Bullet::Bullet()
{
	//�R���X�g���N�^
}
Bullet::~Bullet()
{
	//�f�X�g���N�^
}

void Bullet::Initialize()
{
	//���f�����[�h
	bulletModel.Load(_T("Mesh/Bullet.x"));
	//���W������
	bulletPos.x = bulletPos.y = bulletPos.z = 0.0f;
	//���˂�����true
	BulletShotFlag = false;
}

void Bullet::Draw()
{
	if (BulletShotFlag)
	{
		D3DXMatrixTranslation(&mat_transform, bulletPos.x, bulletPos.y, bulletPos.z); //���W
		D3DXMatrixScaling(&mat_scale, 0.1f, 0.1f, 0.1f);							  //�g��
		D3DXMatrixRotationYawPitchRoll(&mat_rotate, 0.0f, 0.0f, 0.0f);				  //��]

		bulletModel.Draw(mat_transform, mat_scale, mat_rotate);						  //�`��
	}
}

void Bullet::Update()
{

}

//�e�̈ʒu�����߂܂�
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