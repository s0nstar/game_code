#include "Framework.h"
#include "Camera.h"

void Camera::Update()
{
	Move();
}

void Camera::Render()
{
	vpb->SetVSBuffer(1);
}

void Camera::Move()
{
	float delta = Time::Get()->Delta();

	if (Keyboard::Get()->Press(VK_RIGHT))
		position.x += cameraSpeed * delta;
	else if (Keyboard::Get()->Press(VK_LEFT))
		position.x -= cameraSpeed * delta;

	if (Keyboard::Get()->Press(VK_UP))
		position.y += cameraSpeed * delta;
	else if (Keyboard::Get()->Press(VK_DOWN))
		position.y -= cameraSpeed * delta;

	UpdateView();
}

void Camera::UpdateView()
{
	D3DXMatrixLookAtLH(&view, &position, &(position + Values::FwdVec), &Values::UpVec);
	vpb->SetView(view);
}

void Camera::UnProjection(Vector3* out, Vector3 source, Matrix world)
{
	Vector3 position = source;

	out->x = (position.x * 2.0f / WinMaxWidth) - 1.f;
	out->y = (position.y * 2.0f / WinMaxHeight) - 1.f;
	out->z = position.z;

	Matrix wvp = world * view * proj;
	D3DXMatrixInverse(&wvp, nullptr, &wvp);
	D3DXVec3TransformCoord(out, out, &wvp);
}

Camera::Camera()
{
	// Create Buffer
	{
		// view, projection ���� ����
		vpb = new VPBuffer;

		// view ���
		D3DXMatrixLookAtLH
		(
			&view,
			&Vector3(0, 0, 0),	// ī�޶� ��ġ
			&Vector3(0, 0, 1),	// ī�޶� �ٶ󺸴� ����
			&Vector3(0, 1, 0)	// ī�޶� ���� ����
		);

		// projection ���
		D3DXMatrixOrthoOffCenterLH
		(
			&proj,
			0.0f,				// ���� ���� ��ġ
			(float)WinMaxWidth,	// ������ ���� ��ġ
			0.0f,				// �Ʒ��� ���� ��ġ
			(float)WinMaxHeight,// ���� ���� ��ġ
			0,					// ����� ��
			1					// �ָ� �ִ� ��
		);

		vpb->SetView(view);
		vpb->SetProj(proj);
	}
}

Camera::~Camera()
{
	SAFE_DELETE(vpb);
}