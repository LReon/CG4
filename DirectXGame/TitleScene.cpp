#include "TitleScene.h"

void TitleScene::Initialize() {
	// テクスチャの読み込み
	textureHandle_ = TextureManager::Load("title.png");
	// スプライトの生成
	sprite_ = Sprite::Create(textureHandle_, {0, 0});
}

// 更新
void TitleScene::Update() {
	count += 1.0f;
	if (count > countMax) {
		count = 0.0f;
	}
}

// 描画
void TitleScene::Draw() {
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon_ = DirectXCommon::GetInstance();
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();
	Sprite::PreDraw(commandList);
	if (count >= 10.0f) {
		sprite_->Draw();
	}

	Sprite::PostDraw();
}