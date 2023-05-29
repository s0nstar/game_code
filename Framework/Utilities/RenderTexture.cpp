#include "Framework.h"
#include "RenderTexture.h"

RenderTexture::RenderTexture()
{
	D3D11_TEXTURE2D_DESC textureDesc;
	Zero(textureDesc);

	textureDesc.Width = WinMaxWidth;
	textureDesc.Height = WinMaxHeight;
	textureDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	textureDesc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
	textureDesc.SampleDesc.Count = 1;
	textureDesc.SampleDesc.Quality = 0;
	textureDesc.MipLevels = 1;
	textureDesc.ArraySize = 1;
	textureDesc.MiscFlags = 0;

	HRESULT hr = DEVICE->CreateTexture2D(&textureDesc, nullptr, &texture);
	CHECK(hr);


	D3D11_RENDER_TARGET_VIEW_DESC rtvDesc;
	Zero(rtvDesc);

	rtvDesc.Format = textureDesc.Format;
	rtvDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	rtvDesc.Texture2D.MipSlice = 0;

	hr = DEVICE->CreateRenderTargetView(texture, &rtvDesc, &rtv);
	CHECK(hr);

	
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	Zero(srvDesc);

	srvDesc.Format = textureDesc.Format;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = 1;

	hr = DEVICE->CreateShaderResourceView(texture, &srvDesc, &srv);
	CHECK(hr);
}

RenderTexture::~RenderTexture()
{
	SAFE_RELEASE(srv);
	SAFE_RELEASE(rtv);
	SAFE_RELEASE(texture);
}

void RenderTexture::RenderToTexture()
{
	// OM �ܰ迡�� ����� RTV �� ���� - ���ٽ� �� ����
	DC->OMSetRenderTargets(1, &rtv, nullptr);
	DC->ClearRenderTargetView(rtv, Values::ClearColor);
}

/*
Texture2D
- �׷��� ī�忡�� ����ϴ� �ؽ�ó �����͸� �����ϴ� ��ü
- �ַ� �̹���, ����, ������, ����Ʈ�� ���� ����
- ũ��, ����, �Ӹ�, ��Ƽ ���ø� �� �پ��� �Ӽ��� ���� �� �ִ�

Shader Resource View
- �ؽ�ó�� ���̴����� �б� ���� ��
- ���̴��� �ؽ�ó�� �о �ȼ��� ���� ���
- SRV�� ����Ͽ� ���̴��� �ؽ�ó �����Ϳ� �������� �� �ִ�

Render Target View
- ���� Ÿ�ٿ� ���� ��
- ���̴� ����� �����ϴ� ����
- �ش� ���ۿ� ���� �б� / ���� �������� ����
- ���̴� ����� ���� Ÿ�ٿ� ������ �� �ִ�

(View : ���ҽ��� Ư�� �κ��̳� Ư�� ������� �ؼ��� �����͸� �����ϴ� ��ü)

MipMap
- DirectX���� �Ʒ��� ������ ���� �ؽ�ó�� ���� �ػ� ������ �����ϴ� �̹��� �÷���
- ������ �ػ� ������ �迭�� ����
	- 3D �������� ��ü�� ȭ�鿡 �������� ũ�� ���̰�, �ָ� �������� �۰� ���δ�
	- ����� ��ü���� ���� �ػ��� �ؽ�ó�� �����ϰ�, �ָ� �ִ� ��ü���� ���� �ؽ�ó�� �����Ѵ�
		-> �ڿ� ��뷮�� �پ��� ������ �ӵ��� ������
*/