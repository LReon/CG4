#pragma once
#include "KamataEngine.h"
#include "Particle.h"



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

	// パーティクル発生
	void ParticleBorn(KamataEngine::Vector3 position);

private:
	// パーティクル3Dモデル
	KamataEngine::Model* modelParticle_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;

	// パーティクル
	//Particle* particle_ = nullptr;
	std::list<Particle*> particles_;
};
