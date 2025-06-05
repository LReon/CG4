#include "GameScene.h"

// 初期化
void GameScene::Initialize() {
	
	Model2::StaticInitialize();
	//model2_ = Model2::CreateSphere(4, 4);
	camera_.Initialize();
	worldTransform_.Initialize();
}

// 更新
void GameScene::Update() {}

// 描画
void GameScene::Draw() { 
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommon->GetCommandList());

	model2_->Draw(worldTransform_,camera_);

	// 3Dモデル描画後処理
	Model2::PostDraw();
}

GameScene::~GameScene() {

	Model2::StaticFinalize();

}
