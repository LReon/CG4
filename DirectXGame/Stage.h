#pragma once
#include <list>
#include <KamataEngine.h>

using namespace KamataEngine;
class Stage {
public:
	void Initialize();

	void Update();

	void Draw();

private:
	uint32_t insideTextureHandle_ = 0;

	Sprite* insideSprite_ = nullptr;

	uint32_t outsideTextureHandle_ = 0;

	Sprite* outsideSprite_ = nullptr;


};
