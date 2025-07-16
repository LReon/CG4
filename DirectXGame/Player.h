#pragma once
#include <KamataEngine.h>


using namespace KamataEngine;

class Player {
	
public:
	void Initialize(Camera* camera);

	void Update();
	
	void Draw();

private:

	Model* playerModel = nullptr;

	uint32_t textureHandle = 0;

	WorldTransform worldTransform;
	
	Camera* camera_ = nullptr;
\

};
