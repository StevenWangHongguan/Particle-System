#include "Particle.h"
#include "Math.h"

struct ParticleInfo{
	vec3 position;
	vec3 velocity;
	float rotation;
	float scale;
	float lifeLength; // add
};

ParticleInfo getFireworksParticleInfo(const vec3& center, float speed)
{
	ParticleInfo fireworksParticleInfo;

	float dirX = randomFloat() * 0.5 - 0.25f; // ת���ɣ�-0.25��0.25��
	float dirZ = randomFloat() * 0.5 - 0.25f;
	vec3 velocity(dirX, 1.0f, dirZ); // ��ʼY�����ٶȶ�Ϊ1 ��ֱ����
	velocity = glm::normalize(velocity); // ������ ��Ϊ�˽��ٶ�ֵ��С��Ϊ1
	velocity *= speed; // ��������ٶ� ���������������֮�� Ҳ�����ٶȵĴ�С��Ϊspeed��

	fireworksParticleInfo.position = center;
	fireworksParticleInfo.velocity = velocity;
	fireworksParticleInfo.rotation = 0.0f;
	fireworksParticleInfo.scale = randomFloat() * 0.6;

	//float dirX = random(); // ת���ɣ�-0.25��0.25��
	//float dirY = random();
	//float dirZ = random();
	//vec3 velocity(dirX, dirY, dirZ); // ��ʼY�����ٶȶ�Ϊ1 ��ֱ����
	//velocity = glm::normalize(velocity); // ������ ��Ϊ�˽��ٶ�ֵ��С��Ϊ1
	//velocity *= speed; // ��������ٶ� ���������������֮�� Ҳ�����ٶȵĴ�С��Ϊspeed��

	//fireworksParticleInfo.position = center;
	//fireworksParticleInfo.velocity = velocity;
	//fireworksParticleInfo.rotation = 0.0f;
	//fireworksParticleInfo.scale = randomFloat() * 0.1;

	return fireworksParticleInfo;
}

ParticleInfo getFireParticleInfo(const vec3& center, float speed, float lifeLength)
{
	ParticleInfo fireParticleInfo;

	// 1-�����
	float dirX = randomFloat() * 0.5 - 0.25f; 
	float dirZ = randomFloat() * 0.5 - 0.25f; 
	vec3 velocity(dirX, 1.0f, dirZ); // y 1.0f
	velocity = glm::normalize(velocity); 
	velocity *= speed; 

	fireParticleInfo.position = center;
	fireParticleInfo.velocity = velocity;
	fireParticleInfo.rotation = 0.0f;
	fireParticleInfo.scale = 3.0f;
	fireParticleInfo.lifeLength = lifeLength;

	// 2-Բ��
	//float posX = 0, posZ = 0;
	//float radius = 1.0f;
	//while (true)
	//{
	//	posX = random() * radius;
	//	posZ = random() * radius;
	//	if (posX * posX + posZ * posZ < radius * radius)
	//		break;
	//}
	//vec3 posOffset(posX, 0, posZ);
	//vec3 velocity(0.0f, 1.0f, 0.0f);

	//fireParticleInfo.position = center + posOffset;
	//fireParticleInfo.velocity = velocity;
	//fireParticleInfo.rotation = 0.0f;
	//fireParticleInfo.scale = 1.5f;

	//float lifeLengthFactor = 1.0f / (glm::length(posOffset) + 0.7); // +0.1�Ƿ�ֹ��������̫�� ����̫��
	//fireParticleInfo.lifeLength = lifeLengthFactor * lifeLength;

	return fireParticleInfo;
}

ParticleInfo getSmokeParticleInfo(const vec3& center, float speed)
{
	ParticleInfo smokeParticleInfo;

	float posX = randomFloat() * 0.5 - 0.25f;
	float posZ = randomFloat() * 0.5 - 0.25f;
	vec3 posOffset(posX, 0.0f, posZ);

	float dirX = randomFloat() * 0.01 - 0.005f;
	float dirZ = randomFloat() * 0.01 - 0.005f;
	vec3 velocity(dirX, 0.05, dirZ); // ��ʼY�����ٶȶ�Ϊ1 ��ֱ����
	velocity = glm::normalize(velocity); // ������ ��Ϊ�˽��ٶ�ֵ��С��Ϊ1
	velocity *= speed; // ��������ٶ� ���������������֮�� Ҳ�����ٶȵĴ�С��Ϊspeed��

	smokeParticleInfo.position = center + posOffset;
	smokeParticleInfo.velocity = velocity;
	smokeParticleInfo.rotation = 0.0f;
	smokeParticleInfo.scale = 1.0f;
	return smokeParticleInfo;
}

