#include "GameScene.h"

// 初期化
void GameScene::Initialize() {

	Model2::StaticInitialize();

	textureHandle_ = TextureManager::Load("uvChecker.png");
	
	modelSquare_ = Model2::CreateSquare(50);

	titleScene_.Initialize();
	stage_.Initialize();

	camera_ = new Camera();
	camera_->Initialize();
	camera_->translation_.z = -10.0f;
	camera_->UpdateMatrix();
	player_ = new Player();

	player_->Initialize(camera_);

	worldTransform_.Initialize();
	
	
}

// 更新
void GameScene::Update() {

	//titleScene_.Update();
	stage_.Update();
	player_->Update();
}

// 描画
void GameScene::Draw() { 
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	Sprite::PreDraw(dxCommon->GetCommandList());
	//titleScene_.Draw();
	stage_.Draw();
	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();
	Model::PreDraw(dxCommon->GetCommandList());
	player_->Draw();
	Model::PostDraw();

	Sprite::PreDraw(dxCommon->GetCommandList());
	Sprite::PostDraw();

}

GameScene::~GameScene() {

	Model2::StaticFinalize();
	delete camera_;

}
