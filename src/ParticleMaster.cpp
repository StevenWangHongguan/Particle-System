#include "ParticleMaster.h"
#include <algorithm>

bool cmpDistance(const Particle& p1, const Particle& p2) //粒子按距离远近顺序渲染 
{
	return p1.getDistance() > p2.getDistance();  //记得particle里面的getDistance方法要声明为const 否则会报错 报错原因是这里的p1是const对象 但是get方法却是non const方法 不一致导致的额
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