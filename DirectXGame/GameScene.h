#pragma once
#include "Effect.h"
#include "KamataEngine.h"

using namespace KamataEngine;

class GameScene {

public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	Effect* effect_ = nullptr; // エフェクトクラスのポインタ
	//Camera camera_;
	Model* modelEffectResource_ = nullptr;

private:
	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	// ビュープロジェクション
	Camera camera_;

	Model* effectModel_ = nullptr; // エフェクトモデル

};
