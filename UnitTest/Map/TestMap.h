#pragma once


#include "Geomatries/TextureRect.h"

class TestMap
{
public:
	TestMap();
	~TestMap();

	void Update();
	void Render();

private:
	TextureRect* TestStage = nullptr;
	//class TextureRect* Event = nullptr;
};