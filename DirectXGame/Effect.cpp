#include "Effect.h"
#include <algorithm>
#include <cassert>
#include "random"

using namespace MathUtility;

// 初期化
void Effect::Initialize(Model* model, Vector3 position, Vector3 rotation, Vector3 scale) {

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
	//velocity_ = velocity;

	// 大きさ
	//worldTransform_.scale_ = {10.0f, 1.0f, 1.0f};

	worldTransform_.rotation_ = rotation;
	worldTransform_.scale_ = scale;
}

// 更新
void Effect::Update() {

	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);

	// 移動
	//worldTransform_.translation_ += {0.0f + velocity_.x, 0.1f + velocity_.y, 0.0f + velocity_.z};

	if (isFinished_) {
		return;
	}

	// カウンターを1フレーム分秒数進める
	counter_ += 1.0f / 10.0f;

	// 存続時間の上昇に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了扱いにする
		isFinished_ = true;
	}

	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	//// 行列を定数バッファに転送
	// worldTransform_.TransferMatrix();

	// 行列を更新
	worldTransform_.UpdateMatrix();
}

// 描画
void Effect::Draw(Camera& camera) {

	// 3Dモデルの描画
	model_->Draw(worldTransform_, camera, &objectColor_);
}
