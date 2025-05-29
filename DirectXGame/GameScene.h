#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "Effect.h"

using namespace KamataEngine;

class GameScene {

public:
	// 初期化
	void Initialize();

	// デストラクタ
	~GameScene();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	// パーティクル3Dモデル
	Model* modelEffect_ = nullptr;

	// カメラ
	Camera camera_;

	// パーティクル
	//Particle* particle_ = nullptr;
	std::list<Effect*> effects_;
};
