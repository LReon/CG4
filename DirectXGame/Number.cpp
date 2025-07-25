#include "Number.h"

void Number::Initialize() {
	// テクスチャの読み込み
	textureHandle = TextureManager::Load("number.png");
	// スプライトの生成
	for (int i = 0; i < 5; ++i) {
		sprite[i] = Sprite::Create(textureHandle, {100.0f + size.x * i,5});
		sprite[i]->SetSize(size);
	}
}

void Number::Update() { 
	for (int i = 0; i < 5; i++) {
		sprite[i]->SetTextureRect({0,0}, size);
	}
	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		hp = 60000;
	}
	hp -= 200;
	if (hp < 0) {
		hp = 0;
	}
	
}

void Number::Draw() {
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon_ = DirectXCommon::GetInstance();
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();
	Sprite::PreDraw(commandList);
	// スプライトを描画
	digit = 10000;
	number = hp;
	
	for (int i = 0; i < 5; ++i) {
		int nowNumber = number / digit;
		sprite[i]->SetTextureRect({size.x * nowNumber, 0},size);
		number %= digit;
		digit /= 10;
		sprite[i]->Draw();
	}
	Sprite::PostDraw();
}
