#include "Framework.h"
#include "IShader.h"

void IShader::CompileShader(wstring path, string entryName, string profile, ID3DBlob** blob)
{
	ID3DBlob* error = nullptr;			// �����Ϸ� ���� �޼����� ������ blob ������ ���� (nullptr�� �ʱ�ȭ)
	HRESULT hr = D3DCompileFromFile		// ���̴��� ������, ����� blob �����ͷ� ���� ����
	(
		path.c_str(),					// �������� ���̴� ���
		nullptr,						// ���̴� ������ ����� ��Ÿ���� ������
		nullptr,						// Include �������̽��� ������ Ŭ������ ����� ���̴� ���Ͽ��� �ٸ� ������ include�� �� ����� �� �ִ� ���ý�Ʈ
		entryName.c_str(),				// �������� ���̴� ���Ͽ��� ���� ���������� ����� �Լ� �̸�
		profile.c_str(),				// �������� ���̴� ���Ͽ��� ����� ������ �̸�
		D3DCOMPILE_ENABLE_STRICTNESS,	// ������ ������ �ɼ� / ��� �޼����� ���� 1�� ����
		0,								// ����� ������ ���Ե� ������ ����� �����ϱ� ���� �ɼ�
		blob,							// ������ ����� ������ blob ������ �ּҰ�
		&error							// �����Ϸ� ���� �޼����� ������ blob ������ �ּҰ�
	);
	CheckShaderError(hr, error);
	SAFE_RELEASE(error);
}

void IShader::CheckShaderError(HRESULT hr, ID3DBlob* error)
{
	if (FAILED(hr))
	{
		if (error)
		{
			string str = (const char*)error->GetBufferPointer();
			MessageBoxA(handle, str.c_str(), "Shader Error", MB_OK);
		}
		// ���α׷� �ߴ�
		CHECK(false);
	}
}
