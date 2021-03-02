#ifndef PARTILCE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "ParticleMaster.h"
#include "ParticleRenderer.h"

class ParticleSystem{
private:
	float pps; // particles per second
	float speed;
	float gravityComplient; // 重力因子
	float lifeLength;

	ParticleTexture texture;

	ParticleMaster master; //每个粒子系统有一个自己的master
	ParticleRenderer renderer; //每个粒子系统有一个自己的renderer

	void initParticleList();
	void emitFireworksParticles(int count, vec3 systemCenter);
	void emitFireParticles(int count, vec3 systemCenter);
	void emitSmokeParticles(int count, vec3 systemCenter);
	void emitSnowParticles(int count, vec3 systemCenter);
	void emitStarParticles(int count, vec3 systemCenter);
	void emitCosmicParticles(int count, vec3 systemCenter);
	void emitDefaultParticles(int count, vec3 systemCenter);

public:
	//master和renderer自动调用默认的构造函数
	ParticleSystem(float pps, float speed, float gravityComplient, float lifeLength, ParticleTexture texture) :
		pps(pps), speed(speed), gravityComplient(gravityComplient), lifeLength(lifeLength), texture(texture){}
	//以下函数为外部调用接口  后续可以封装为一个接口 particleSystem.start(sysPos,projection,camera)
	//projection的设置也可以优化 设定一个默认值 在renderer构造的时候 传递这个projection
	void emitParticles(const vec3& systemCenter);  //主循环中 每帧调用
	void setProjection(const mat4& projection);
	void update(const Camera& camera);
	void render(const Camera& camera);

	void Start(const vec3& systemCenter, const Camera& camera);
};

#endif