#include "Effect.h"

void Effect::Initialize(Model* model, Camera* camera) {

// NULL
	worldTransform_.Initialize();
	

	model_ = model;

	camera_ = camera;
	
}

void Effect::Update() {

	// ワールド変換行列の更新
	
	
	
}

void Effect::Draw() {

	model_->Draw(worldTransform_, *camera_);

}
