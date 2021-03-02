#ifndef PARTICLE_H
#define PARTICLE_H

#include <glm/glm.hpp>
#include <learnopengl/camera.h>
#include "ParticleTexture.h"

typedef glm::vec3 vec3;
typedef glm::vec2 vec2;

extern float GRAVITY; //����ֵ ֱ�Ӵ��ⲿ��ȡ ��Main.cpp�ж��� ���������ļ��ж���
extern float deltaTime; //ÿһ֡��ʱ�� ͨ����Ⱦ��ѭ����֡��ʱ������ ��Main.cpp�� ��ȫ�ֱ���

class Particle{
private:
	vec3 position;
	vec3 velocity;
	float gravityEffect;  //��ֵ�����ϵ�
	float staticLifeLength;
	float lifeLength;
	float rotation; //��ת�Ƕ� һ������z����ת�ĽǶ�
	float scale;
	float distance = 0; //������ľ��� ������Ⱦ˳��
	float elapsedTime = 0; //�Ѿ�����ʱ��

	bool alive = false; //�����˼��

	ParticleTexture texture; //ÿһ�������ж�Ӧ������
	vec2 texOffset1; //���ӵ�ǰ��ƫ��ֵ �����׶� ����һ����λ����ռ����ǰ����������
	vec2 texOffset2;
	float blend = 0;

	void updateTextureCoordInfo();
	void setTextureOffset(vec2 &offset, int index);
	
	/*bool updateDefaultParticle();
	bool updateFireWorkParticle();
	bool updateFireParticle();
	bool updateSnowParticle();*/

public:
	Particle(const vec3& position, const vec3& velocity, float gravityEffect, float lifeLength, float rotation, float scale, const ParticleTexture& texture)
		: position(position), velocity(velocity), gravityEffect(gravityEffect),
		staticLifeLength(lifeLength), lifeLength(lifeLength), rotation(rotation), scale(scale), texture(texture)
	{}

	//�������� ����������
	void setActive(const vec3& position, const vec3& velocity, float rotation, float scale); //�����µ����� ֻ��Ҫ�ı���Щ���� �����������������ӡ��������ڳ��Ⱥ�����Ȳ���ı�
	void setActive(const vec3& position, const vec3& velocity, float rotation, float scale
	,float Lifelength); // ��������Ҳ��������
	void setNotActive();
	bool update(const Camera& camera);

	vec3 getPosition() const
	{
		return position;
	}
	float getRotation() const
	{
		return rotation;
	}
	float getScale() const
	{
		return scale;
	}
	float getStaticLifeLength() const
	{
		return staticLifeLength;
	}
	float getLifeLength() const
	{
		return lifeLength;
	}
	ParticleTexture getTexture() const
	{
		return texture;
	}
	vec2 getTexOffset1() const
	{
		return texOffset1;
	}
	vec2 getTexOffset2() const
	{
		return texOffset2;
	}
	float getBlend() const
	{
		return blend;
	}
	float getDistance() const
	{
		return distance;
	}
	bool isAlive() const
	{
		return alive;
	}
};

#endif

