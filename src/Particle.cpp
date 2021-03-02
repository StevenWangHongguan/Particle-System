#include "Particle.h"
#include <iostream>

bool Particle::update(const Camera& camera)
{
	{
		velocity.y += GRAVITY * gravityEffect * deltaTime; //����Y�����ٶȵı仯 v = v + a*t  �൱��ǰ����Ǽ��ٶ�deltaTime����ʱ����
		position += velocity * deltaTime; //�µ�λ�� s += v*t
		elapsedTime += deltaTime;
		updateTextureCoordInfo();
		if (!texture.getIsAdditve()) //�������additive��ϲ���Ҫ���㲢���¾���
		{
			// distance = glm::length(camera.Position - position); // �Ż�
			auto disVec = camera.Position - position;
			distance = glm::dot(disVec, disVec);
		}
		return elapsedTime < lifeLength;
	}
}

void Particle::updateTextureCoordInfo()
{
	float lifeFactor = elapsedTime / lifeLength;
	int stageCount = texture.getNumberOfRows() * texture.getNumberOfRows(); //�׶ε��ܸ�����
	float atlasProgression = lifeFactor * stageCount; //Ŀǰ�Ľ׶� ��һ��float�� Ҫ����Ϊ�������� �Ҽ���ƫ��ֵ����������
	int index1 = (int)floor(atlasProgression); //����ȡ��
	int index2 = index1 < stageCount - 1 ? index1 + 1 : index1; //��ֹ��� ��25������ �߽��±�Ϊ24 ����>=24 ������+1
	blend = atlasProgression - index1; //ƫ��ֵ ����˵��� ��5.6-5=0.6
	setTextureOffset(texOffset1, index1);
	setTextureOffset(texOffset2, index2);
}

void Particle::setTextureOffset(vec2& offset, int index)
{
	int rows = texture.getNumberOfRows();
	int column = index % rows;
	int row = index / rows;
	offset.x = (float)column / rows; //ӳ�䵽0-1
	offset.y = (float)row / rows;
}

void Particle::setActive(const vec3& position, const vec3& velocity, float rotation, float scale)
{
	this->alive = true; //����
	this->position = position;
	this->velocity = velocity;
	this->rotation = rotation;
	this->scale = scale;
	this->elapsedTime = 0; //�����ʱ�����ô��ʱ��
}

void Particle::setActive(const vec3& position, const vec3& velocity, float rotation, float scale,
	float Lifelength)
{
	this->alive = true; //����
	this->position = position;
	this->velocity = velocity;
	this->rotation = rotation;
	this->scale = scale;
	this->lifeLength = Lifelength;
	this->elapsedTime = 0; //�����ʱ�����ô��ʱ��
}

void Particle::setNotActive()
{
	this->alive = false;
}