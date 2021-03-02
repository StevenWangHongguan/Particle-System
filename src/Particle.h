#ifndef PARTICLE_H
#define PARTICLE_H

#include <glm/glm.hpp>
#include <learnopengl/camera.h>
#include "ParticleTexture.h"

typedef glm::vec3 vec3;
typedef glm::vec2 vec2;

extern float GRAVITY; //重力值 直接从外部获取 在Main.cpp中定义 或者其他文件中定义
extern float deltaTime; //每一帧的时间 通过渲染主循环两帧的时间差计算 在Main.cpp中 是全局变量

class Particle{
private:
	vec3 position;
	vec3 velocity;
	float gravityEffect;  //正值是向上的
	float staticLifeLength;
	float lifeLength;
	float rotation; //旋转角度 一般是绕z轴旋转的角度
	float scale;
	float distance = 0; //和相机的距离 用于渲染顺序
	float elapsedTime = 0; //已经存活的时间

	bool alive = false; //对象池思想

	ParticleTexture texture; //每一个粒子有对应的纹理
	vec2 texOffset1; //粒子当前的偏移值 两个阶段 类似一个单位格子占据了前后两个格子
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

	//激活粒子 反激活粒子
	void setActive(const vec3& position, const vec3& velocity, float rotation, float scale); //激活新的粒子 只需要改变这些属性 其他的例如重力因子、生命周期长度和纹理等不需改变
	void setActive(const vec3& position, const vec3& velocity, float rotation, float scale
	,float Lifelength); // 生命周期也可以设置
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

