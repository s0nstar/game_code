#include "stdafx.h"
#include "Test.h"

#include "Map/TestMap.h"

void Test::Init()
{
	map = new TestMap();
}

void Test::Destroy()
{
	SAFE_DELETE(map);
}

void Test::Update()
{
	map->Update();
}

void Test::Render()
{
	map->Render();
}

void Test::PostRender()
{
}

void Test::GUI()
{
}
