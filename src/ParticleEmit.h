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

	float dirX = randomFloat() * 0.5 - 0.25f; // 转换成（-0.25，0.25）
	float dirZ = randomFloat() * 0.5 - 0.25f;
	vec3 velocity(dirX, 1.0f, dirZ); // 初始Y方向速度都为1 竖直向上
	velocity = glm::normalize(velocity); // 正交化 是为了将速度值大小设为1
	velocity *= speed; // 方向乘上速度 这样三个方向分量之和 也就是速度的大小就为speed了

	fireworksParticleInfo.position = center;
	fireworksParticleInfo.velocity = velocity;
	fireworksParticleInfo.rotation = 0.0f;
	fireworksParticleInfo.scale = randomFloat() * 0.6;

	//float dirX = random(); // 转换成（-0.25，0.25）
	//float dirY = random();
	//float dirZ = random();
	//vec3 velocity(dirX, dirY, dirZ); // 初始Y方向速度都为1 竖直向上
	//velocity = glm::normalize(velocity); // 正交化 是为了将速度值大小设为1
	//velocity *= speed; // 方向乘上速度 这样三个方向分量之和 也就是速度的大小就为speed了

	//fireworksParticleInfo.position = center;
	//fireworksParticleInfo.velocity = velocity;
	//fireworksParticleInfo.rotation = 0.0f;
	//fireworksParticleInfo.scale = randomFloat() * 0.1;

	return fireworksParticleInfo;
}

ParticleInfo getFireParticleInfo(const vec3& center, float speed, float lifeLength)
{
	ParticleInfo fireParticleInfo;

	// 1-火炬型
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

	// 2-圆形
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

	//float lifeLengthFactor = 1.0f / (glm::length(posOffset) + 0.7); // +0.1是防止距离中心太近 倒数太大
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
	vec3 velocity(dirX, 0.05, dirZ); // 初始Y方向速度都为1 竖直向上
	velocity = glm::normalize(velocity); // 正交化 是为了将速度值大小设为1
	velocity *= speed; // 方向乘上速度 这样三个方向分量之和 也就是速度的大小就为speed了

	smokeParticleInfo.position = center + posOffset;
	smokeParticleInfo.velocity = velocity;
	smokeParticleInfo.rotation = 0.0f;
	smokeParticleInfo.scale = 1.0f;
	return smokeParticleInfo;
}

ParticleInfo getSnowParticleInfo(const vec3& center, float speed) //待调整
{
	ParticleInfo snowParticleInfo;

	float posX = randomFloat() * 5 - 10.0f; //[-5,5]
	float posZ = randomFloat() * 5 - 10.0f;
	vec3 posOffset(posX, 0.0f, posZ);

	float dirX = randomFloat() * 2 - 1.0f; // 转换成（-1，1）
	float dirZ = randomFloat() * 2 - 1.0f;
	vec3 velocity(dirX, 0.0f, dirZ); // 初始Y方向速度都为1 竖直向上
	velocity = glm::normalize(velocity); // 正交化 是为了将速度值大小设为1
	velocity *= speed; // 方向乘上速度 这样三个方向分量之和 也就是速度的大小就为speed了

	snowParticleInfo.position = center + posOffset;
	snowParticleInfo.velocity = velocity;
	snowParticleInfo.rotation = randomFloat() * 360; // 0-randomFloat()
	snowParticleInfo.scale = randomFloat() * 0.2;
	//snowParticleInfo.scale = pow(EXPONENT, snowParticleInfo.velocity.z) * 0.1; // 近大远小

	return snowParticleInfo;
}

ParticleInfo getStarParticleInfo(const vec3& center, float speed)
{
	ParticleInfo starParticleInfo;

	float posX = randomFloat() * 1 - 2.0f; //[-5,5]
	float posZ = randomFloat() * 5 - 10.0f;
	vec3 posOffset(posX, 0.0f, posZ);

	float dirX = randomFloat() * 0.5 - 0.25f; // 转换成（-1，1）
	float dirZ = randomFloat() ; // 转换成（-1，0）
	vec3 velocity(dirX, 0.0f, dirZ); // 初始Y方向速度都为1 竖直向上
	velocity = glm::normalize(velocity); // 正交化 是为了将速度值大小设为1
	velocity *= speed; // 方向乘上速度 这样三个方向分量之和 也就是速度的大小就为speed了

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
	cosmicParticleInfo.rotation = 0.0f; //要试试旋转吗
	cosmicParticleInfo.scale = 0.7f; //是多少来着？

	return cosmicParticleInfo;
}

ParticleInfo getDefaultParticleInfo(const vec3& center, float speed)
{
	ParticleInfo defaultParticleInfo;
	float dirX = randomFloat() * 2 - 1.0f; // 转换成（-1，1）
	float dirZ = randomFloat() * 2 - 1.0f;
	vec3 velocity(dirX, 0.0f, dirZ); // 初始Y方向速度都为1 竖直向上
	velocity = glm::normalize(velocity); // 正交化 是为了将速度值大小设为1
	velocity *= speed; // 方向乘上速度 这样三个方向分量之和 也就是速度的大小就为speed了

	defaultParticleInfo.position = center;
	defaultParticleInfo.velocity = velocity;
	defaultParticleInfo.rotation = 0.0f;
	defaultParticleInfo.scale = 1.0f;
	return defaultParticleInfo;
}