ParticleInfo getSnowParticleInfo(const vec3& center, float speed) //������
{
	ParticleInfo snowParticleInfo;

	float posX = randomFloat() * 5 - 10.0f; //[-5,5]
	float posZ = randomFloat() * 5 - 10.0f;
	vec3 posOffset(posX, 0.0f, posZ);

	float dirX = randomFloat() * 2 - 1.0f; // ת���ɣ�-1��1��
	float dirZ = randomFloat() * 2 - 1.0f;
	vec3 velocity(dirX, 0.0f, dirZ); // ��ʼY�����ٶȶ�Ϊ1 ��ֱ����
	velocity = glm::normalize(velocity); // ������ ��Ϊ�˽��ٶ�ֵ��С��Ϊ1
	velocity *= speed; // ��������ٶ� ���������������֮�� Ҳ�����ٶȵĴ�С��Ϊspeed��

	snowParticleInfo.position = center + posOffset;
	snowParticleInfo.velocity = velocity;
	snowParticleInfo.rotation = randomFloat() * 360; // 0-randomFloat()
	snowParticleInfo.scale = randomFloat() * 0.2;
	//snowParticleInfo.scale = pow(EXPONENT, snowParticleInfo.velocity.z) * 0.1; // ����ԶС

	return snowParticleInfo;
}

ParticleInfo getStarParticleInfo(const vec3& center, float speed)
{
	ParticleInfo starParticleInfo;

	float posX = randomFloat() * 1 - 2.0f; //[-5,5]
	float posZ = randomFloat() * 5 - 10.0f;
	vec3 posOffset(posX, 0.0f, posZ);

	float dirX = randomFloat() * 0.5 - 0.25f; // ת���ɣ�-1��1��
	float dirZ = randomFloat() ; // ת���ɣ�-1��0��
	vec3 velocity(dirX, 0.0f, dirZ); // ��ʼY�����ٶȶ�Ϊ1 ��ֱ����
	velocity = glm::normalize(velocity); // ������ ��Ϊ�˽��ٶ�ֵ��С��Ϊ1
	velocity *= speed; // ��������ٶ� ���������������֮�� Ҳ�����ٶȵĴ�С��Ϊspeed��

	starParticleInfo.position = center + posOffset;
	starParticleInfo.velocity = velocity;
	starParticleInfo.rotation = 0.0f;
	starParticleInfo.scale = (randomFloat() + 5.0) / 2;

	return starParticleInfo;
}

ParticleInfo getCosmicParticleInfo(const vec3& center, float speed)
{
	ParticleInfo cosmicParticleInfo;

	//float dirX = randomFloat() * 0.5 - 0.25f;
	float dirZ = randomFloat() * 2 - 1.0f;
	vec3 velocity(-2.0f, 0.0f, dirZ);
	velocity = glm::normalize(velocity);
	velocity *= speed;

	cosmicParticleInfo.position = center;
	cosmicParticleInfo.velocity = velocity;
	cosmicParticleInfo.rotation = 0.0f; //Ҫ������ת��
	cosmicParticleInfo.scale = 0.7f; //�Ƕ������ţ�

	return cosmicParticleInfo;
}

ParticleInfo getDefaultParticleInfo(const vec3& center, float speed)
{
	ParticleInfo defaultParticleInfo;
	float dirX = randomFloat() * 2 - 1.0f; // ת���ɣ�-1��1��
	float dirZ = randomFloat() * 2 - 1.0f;
	vec3 velocity(dirX, 0.0f, dirZ); // ��ʼY�����ٶȶ�Ϊ1 ��ֱ����
	velocity = glm::normalize(velocity); // ������ ��Ϊ�˽��ٶ�ֵ��С��Ϊ1
	velocity *= speed; // ��������ٶ� ���������������֮�� Ҳ�����ٶȵĴ�С��Ϊspeed��

	defaultParticleInfo.position = center;
	defaultParticleInfo.velocity = velocity;
	defaultParticleInfo.rotation = 0.0f;
	defaultParticleInfo.scale = 1.0f;
	return defaultParticleInfo;
}