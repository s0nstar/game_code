#pragma once

#include "Game/Character.h"
#include "Animation/LinkAnimation.h"
#include "State/StateComponent.h"

class Link : public Character
{
public:
	Link(Vector3 position, Vector3 size);
	~Link();

	virtual void Update() override;
	virtual void Render() override;

	void Move();
	void SetState();

private:
	StateComponent* state = nullptr;
	LinkAnimation* animation = nullptr;
};