#include "GameScene.h"

// 初期化
void GameScene::Initialize() {

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	// ビュープロジェクションの初期化
	camera_.Initialize();
	// エフェクトクラスのインスタンスを生成
	effect_ = new Effect();
	effectModel_ = Model::CreateFromOBJ("effect", true);
	effect_->Initialize(effectModel_, &camera_);
	

}

// 更新
void GameScene::Update() {

	// エフェクトクラスの更新
	effect_->Update();
	

}

// 描画
void GameScene::Draw() {

	// エフェクトクラスの描画
	effect_->Draw();


}
