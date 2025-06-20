#include "GameScene.h"

// 初期化
void GameScene::Initialize() {

	Model2::StaticInitialize();

	textureHandle_ = TextureManager::Load("uvChecker.png");
	
	modelSquare_ = Model2::CreateSquare(50);
	
	camera_.Initialize();
	camera_.translation_.z = -10.0f;
	camera_.UpdateMatrix();
	
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



		modelSquare_->Draw(worldTransform_, camera_,textureHandle_);
	
	// 3Dモデル描画後処理
	Model2::PostDraw();
}

GameScene::~GameScene() {

	Model2::StaticFinalize();

}
