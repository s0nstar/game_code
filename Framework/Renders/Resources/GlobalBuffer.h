// WVP ��� ����

#pragma once
#include "Framework.h"

class WorldBuffer : public ShaderBuffer
{
public:
	WorldBuffer() : ShaderBuffer(&data, sizeof(Data))
	{
		D3DXMatrixIdentity(&data.world);
	}

	void SetWorld(Matrix world)
	{
		D3DXMatrixTranspose(&data.world, &world);
	}

	struct Data
	{
		Matrix world;
	};
private:
	Data data;
};

class VPBuffer : public ShaderBuffer
{
public:
	VPBuffer() : ShaderBuffer(&data, sizeof(Data))
	{
		// ��� �ʱ�ȭ
		D3DXMatrixIdentity(&data.view);
		D3DXMatrixIdentity(&data.projection);
	}

	void SetView(Matrix view)
	{
		// ��� ��ġ
		D3DXMatrixTranspose(&data.view, &view);
	}

	void SetProj(Matrix projection)
	{
		D3DXMatrixTranspose(&data.projection, &projection);
	}
	struct Data
	{
		Matrix view;
		Matrix projection;
	};

private:
	Data data;
};

/*
W V P : World, View, Projection

1. World : ����
- ���� ������ ���� ��ǥ�迡�� ���� ��ǥ�Է� ��ȯ�ϴ� ���� �ǹ�
- ���� ��ġ, ȸ�� �� ũ�⸦ ����

2. View : ��
- ī�޶��� ��ġ, ���� �� �þ߸� ��Ÿ���� ���
- ���� ��ǥ�迡�� ī�޶� �ٶ󺸴� ������ ��Ÿ��
- ī�޶��� ��ġ�� ������ ����

3. Projection : ����
- 3D ������ 2D ��ũ�� ��ǥ�� ��ȯ�ϴ� ���� �ǹ�
- �þ߰�, ��Ⱦ��, ũ���� ���(Clipping Planes)���� ����Ͽ� ����

*/