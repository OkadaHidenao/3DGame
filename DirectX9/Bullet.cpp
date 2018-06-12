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
	bulletModel.Load(_T("Mesh/ball.x"));
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
		D3DXMatrixScaling(&mat_scale, 1.0f, 1.0f, 1.0f);							  //�g��
		D3DXMatrixRotationYawPitchRoll(&mat_rotate, 0.0f, 0.0f, 0.0f);				  //��]

		bulletModel.Draw(mat_transform, mat_scale, mat_rotate);						  //�`��
	}
}

//�e�̈ʒu�����߂܂�
void Bullet::BulletSet(D3DXVECTOR3 Pos, D3DXVECTOR3 Angle)
{
	if (BulletShotFlag)
	{
		//�O�ɔ�΂�
		bulletPos += bulletShotAngle*Bullet_Speed;
	}
	else
	{
		bulletShotAngle = Angle - Pos;
		bulletPos = Pos;
	}
}