#ifndef PARTICLE_MASTER_H
#define PARTICLE_MASTER_H

#include "Particle.h"
#include <vector>
//#include <list>

class ParticleMaster{
public:
	//list<Particle> particles; 
	std::vector<Particle> particles;
	void update(const Camera& camera); //�����б��е���������״̬
	void addParticle(const Particle& particle); //�����µ����� ��ӵ��б���
};

#endif