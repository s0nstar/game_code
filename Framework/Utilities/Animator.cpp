#include "Framework.h"
#include "Animator.h"

AnimationClip::AnimationClip(wstring clipName, Texture2D* srcTex, UINT frameCount, Vector2 startPos, Vector2 endPos, bool bReversed, float playRate)
	: clipName(clipName), frameCount(frameCount), playRate(playRate), bReversed(bReversed)
{
	srv = srcTex->GetSRV();

	// �ؽ�ó�� �ʺ�� ����
	float imageWidth = srcTex->GetWidth();
	float imageHeight = srcTex->GetHeight();

	// Ŭ�� ������ (�ִϸ��̼��� �׷����ִ� �ؽ�ó�� ����)
	Vector2 clipSize = endPos - startPos;

	// ������ ������ (�ִϸ��̼� �׸� �� �ϳ�)
	Vector2 frameSize;
	frameSize.x = clipSize.x / frameCount;
	frameSize.y = clipSize.y;

	// �ؼ� ������ ���
	texelFrameSize.x = frameSize.x / imageWidth;
	texelFrameSize.y = frameSize.y / imageHeight;

	// �ؼ� ���� ��ġ
	Vector2 texelStartPos;
	texelStartPos.x = startPos.x / imageWidth;
	texelStartPos.y = startPos.y / imageHeight;

	Vector2 keyframe;

	for (UINT i = 0; i < frameCount; i++)
	{
		keyframe.x = texelStartPos.x + (texelFrameSize.x * i);
		keyframe.y = texelStartPos.y;

		keyFrames.push_back(keyframe);
	}
}

Animator::Animator()
{
}

Animator::~Animator()
{
	for (auto clip : animClips)
		SAFE_DELETE(clip.second);
}

void Animator::Update()
{
	if (deltaTime > currentClip->playRate)
	{
		if (currentClip->bReversed == false)
		{
			currentFrameIndex++;

			if (currentFrameIndex == currentClip->frameCount)
				currentFrameIndex = 0;

			currentFrame = currentClip->keyFrames[currentFrameIndex];
		}
		else
		{
			currentFrameIndex--;

			if (currentFrameIndex == -1)
				currentFrameIndex = currentClip->frameCount - 1;

			currentFrame = currentClip->keyFrames[currentFrameIndex];
		}
		deltaTime = 0.f;
	}
	else
		deltaTime += Time::Delta();
}

void Animator::AddAnimClip(AnimationClip* animClip)
{
	animClips.insert(make_pair(animClip->clipName, animClip));
}

void Animator::SetCurrentAnimClip(wstring clipName)
{
	if (currentClip == nullptr && CheckExist(clipName) == true)
		currentClip = animClips.find(clipName)->second;
	else if (currentClip != nullptr && currentClip->clipName == clipName)
		return;

	if (CheckExist(clipName))
	{
		currentClip = animClips.find(clipName)->second;
		deltaTime = .0f;

		// ������� Ȱ��ȭ �Ǿ��ִ� ���
		if (currentClip->bReversed == true)
			currentFrameIndex = currentClip->frameCount - 1;
		else
			currentFrameIndex = 0;

		// ���� ������ ������Ʈ
		currentFrame = currentClip->keyFrames[currentFrameIndex];
	}
}
