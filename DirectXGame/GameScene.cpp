#include "GameScene.h"
#include <random>
std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

using namespace MathUtility;

// 初期化
void GameScene::Initialize() {

	// 3Dモデルデータの生成
	modelEffect_ = Model::CreateSphere(2, 2);

	camera_.Initialize();
	camera_.translation_ = {0.0f, 0.0f, -20.0f};
	camera_.UpdateMatrix();
	// パーティクルの生成
	//particle_ = new Particle();

	for (int i = 0; i < 150; i++) {
		// 生成
		Effect* effect = new Effect();
		// 位置
		Vector3 position = {0.0f, 0.0f, 0.0f};
		// 移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
		// 初期化
		effect->Initialize(modelEffect_, position,velocity);
		// リスト追加
		effects_.push_back(effect);
	
		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;
	}

	// 位置
	Vector3 position = {0.0f, 0.0f, 0.0f};
	// パーティクルの初期化
	//particle_->Initialize(modelParticle_,position);
	

}

GameScene::~GameScene() {

	delete modelEffect_;
	//delete particle_;
	// パーティクルの解放
	for (Effect* effect : effects_) {
		delete effect;
	}
	effects_.clear();
}

// 更新
void GameScene::Update() {

	// パーティクルの更新
	for (Effect* effect : effects_) {
	
		effect->Update();
	}
		// パーティクルの移動
	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			delete effect;
			return true;
		}
		else {
			return false;
		}
		});
	}



// 描画
void GameScene::Draw() {

	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// パーティクル描画
	for (Effect* effect : effects_) {

		effect->Draw(camera_);
	}

	// 3Dモデル描画後処理
	Model::PostDraw();

}
