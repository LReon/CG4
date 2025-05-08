#include "GameScene.h"
#include <random>
std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

using namespace MathUtility;

// 初期化
void GameScene::Initialize() {

	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	camera_.Initialize();
	camera_.translation_ = {0.0f, 0.0f, -50.0f};
	camera_.UpdateMatrix();
	// パーティクルの生成
	//particle_ = new Particle();

	// 乱数の初期化
	srand((unsigned)time(NULL));
	
}

GameScene::~GameScene() {

	delete modelParticle_;
	//delete particle_;
	// パーティクルの解放
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
}

// 更新
void GameScene::Update() {

	// 確率で発生
	if (rand() % 20 == 0) {
	
	// 発生位置は乱数
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 30.0f, 0.0f};

		ParticleBorn(position);
	}


	// パーティクルの更新
	for (Particle* particle : particles_) {
	
		particle->Update();
	}
		// パーティクルの移動
	particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()) {
			delete particle;
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
	for (Particle* particle : particles_) {

		particle->Draw(camera_);
	}

	// 3Dモデル描画後処理
	Model::PostDraw();

}

void GameScene::ParticleBorn(Vector3 position) {

	for (int i = 0; i < 150; i++) {
		// 生成
		Particle* particle = new Particle();
		
		// 移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
		// 初期化
		particle->Initialize(modelParticle_, position, velocity);
		// リスト追加
		particles_.push_back(particle);

		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;
	}

	
	// パーティクルの初期化
	// particle_->Initialize(modelParticle_,position);


}
