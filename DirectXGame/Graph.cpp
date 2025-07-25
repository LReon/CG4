#include "Graph.h"

void Graph::Initialize() {
	// テクスチャの読み込み
	redTextureHandle_ = TextureManager::Load("white1x1.png");
	greenTextureHandle_ = TextureManager::Load("white1x1.png");
	// スプライトの生成
	redSprite_ = Sprite::Create(redTextureHandle_, {0, 0});
	greenSprite_ = Sprite::Create(greenTextureHandle_, {0, 0});

	redSprite_->SetPosition({100, 100});
	greenSprite_->SetPosition({100, 100});
	redSprite_->SetSize({300, 20});
	greenSprite_->SetSize({300, 20});
	redSprite_->SetColor({1, 0, 0, 0.8f});
	greenSprite_->SetColor({0, 1, 0, 0.8f});
}

void Graph::Update() { 
	Vector2 spriteSize = {greenSprite_->GetSize()}; 
	spriteSize.x -= 1.0f;
	if (spriteSize.x < 0) {
		spriteSize.x = 0;
	}
	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		spriteSize.x = 300.0f;
	}
	greenSprite_->SetSize(spriteSize);
}


void Graph::Draw() {
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon_ = DirectXCommon::GetInstance();
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();
	Sprite::PreDraw(commandList);
	// 赤いスプライトを描画
	redSprite_->Draw();
	// 緑のスプライトを描画
	greenSprite_->Draw();
	Sprite::PostDraw();
}