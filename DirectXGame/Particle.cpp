#include "Particle.h"
#include <cassert>

using namespace MathUtility;

// 初期化
void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity) {

	// NULLポインタチェック
	assert(model);
	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	// ワールド変換の初期化
	worldTransform_.Initialize();

	// 色の設定
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	// パーティクルの位置
	worldTransform_.translation_ = position;
	// 引数として受け取ったデータをメンバ変数に記録する
	velocity_ = velocity;

	// 大きさ
	worldTransform_.scale_ = {0.2f, 0.2f, 0.2f};
}

// 更新
void Particle::Update() {
	
	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);

	// 移動
	worldTransform_.translation_ += {0.0f + velocity_.x, 0.1f + velocity_.y, 0.0f + velocity_ .z};

	

	//// 行列を定数バッファに転送
	//worldTransform_.TransferMatrix();

	// 行列を更新
	worldTransform_.UpdateMatrix();

}

// 描画
void Particle::Draw(Camera& camera) {

	// 3Dモデルの描画
	model_->Draw(worldTransform_, camera,&objectColor_);

}
