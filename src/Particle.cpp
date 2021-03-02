#include "Particle.h"
#include <iostream>

bool Particle::update(const Camera& camera)
{
	{
		velocity.y += GRAVITY * gravityEffect * deltaTime; //粒子Y方向速度的变化 v = v + a*t  相当于前面就是加速度deltaTime就是时间间隔
		position += velocity * deltaTime; //新的位置 s += v*t
		elapsedTime += deltaTime;
		updateTextureCoordInfo();
		if (!texture.getIsAdditve()) //如果不是additive混合才需要计算并更新距离
		{
			// distance = glm::length(camera.Position - position); // 优化
			auto disVec = camera.Position - position;
			distance = glm::dot(disVec, disVec);
		}
		return elapsedTime < lifeLength;
	}
}

void Particle::updateTextureCoordInfo()
{
	float lifeFactor = elapsedTime / lifeLength;
	int stageCount = texture.getNumberOfRows() * texture.getNumberOfRows(); //阶段的总格子数
	float atlasProgression = lifeFactor * stageCount; //目前的阶段 是一个float数 要划分为两个格子 且计算偏移值（浮点数）
	int index1 = (int)floor(atlasProgression); //向下取整
	int index2 = index1 < stageCount - 1 ? index1 + 1 : index1; //防止溢出 如25个格子 边界下标为24 不能>=24 否则不能+1
	blend = atlasProgression - index1; //偏移值 或者说混合 如5.6-5=0.6
	setTextureOffset(texOffset1, index1);
	setTextureOffset(texOffset2, index2);
}

void Particle::setTextureOffset(vec2& offset, int index)
{
	int rows = texture.getNumberOfRows();
	int column = index % rows;
	int row = index / rows;
	offset.x = (float)column / rows; //映射到0-1
	offset.y = (float)row / rows;
}

void Particle::setActive(const vec3& position, const vec3& velocity, float rotation, float scale)
{
	this->alive = true; //活了
	this->position = position;
	this->velocity = velocity;
	this->rotation = rotation;
	this->scale = scale;
	this->elapsedTime = 0; //激活的时候重置存活时间
}

void Particle::setActive(const vec3& position, const vec3& velocity, float rotation, float scale,
	float Lifelength)
{
	this->alive = true; //活了
	this->position = position;
	this->velocity = velocity;
	this->rotation = rotation;
	this->scale = scale;
	this->lifeLength = Lifelength;
	this->elapsedTime = 0; //激活的时候重置存活时间
}

void Particle::setNotActive()
{
	this->alive = false;
}