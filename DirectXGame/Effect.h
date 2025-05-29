#pragma once
#include "KamataEngine.h"
#include "MathUtilityForText.h"

using namespace KamataEngine;

class Effect {

public:
	void Initialize(Model* model, Camera* camera);
	void Update();
	void Draw();

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;

	// テクスチャハンドル
	//uint32_t textureHandle_ = 0u;

	Camera* camera_ = nullptr;

};
