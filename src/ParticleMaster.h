#ifndef PARTICLE_MASTER_H
#define PARTICLE_MASTER_H

#include "Particle.h"
#include <vector>
//#include <list>

class ParticleMaster{
public:
	//list<Particle> particles; 
	std::vector<Particle> particles;
	void update(const Camera& camera); //更新列表中的所有粒子状态
	void addParticle(const Particle& particle); //增加新的粒子 添加到列表中
};

#endif