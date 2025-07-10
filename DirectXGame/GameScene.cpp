#include "GameScene.h"

// 初期化
void GameScene::Initialize() {

	Model2::StaticInitialize();

	textureHandle_ = TextureManager::Load("uvChecker.png");
	
	modelSquare_ = Model2::CreateSquare(50);

	titleScene_.Initialize();
	
	camera_.Initialize();
	camera_.translation_.z = -10.0f;
	camera_.UpdateMatrix();
	
	worldTransform_.Initialize();
	
	
}

// 更新
void GameScene::Update() {

	titleScene_.Update();

}

// 描画
void GameScene::Draw() { 
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon->GetCommandList();
	// スプライト描画前処理
	Sprite::PreDraw(commandList);
	titleScene_.Draw();

	// 3Dモデル描画前処理
	Model2::PreDraw(dxCommon->GetCommandList());



		//modelSquare_->Draw(worldTransform_, camera_,textureHandle_);
	
	// 3Dモデル描画後処理
	Model2::PostDraw();
}

GameScene::~GameScene() {

	Model2::StaticFinalize();

}
