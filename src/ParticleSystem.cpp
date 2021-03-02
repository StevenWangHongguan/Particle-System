#include "ParticleSystem.h"
#include "ParticleEmit.h"

void ParticleSystem::emitParticles(const vec3& systemCenter)
{
	//��������б�Ϊ�� �ͳ�ʼ������б� �����п��ܶ�����Ӷ��Ž�ȥ ��Ĭ������Ϊ������״̬
	if (master.particles.size() == 0)
	{
		initParticleList();
	}

	float particlesToCreate = pps * deltaTime; //ÿ֡��Ⱦ(���ɣ���������
	int count = (int)floor(particlesToCreate); // ����ȡ��
	float partialParticle = particlesToCreate - count; //С������
	if (randomFloat() < partialParticle) count++; //����ÿ֡��Ⱦ��������

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
	if (master.particles.size() == 0) return; //���Ŀǰ�����б�Ϊ�� ���ܸ��²���Ⱦ ����������ӵ�pps<=2 һ��ʼ����list�����û������ ��ʱ��Ⱦ�ͻ�ը��
	master.update(camera); //�ȸ����б��е����� ����Ⱦ
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
	int count = pps * lifeLength; //����ͬ������������� ��Ϊÿ����Ⱦpps������ �������ܳ���LifeTime����
	for (int i = 0; i < count; i++)
	{
		//��ʼ��Ҫ�趨�������ӡ��������ں����� ����ں���������ӵ�ʱ���ǲ����
		Particle newParticle(vec3(0.0), vec3(0.0), gravityComplient, lifeLength, 0, 0, texture);
		master.addParticle(newParticle);
	}
}

void ParticleSystem::emitFireworksParticles(int count, vec3 systemCenter)
{
	// ���Բ��� ������
	ParticleInfo particleInfo;
	for (auto& particle : master.particles) //���������б� �Ѳ���������Ӽ��� ��������Ӧ������ֵ
	{
		if (count == 0) break;
		if (!particle.isAlive()) //�����������ǲ�����״̬ ����Ӧ���ӵķ��䷽���л����������ֵ �������������
		{
			particleInfo = getFireworksParticleInfo(systemCenter, speed); //��ͬ�����в�ͬ�ķ��䷽ʽ ������������ӵķ�ʽ
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
			count--;
		}
	}

	// ��¼�������������� �Ӹ����ӿ�ʼ������
	//static int lastDeadIndex = 0;
	//ParticleInfo particleInfo;
	//for (int i = lastDeadIndex; i < master.particles.size(); i++)
	//{
	//	if (count == 0) break;
	//	auto& partilce = master.particles[lastDeadIndex];
	//	if (!partilce.isAlive())
	//	{
	//		particleInfo = getFireworksParticleInfo(systemCenter, speed); //��ͬ�����в�ͬ�ķ��䷽ʽ ������������ӵķ�ʽ
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
	for (auto& particle : master.particles) //���������б� �Ѳ���������Ӽ��� ��������Ӧ������ֵ
	{
		if (count == 0) break;
		if (!particle.isAlive()) //�����������ǲ�����״̬ ����Ӧ���ӵķ��䷽���л����������ֵ �������������
		{
			particleInfo = getFireParticleInfo(systemCenter, speed, lifeLength); //��ͬ�����в�ͬ�ķ��䷽ʽ ������������ӵķ�ʽ
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale,
				particleInfo.lifeLength); // ��������Ҳ�仯
			count--;
		}
	}
}
void ParticleSystem::emitSmokeParticles(int count, vec3 systemCenter)
{
	ParticleInfo particleInfo;
	for (auto& particle : master.particles) //���������б� �Ѳ���������Ӽ��� ��������Ӧ������ֵ
	{
		if (count == 0) break;
		if (!particle.isAlive()) //�����������ǲ�����״̬ ����Ӧ���ӵķ��䷽���л����������ֵ �������������
		{
			particleInfo = getSmokeParticleInfo(systemCenter, speed); //��ͬ�����в�ͬ�ķ��䷽ʽ ������������ӵķ�ʽ
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
			count--;
		}
	}
}
void ParticleSystem::emitSnowParticles(int count, vec3 systemCenter)
{
	ParticleInfo particleInfo;
	for (auto& particle : master.particles) //���������б� �Ѳ���������Ӽ��� ��������Ӧ������ֵ
	{
		if (count == 0) break;
		if (!particle.isAlive()) //�����������ǲ�����״̬ ����Ӧ���ӵķ��䷽���л����������ֵ �������������
		{
			particleInfo = getSnowParticleInfo(systemCenter, speed); //��ͬ�����в�ͬ�ķ��䷽ʽ ������������ӵķ�ʽ
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
			count--;
		}
	}
}
void ParticleSystem::emitStarParticles(int count, vec3 systemCenter)
{
	ParticleInfo particleInfo;
	for (auto& particle : master.particles) //���������б� �Ѳ���������Ӽ��� ��������Ӧ������ֵ
	{
		if (count == 0) break;
		if (!particle.isAlive()) //�����������ǲ�����״̬ ����Ӧ���ӵķ��䷽���л����������ֵ �������������
		{
			particleInfo = getStarParticleInfo(systemCenter, speed); //��ͬ�����в�ͬ�ķ��䷽ʽ ������������ӵķ�ʽ
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
			count--;
		}
	}
}
void ParticleSystem::emitCosmicParticles(int count, vec3 systemCenter)
{
	ParticleInfo particleInfo;
	for (auto& particle : master.particles) //���������б� �Ѳ���������Ӽ��� ��������Ӧ������ֵ
	{
		if (count == 0) break;
		if (!particle.isAlive()) //�����������ǲ�����״̬ ����Ӧ���ӵķ��䷽���л����������ֵ �������������
		{
			particleInfo = getCosmicParticleInfo(systemCenter, speed); //��ͬ�����в�ͬ�ķ��䷽ʽ ������������ӵķ�ʽ
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
			count--;
		}
	}
}
void ParticleSystem::emitDefaultParticles(int count, vec3 systemCenter)
{
	ParticleInfo particleInfo;
	for (auto& particle : master.particles) //���������б� �Ѳ���������Ӽ��� ��������Ӧ������ֵ
	{
		if (count == 0) break;
		if (!particle.isAlive()) //�����������ǲ�����״̬ ����Ӧ���ӵķ��䷽���л����������ֵ �������������
		{
			particleInfo = getDefaultParticleInfo(systemCenter, speed); //��ͬ�����в�ͬ�ķ��䷽ʽ ������������ӵķ�ʽ
			particle.setActive(particleInfo.position, particleInfo.velocity, particleInfo.rotation, particleInfo.scale);
			count--;
		}
	}
}