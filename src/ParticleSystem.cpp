#include "ParticleSystem.h"
#include "ParticleEmit.h"

void ParticleSystem::emitParticles(const vec3& systemCenter)
{
	//如果粒子列表为空 就初始化这个列表 把所有可能多的粒子都放进去 并默认设置为不激活状态
	if (master.particles.size() == 0)
	{
		initParticleList();
	}

	float particlesToCreate = pps * deltaTime; //每帧渲染(生成）的粒子数
	int count = (int)floor(particlesToCreate); // 向下取整
	float partialParticle = particlesToCreate - count; //小数部分
	if (randomFloat() < partialParticle) count++; //修正每帧渲染的粒子数

	Particle_Type type = texture.getParticleType();
	switch (type)
	{
		case FIREWORKS:
			emitFireworksParticles(count, systemCenter);
			break;
		case FIRE:
			emitFireParticles(count, systemCenter);
			break;
		case SMOKE:
			emitSmokeParticles(count, systemCenter);
			break;
		case SNOW:
			emitSnowParticles(count, systemCenter);
			break;
		case STAR:
			emitStarParticles(count, systemCenter);
			break;
		case COSTMIC:
			emitCosmicParticles(count, systemCenter);
			break;
		default:
			emitDefaultParticles(count, systemCenter);
			break;
	}
}

void ParticleSystem::setProjection(const mat4& projection)
{
	renderer.setProjection(projection);
}

void ParticleSystem::update(const Camera& camera)
{
	if (master.particles.size() == 0) return; //如果目前粒子列表为空 不能更新并渲染 否则如果粒子的pps<=2 一开始可能list里面就没有粒子 此时渲染就会炸了
	master.update(camera); //先更新列表中的粒子 再渲染
}

void ParticleSystem::render(const Camera& camera)
{
	renderer.render(master.particles, camera);
}

void ParticleSystem::Start(const vec3& systemCenter, const Camera& camera)
{
	emitParticles(systemCenter);
	update(camera);
	render(camera);
}

void ParticleSystem::initParticleList()
{
	int count = pps * lifeLength; //当下同屏的最大粒子数 因为每秒渲染pps个粒子 而粒子能持续LifeTime长度
	for (int i = 0; i < count; i++)
	{
		//初始化要设定重力因子、生命周期和纹理 这点在后面更新粒子的时候是不变的
		Particle newParticle(vec3(0.0), vec3(0.0), gravityComplient, lifeLength, 0, 0, texture);
		master.addParticle(newParticle);
	}
}

void ParticleSystem::emitFireworksParticles(int count, vec3 systemCenter)
{
	// 线性查找 暴力法
	ParticleInfo particleInfo;
	for (auto& particle : master.particles) //遍历粒子列表 把不激活的粒子激活 并设置相应的属性值
	{
		if (count == 0) break;
		if (!particle.isAlive()) //如果这个粒子是不激活状态 从相应粒子的发射方法中获得粒子属性值 并激活这个粒子
		{
			particleInfo = getFireworksParticleInfo(systemCenter, speed); //不同粒子有不同的发射方式 即随机产生粒子的方式
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
			count--;
		}
	}

	// 记录最先死亡的粒子 从该粒子开始查找起
	//static int lastDeadIndex = 0;
	//ParticleInfo particleInfo;
	//for (int i = lastDeadIndex; i < master.particles.size(); i++)
	//{
	//	if (count == 0) break;
	//	auto& partilce = master.particles[lastDeadIndex];
	//	if (!partilce.isAlive())
	//	{
	//		particleInfo = getFireworksParticleInfo(systemCenter, speed); //不同粒子有不同的发射方式 即随机产生粒子的方式
	//		partilce.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
	//		lastDeadIndex = i;
	//		count--;
	//	}
	//	if (lastDeadIndex == master.particles.size())
	//		lastDeadIndex = 0;
	//}
}
void ParticleSystem::emitFireParticles(int count, vec3 systemCenter)
{
	ParticleInfo particleInfo;
	float lifeLength = master.particles.front().getStaticLifeLength();
	for (auto& particle : master.particles) //遍历粒子列表 把不激活的粒子激活 并设置相应的属性值
	{
		if (count == 0) break;
		if (!particle.isAlive()) //如果这个粒子是不激活状态 从相应粒子的发射方法中获得粒子属性值 并激活这个粒子
		{
			particleInfo = getFireParticleInfo(systemCenter, speed, lifeLength); //不同粒子有不同的发射方式 即随机产生粒子的方式
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale,
				particleInfo.lifeLength); // 生命周期也变化
			count--;
		}
	}
}
void ParticleSystem::emitSmokeParticles(int count, vec3 systemCenter)
{
	ParticleInfo particleInfo;
	for (auto& particle : master.particles) //遍历粒子列表 把不激活的粒子激活 并设置相应的属性值
	{
		if (count == 0) break;
		if (!particle.isAlive()) //如果这个粒子是不激活状态 从相应粒子的发射方法中获得粒子属性值 并激活这个粒子
		{
			particleInfo = getSmokeParticleInfo(systemCenter, speed); //不同粒子有不同的发射方式 即随机产生粒子的方式
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
			count--;
		}
	}
}
void ParticleSystem::emitSnowParticles(int count, vec3 systemCenter)
{
	ParticleInfo particleInfo;
	for (auto& particle : master.particles) //遍历粒子列表 把不激活的粒子激活 并设置相应的属性值
	{
		if (count == 0) break;
		if (!particle.isAlive()) //如果这个粒子是不激活状态 从相应粒子的发射方法中获得粒子属性值 并激活这个粒子
		{
			particleInfo = getSnowParticleInfo(systemCenter, speed); //不同粒子有不同的发射方式 即随机产生粒子的方式
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
			count--;
		}
	}
}
void ParticleSystem::emitStarParticles(int count, vec3 systemCenter)
{
	ParticleInfo particleInfo;
	for (auto& particle : master.particles) //遍历粒子列表 把不激活的粒子激活 并设置相应的属性值
	{
		if (count == 0) break;
		if (!particle.isAlive()) //如果这个粒子是不激活状态 从相应粒子的发射方法中获得粒子属性值 并激活这个粒子
		{
			particleInfo = getStarParticleInfo(systemCenter, speed); //不同粒子有不同的发射方式 即随机产生粒子的方式
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
			count--;
		}
	}
}
void ParticleSystem::emitCosmicParticles(int count, vec3 systemCenter)
{
	ParticleInfo particleInfo;
	for (auto& particle : master.particles) //遍历粒子列表 把不激活的粒子激活 并设置相应的属性值
	{
		if (count == 0) break;
		if (!particle.isAlive()) //如果这个粒子是不激活状态 从相应粒子的发射方法中获得粒子属性值 并激活这个粒子
		{
			particleInfo = getCosmicParticleInfo(systemCenter, speed); //不同粒子有不同的发射方式 即随机产生粒子的方式
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
			count--;
		}
	}
}
void ParticleSystem::emitDefaultParticles(int count, vec3 systemCenter)
{
	ParticleInfo particleInfo;
	for (auto& particle : master.particles) //遍历粒子列表 把不激活的粒子激活 并设置相应的属性值
	{
		if (count == 0) break;
		if (!particle.isAlive()) //如果这个粒子是不激活状态 从相应粒子的发射方法中获得粒子属性值 并激活这个粒子
		{
			particleInfo = getDefaultParticleInfo(systemCenter, speed); //不同粒子有不同的发射方式 即随机产生粒子的方式
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
			count--;
		}
	}
}