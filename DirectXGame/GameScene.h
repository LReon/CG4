#pragma once
#include "KamataEngine.h"
#include "Model2.h"
#include "TitleScene.h"
#include "Player.h"

using namespace KamataEngine;

class GameScene {

public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	// 解放
	~GameScene();

	

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model2* modelSquare_ = nullptr;

	uint32_t textureHandle_ = 0;

	Camera* camera_;

	TitleScene titleScene_;

	Player* player_;

};
