#include "stdafx.h"
#include "TestMap.h"


TestMap::TestMap()
{
	//Test
	{
		TestStage = new TextureRect(Vector3(WinMaxWidth, WinMaxHeight - 360, 0), Vector3(2560, 720, 0), 0.f, TexturePath + L"Map_Test.jpg");
	}
}

TestMap::~TestMap()
{
	SAFE_DELETE(TestStage);
}

void TestMap::Update()
{
	TestStage->Update();
}

void TestMap::Render()
{
	TestStage->Render();
}
