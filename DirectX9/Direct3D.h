#pragma once

//�C���N���[�h�t�@�C���@Direct3D�֌W
#include <d3d9.h>
#include <d3dx9.h>

//���C�u�����t�@�C���̓ǂݍ���
//Direct3D�֌W
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3dxof.lib")
#pragma comment(lib,"dxguid.lib")

//�C���N���[�h�t�@�C���@windows
#include <Windows.h>

//���C�u�����t�@�C���@windows
#pragma comment(lib,"winmm.lib")


#include <tchar.h>

//�|���S���̒��_���(�P���_���̏��)
//SpriteFVF�̓��e�ƍ��킹��K�v������ 
//FVF�͒��_�\���̂̍\����񂪕ۑ����ꂽ����
//MSDN�̒��_�t�H�[�}�b�g�̃y�[�W�ȂǎQ��
struct SpriteVertex
{
	//�����o�̐錾�̏��Ԃ�FVF�ɂ���Č��܂�̂�
	//�錾�̏��Ԃɒ��ӂ��邱��

	//�O�������W
	D3DXVECTOR3 pos;

	//�X�N���[�����W�ɕϊ��ς݂��ǂ�����\���t���O
	//1.0�Ȃ璸�_�V�F�[�_�ł̕ϊ����s���Ȃ�
	float rhw;

	//���_�F //diffuse
	D3DCOLOR color;

	//���̒��_�ƃe�N�X�`�����̍��W�̑Ή��t��
	float u, v;
};

//���_�\���̂̍\�����
static const DWORD SPRITE_FVF
= D3DFVF_XYZRHW |D3DFVF_DIFFUSE| D3DFVF_TEX1;

//�����_�[�X�e�[�g�̎�ށ@�ݒ�p
enum RENDERSTATE
{
	RENDER_DEFAULT,		//�f�t�H���g
	RENDER_ALPHATEST,	//���e�X�g
	RENDER_ALPHABLEND,	//���u�����h
	RENDER_MESH_X		//���b�V��
};

//�g�p����N���X����錾
//Sprite.h���C���N���[�h�����ɃN���XSprite�̖��O���g��
//���O�ȊO�̗v�f���g�����Ƃ���ƃG���[
//Direct3d.cpp�ł�Sprite.h���C���N���[�h����K�v������
class Sprite;

//���Sprite�N���X�Ɠ��l�̗��R
class Texture;
class MeshX;
class OrientedBoundingBox;

//�V���O���g���ȃN���X�ɂ���
//�C���X�^���X���ЂƂ�������Ȃ����Ƃ�ۏ؂���N���X
//�R���X�g���N�^�������Z�q��private�ɂ���
//�I�u�W�F�N�g�̍쐬�̎�i�𐧌�
class Direct3D
{
private  :
	//�N���X�O����̓I�u�W�F�N�g�������鏈���������Ȃ�
	Direct3D();
	~Direct3D();

	Direct3D(const Direct3D& obj) {};		//�R�s�[�R���X�g���N�^
	void operator=(const Direct3D& obj) {};	//������Z

	//�B��̃I�u�W�F�N�g���w���|�C���^
	static Direct3D* pInstance;

public :
	
	//�B��̃C���X�^���X�ւ̎Q�Ƃ��擾����֐�
	//�ŏ��̎��s�̎��ɃC���X�^���X���쐬����
	static Direct3D& GetInstance()
	{
		if (pInstance == nullptr)
		{
			pInstance = new Direct3D();
		}
		return *pInstance;//�B��̃C���X�^���X�ւ̎Q�Ƃ�Ԃ�
	}

	//�쐬�����B��̃C���X�^���X��j������
	static  void DestroyInstance()
	{
		if (pInstance != nullptr)
		{
			delete pInstance;
			pInstance = nullptr;
		}
	}

	//�J���֐�
	//�R���X�g���N�^���s���Ɠ�����Ԃɖ߂�
	void Release();

	//�����_�[�X�e�[�g�̐ݒ�@�`��̐ݒ�
	void SetRenderState(RENDERSTATE state);

private:
	//Direct3D�̃f�o�C�X
	//�`���������摜�����[�h�����肷�邽�߂Ɏg�p����I�u�W�F�N�g
	IDirect3DDevice9 * pDevice3D;

	//Direct3D�f�o�C�X�̍쐬���s�����߂̃I�u�W�F�N�g
	IDirect3D9*  pD3D9;

	HWND hWnd;
	
	//�ȉ��@�����o�֐��̐錾
private :
	bool Create(HWND hWnd);

public :

	//Direct3D�f�o�C�X�̍쐬�����݂�
	//���s�����false���Ԃ�悤�ɂ���
	bool TryCreate(HWND hWnd);
	
	//begin��end�̊Ԃōs��ꂽ�`�揈���łȂ��ƕ`�悳��Ȃ�

	//�`��̊J�n�̍��}��DirectX�֑���
	HRESULT BeginScene();
	//�`��I���̍��}��DirectX�֑���
	HRESULT EndScene();

	//�o�b�N�o�b�t�@�̃N���A
	HRESULT ClearScreen();

	//�o�b�N�o�b�t�@���t�����g��ʂɔ��f
	HRESULT Present();

	//�r���[�s��̐ݒ�@�ȒP�Ɍ����΁@�J�����̈ʒu�Ɖ�]
	void SetViewMatric(D3DXMATRIXA16& matView);
	//�v���W�F�N�V�����s��̐ݒ� ����p�@�A�X�y�N�g��@�`�拗��
	void SetProjectionMatrix();

	//�e�N�X�`���̃��[�h
	//�߂�l�͐������������s������
	//���[�h������������@tex�̃����o��pTexture�ɃA�h���X�����蓖�Ă���
	bool LoadTexture(Texture& tex, TCHAR*FilePath);

	//�X�v���C�g�̕`��
	void DrawSprite(Sprite& sprite,Texture& tex);

	//.x�`���̃��b�V���ǂݍ���
	bool LoadMeshX(MeshX& mesh, TCHAR*path);
	//.x�`���̃��b�V���`��
	void DrawMeshX(MeshX& mesh, D3DXMATRIXA16& matWorld);

	//�L�����E�{�b�N�X�̕`��֐����Ăяo��
	HRESULT CallDrawFunc(OrientedBoundingBox &obb);
};