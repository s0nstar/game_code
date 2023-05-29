#include "stdafx.h"
#include "LInk.h"

Link::Link(Vector3 position, Vector3 size)
	:Character(position, size)
{
	state = new StateComponent();
	animation = new LinkAnimation(animRect, animator);
}

Link::~Link()
{
	SAFE_DELETE(animation);
	SAFE_DELETE(state);
}

void Link::Update()
{
	animRect->Update();
}

void Link::Render()
{
	animRect->Render();
}

void Link::Move()
{

}

void Link::SetState()
{
	auto key = Keyboard::Get();
}
