#pragma once
#include "KamataEngine.h"
#include "Particle.h"

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
	Model* modelParticle_ = nullptr;

	// カメラ
	Camera camera_;

	// パーティクル
	//Particle* particle_ = nullptr;
	std::list<Particle*> particles_;
};
