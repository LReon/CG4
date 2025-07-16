#include "Stage.h"
void Stage::Initialize() {
	// 内側背景テクスチャの読み込み
	insideTextureHandle_ = TextureManager::Load("backGround/inside.png");
	// 内側背景スプライトの生成
	insideSprite_ = Sprite::Create(insideTextureHandle_, {0, 0});
	// 外側背景テクスチャの読み込み
	outsideTextureHandle_ = TextureManager::Load("backGround/outside.png");
	// 外側背景スプライトの生成
	outsideSprite_ = Sprite::Create(outsideTextureHandle_, {1280, 0});
}

// 更新
void Stage::Update() {
	Vector2 insidePosition = insideSprite_->GetPosition();
	insidePosition.x -= 2.0f;
	if (insidePosition.x <= -1280.0f) {
		insidePosition.x = 1280.0f;
	}
	insideSprite_->SetPosition(insidePosition);

	Vector2 outsidePosition = outsideSprite_->GetPosition();
	outsidePosition.x -= 2.0f;
	if (outsidePosition.x <= -1280.0f) {
		outsidePosition.x = 1280.0f;
	}
	outsideSprite_->SetPosition(outsidePosition);
}

// 描画
void Stage::Draw() {
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon_ = DirectXCommon::GetInstance();
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();
	Sprite::PreDraw(commandList);

	insideSprite_->Draw();
	outsideSprite_->Draw();

	Sprite::PostDraw();
}

