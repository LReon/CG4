#pragma once
#include <KamataEngine.h>
#include <list>
using namespace KamataEngine;

class TitleScene {

public:
	void Initialize();

	void Update();

	void Draw();

	float count = 0.0f;
	const float countMax = 120.0f;

private:
	uint32_t textureHandle_ = 0;

	Sprite* sprite_;
};