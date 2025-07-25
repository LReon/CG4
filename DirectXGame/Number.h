#pragma once
#include <KamataEngine.h>
using namespace KamataEngine;

class Number {

public:

	void Initialize();

	Vector2 size = {32.0f, 64.0f};
	int32_t digit = 10000;
	int number = 0;
	int hp = 60000;
	

	void Update();

	void Draw();

private:
	Sprite* sprite[5] = {};
	uint32_t textureHandle = 0u;
};
