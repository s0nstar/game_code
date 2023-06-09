#pragma once

class VertexBuffer
{
public:
	~VertexBuffer();

	// 정점 자료형으로 어떤게 들어올지 모르기 때문에 템플릿 사용
	template<typename T>
	void Create(const vector<T>& vertices, const D3D11_USAGE& usage = D3D11_USAGE_DEFAULT);

	ID3D11Buffer* GetResource() { return buffer; }

	uint GetStride() { return stride; }
	uint GetOffset() { return offset; }
	uint GetCount()  { return count;  }

	void SetIA();

private:
	ID3D11Buffer* buffer = nullptr;

	uint stride = 0;		// 정점 버퍼에서 한 정점의 크기를 나타내는 값
	uint offset = 0;		// 버퍼에서 읽기 시작할 위치
	uint count = 0;			// 정점 버퍼에서 읽을 정점 개수
};

template<typename T>
inline void VertexBuffer::Create(const vector<T>& vertices, const D3D11_USAGE& usage)
{
	stride = sizeof(T);		// 정점 크기 저장
	count = vertices.size();	// 정점 개수 저장

	D3D11_BUFFER_DESC desc;							// 버퍼 생성을 위한 구조체 선언
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));	// 구조체 초기화

	// desc 설정
	{
		desc.Usage = usage;							// 버퍼의 사용 용도 설정
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;	// 정점 버퍼로 사용함을 정의
		desc.ByteWidth = stride * count;			// 버퍼 크기

		// CPU 접근 설정
		switch (usage)
		{
			case D3D11_USAGE_DEFAULT:
			case D3D11_USAGE_IMMUTABLE:
				break;

			case D3D11_USAGE_DYNAMIC:
				desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
				break;

			// CPU에서 접근 가능, GPU에서 사용할 수 있는 형태로 변환 가능한 버퍼
			case D3D11_USAGE_STAGING:
				desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE | D3D11_CPU_ACCESS_READ;
				break;
		}
	}

	// Buffer 생성
	{
		D3D11_SUBRESOURCE_DATA subData;									// 정점 데이터를 담을 구조체
		ZeroMemory(&subData, sizeof(D3D11_SUBRESOURCE_DATA));			// 구조체 초기화

		subData.pSysMem = vertices.data();								// 정점 데이터를 할당한 메모리에 복사

		HRESULT hr = DEVICE->CreateBuffer(&desc, &subData, &buffer);	// 정점 버퍼 생성
		CHECK(hr);	// 생성 실패 시 펑
	}
}

/*						GPU				CPU
D3D11_USAGE_DEFAULT		읽기, 쓰기		접근 불가
D3D11_USAGE_IMMUTABLE	읽기				접근 불가
D3D11_USAGE_DYNAMIC		읽기				쓰기(Map사용) (느림)
D3D11_USAGE_STAGING		GPU 메모리에서 CPU 메모리로 복사를 허용 (CopyResource) (엄청 느림)
*/