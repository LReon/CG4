#include "Player.h"
#include <KamataEngine.h>

using namespace KamataEngine;

void Player::Initialize(Camera* camera) {
	// モデルの初期化
	playerModel = Model::Create();
	textureHandle = TextureManager::Load("uvChecker.png");
	
	
	// ワールド変形の初期化
	worldTransform.Initialize();
	// カメラの初期化
	camera_ = camera;
	//camera->translation_.z = -10.0f;
	//camera->UpdateMatrix();
}

void Player::Update() {

	worldTransform.scale_ = {0.5f, 0.5f, 0.5f}; // スケールの設定
	// 入力処理などの更新処理をここに追加
	// 例: キーボード入力による移動
	if (Input::GetInstance()->PushKey(DIK_A)) {
		worldTransform.translation_.x -= 0.5f;
	}
	if (Input::GetInstance()->PushKey(DIK_D)) {
		worldTransform.translation_.x += 0.5f;
	}
	if (Input::GetInstance()->PushKey(DIK_W)) {
		worldTransform.translation_.y += 0.5f;
	}
	if (Input::GetInstance()->PushKey(DIK_S)) {
		worldTransform.translation_.y -= 0.5f;
	}
	
	
	worldTransform.UpdateMatrix();
}

void Player::Draw() {
	// モデルの描画
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon_ = DirectXCommon::GetInstance();
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();
	Model::PreDraw(commandList);
	playerModel->Draw(worldTransform, *camera_,textureHandle);
	Model::PostDraw();
}