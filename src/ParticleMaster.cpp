#include "ParticleMaster.h"
#include <algorithm>

bool cmpDistance(const Particle& p1, const Particle& p2) //���Ӱ�����Զ��˳����Ⱦ 
{
	return p1.getDistance() > p2.getDistance();  //�ǵ�particle�����getDistance����Ҫ����Ϊconst ����ᱨ�� ����ԭ���������p1��const���� ����get����ȴ��non const���� ��һ�µ��µĶ�
}

void ParticleMaster::update(const Camera& camera)
{
	for (auto& particle : particles)
	{
		bool stillAlive = particle.update(camera);
		if (!stillAlive)
		{
			particle.setNotActive();
		}
	}
	if (!particles.front().getTexture().getIsAdditve())
	{
		//particles.sort(cmpDistance);
		std::sort(particles.begin(), particles.end(), cmpDistance);
	}
}

void ParticleMaster::addParticle(const Particle& particle)
{
	particles.emplace_back(particle);
}