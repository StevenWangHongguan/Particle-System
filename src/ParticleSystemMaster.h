#ifndef PARTICLE_SYSTEM_MASTER_H
#define PARTICLE_SYSTEM_MASTER_H

#include "ParticleSystem.h"
#include "ThreadPool.hpp"
#include <vector>

class ParticleSystemMaster{
private:
	static unsigned int loadTexture(const char* path);
	
public:
	static vector<ParticleSystem> particleSystems;
	static vector<vec3> particleSystemsPositions;
	//static void renderParticleSystem(unsigned int particleSysIndex, const Camera& camera);
	static void GenerateParticles(unsigned int particleSysIndex, const Camera& camera);
	static void LoadParticlesInfo();
};

#endif