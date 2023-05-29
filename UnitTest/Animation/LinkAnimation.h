#pragma once

#include "Geomatries/AnimationRect.h"
#include "Utilities/Animator.h"

class LinkAnimation
{
public:
	LinkAnimation(class AnimationRect* animRect, class Animator* animator);
	~LinkAnimation();

private:
	class AnimationRect* animRect = nullptr;
	class Animator* animator = nullptr;
};