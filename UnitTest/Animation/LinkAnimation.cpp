#include "stdafx.h"
#include "LinkAnimation.h"

LinkAnimation::LinkAnimation(AnimationRect* animRect, Animator* animator)
{
	//Link1
	{
		Texture2D* srcTex = new Texture2D(TexturePath + L"Link.png");
		Vector2 texSize = Vector2(srcTex->GetWidth(), srcTex->GetHeight());

		//Up
		{
			Vector2 Up_endPos = Vector2(texSize.x * 2 / 5, texSize.y * 1 / 10);

			AnimationClip* Up = new AnimationClip(L"Up", srcTex, 2, Values::ZeroVec2, Up_endPos, false);
			animator->AddAnimClip(Up);
		}

		//Down
		{
			Vector2 Down_staPos = Vector2(0, texSize.y * 1 / 10);
			Vector2 Down_endPos = Vector2(texSize.x * 2 / 5, texSize.y * 2 / 10);

			AnimationClip* Down = new AnimationClip(L"Down", srcTex, 2, Down_staPos, Down_endPos, false);
			animator->AddAnimClip(Down);
		}

		//Right
		{
			Vector2 Right_staPos = Vector2(0, texSize.y * 2 / 10);
			Vector2 Right_endPos = Vector2(texSize.x * 2 / 5, texSize.y * 3 / 10);

			AnimationClip* Right = new AnimationClip(L"Right", srcTex, 2, Right_staPos, Right_endPos, false);
			animator->AddAnimClip(Right);
		}

		//Left
		{
			Vector2 Left_staPos = Vector2(0, texSize.y * 3 / 10);
			Vector2 Left_endPos = Vector2(texSize.x * 2 / 5, texSize.y * 4 / 10);

			AnimationClip* Left = new AnimationClip(L"Left", srcTex, 2, Left_staPos, Left_endPos, false);
			animator->AddAnimClip(Left);
		}

		//AttackDown
		{
			Vector2 AttackDown_staPos = Vector2(0, texSize.y * 4 / 10);
			Vector2 AttackDown_endPos = Vector2(texSize.x * 4 / 5, texSize.y * 5 / 10);

			AnimationClip* AttackDown = new AnimationClip(L"AttackDown", srcTex, 4, AttackDown_staPos, AttackDown_endPos, false);
			animator->AddAnimClip(AttackDown);
		}

		//AttackUp
		{
			Vector2 AttackUp_staPos = Vector2(0, texSize.y * 5 / 10);
			Vector2 AttackUp_endPos = Vector2(texSize.x * 4 / 5, texSize.y * 6 / 10);

			AnimationClip* AttackUp = new AnimationClip(L"AttackUp", srcTex, 4, AttackUp_staPos, AttackUp_endPos, false);
			animator->AddAnimClip(AttackUp);
		}

		//AttackRight
		{
			Vector2 AttackRight_staPos = Vector2(0, texSize.y * 6 / 10);
			Vector2 AttackRight_endPos = Vector2(texSize.x * 4 / 5, texSize.y * 7 / 10);

			AnimationClip* AttackRight = new AnimationClip(L"AttackRight", srcTex, 4, AttackRight_staPos, AttackRight_endPos, false);
			animator->AddAnimClip(AttackRight);
		}

		//AttackLeft
		{
			Vector2 AttackLeft_staPos = Vector2(0, texSize.y * 7 / 10);
			Vector2 AttackLeft_endPos = Vector2(texSize.x * 4 / 5, texSize.y * 8 / 10);

			AnimationClip* AttackLeft = new AnimationClip(L"AttackLeft", srcTex, 4, AttackLeft_staPos, AttackLeft_endPos, false);
			animator->AddAnimClip(AttackLeft);
		}

		//EatItem
		{
			Vector2 EatItem_staPos = Vector2(0, texSize.y * 8 / 10);
			Vector2 EatItem_endPos = Vector2(texSize.x * 2 / 5, texSize.y * 9 / 10);

			AnimationClip* EatItem = new AnimationClip(L"EatItem", srcTex, 2, EatItem_staPos, EatItem_endPos, false);
			animator->AddAnimClip(EatItem);
		}

		animRect->SetAnimator(animator);

		SAFE_DELETE(srcTex);
	}

	//Link2
	{
		Texture2D* srcTex2 = new Texture2D(TexturePath + L"Link2.png");
		Vector2 texSize2 = Vector2(srcTex2->GetWidth(), srcTex2->GetHeight());

		//IdleDown
		{
			Vector2 IdleDown_endPos = Vector2(texSize2.x * 1 / 5, texSize2.y * 1 / 10);

			AnimationClip* IdleDown = new AnimationClip(L"IdleDown", srcTex2, 1, Values::ZeroVec2, IdleDown_endPos, false);
			animator->AddAnimClip(IdleDown);
		}

		//IdleUp
		{
			Vector2 IdleUp_staPos = Vector2(0, texSize2.y * 1 / 10);
			Vector2 IdleUp_endPos = Vector2(texSize2.x * 1 / 5, texSize2.y * 2 / 10);

			AnimationClip* IdleUp = new AnimationClip(L"IdleUp", srcTex2, 1, IdleUp_staPos, IdleUp_endPos, false);
			animator->AddAnimClip(IdleUp);
		}

		//IdleRight
		{
			Vector2 IdleRight_staPos = Vector2(0, texSize2.y * 2 / 10);
			Vector2 IdleRight_endPos = Vector2(texSize2.x * 1 / 5, texSize2.y * 3 / 10);

			AnimationClip* IdleRight = new AnimationClip(L"IdleRight", srcTex2, 1, IdleRight_staPos, IdleRight_endPos, false);
			animator->AddAnimClip(IdleRight);
		}

		//IdleLeft
		{
			Vector2 IdleLeft_staPos = Vector2(0, texSize2.y * 3 / 10);
			Vector2 IdleLeft_endPos = Vector2(texSize2.x * 1 / 5, texSize2.y * 4 / 10);

			AnimationClip* IdleLeft = new AnimationClip(L"IdleLeft", srcTex2, 1, IdleLeft_staPos, IdleLeft_endPos, false);
			animator->AddAnimClip(IdleLeft);
		}

		//Hurt
		{
			Vector2 Hurt_staPos = Vector2(0, texSize2.y * 4 / 10);
			Vector2 Hurt_endPos = Vector2(texSize2.x * 4 / 5, texSize2.y * 5 / 10);

			AnimationClip* Hurt = new AnimationClip(L"Hurt", srcTex2, 4, Hurt_staPos, Hurt_endPos, false);
			animator->AddAnimClip(Hurt);
		}
		
		animator->SetCurrentAnimClip(L"IdleRight");

		animRect->SetAnimator(animator);

		SAFE_DELETE(srcTex2);
	}
}

LinkAnimation::~LinkAnimation()
{
}
