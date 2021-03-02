#include "ParticleSystemMaster.h"
#include <stb_image.h>

unsigned int ParticleSystemMaster::loadTexture(char const* path)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	} else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}

vector<ParticleSystem> ParticleSystemMaster::particleSystems;
vector<vec3> ParticleSystemMaster::particleSystemsPositions;

void ParticleSystemMaster::LoadParticlesInfo()
{
	unsigned int textureID_0, textureID_1, textureID_2, textureID_3, textureID_4, textureID_5;
	textureID_0 = loadTexture("./resource/texture/particleAtlas.png");
	ParticleTexture fireWorksTexture(textureID_0, 4, Particle_Type::FIREWORKS, false);
	textureID_1 = loadTexture("./resource/texture/particleFire.png");
	ParticleTexture fireTexture(textureID_1, 8, Particle_Type::FIRE, true);
	textureID_2 = loadTexture("./resource/texture/particleSmoke.png");
	ParticleTexture smokeTexture(textureID_2, 8, Particle_Type::SMOKE, false);
	textureID_3 = loadTexture("./resource/texture/particleSnow.bmp");
	ParticleTexture snowTexture(textureID_3, 1, Particle_Type::SNOW, true);
	textureID_4 = loadTexture("./resource/texture/particleStar.png");
	ParticleTexture starTexture(textureID_4, 1, Particle_Type::STAR, true);
	textureID_5 = loadTexture("./resource/texture/particleCosmic.png");
	ParticleTexture cosmicTexture(textureID_5, 4, Particle_Type::COSTMIC, true);

	ParticleSystem fireWorks(200, 2, -1, 5, fireWorksTexture);
	ParticleSystem fire(150, 3.6, 0.15, 2.2, fireTexture);
	ParticleSystem smoke(30, 0.5, 0, 12, smokeTexture);
	ParticleSystem snow(100, 1, -1, 8, snowTexture);
	ParticleSystem star(10, 4, -3, 8, starTexture);
	ParticleSystem galaxy(200, 3, -2, 4, cosmicTexture);

	/*ParticleSystem fireWorks(3333, 2, -1, 10, fireWorksTexture);
	ParticleSystem fire(3333, 3.6, 0.15, 10, fireTexture);
	ParticleSystem smoke(3333, 0.5, 0, 10, smokeTexture);
	ParticleSystem snow(3333, 1, -1, 10, snowTexture);
	ParticleSystem star(3333, 4, -3, 10, starTexture);
	ParticleSystem galaxy(3333, 3, -2, 10, cosmicTexture);*/

	particleSystems.emplace_back(fireWorks);
	particleSystems.emplace_back(fire);
	particleSystems.emplace_back(smoke);
	particleSystems.emplace_back(snow);
	particleSystems.emplace_back(star);
	particleSystems.emplace_back(galaxy);

	vec3 fireWorksPos = vec3(0.0f, -1.0f, -2.0f);
	vec3 firePos = vec3(-10.0f, -5.0f, 5.0f);
	vec3 smokePos = vec3(-5.0, -1.0, -2.0);
	vec3 snowPos = vec3(15.0f, 10.0f, 5.0f);
	vec3 starPos = vec3(0.0f, 40.0f, -5.0f);
	vec3 galaxyPos = vec3(0.0f, -1.0f, 10.0f);

	particleSystemsPositions.emplace_back(fireWorksPos);
	particleSystemsPositions.emplace_back(firePos);
	particleSystemsPositions.emplace_back(smokePos);
	particleSystemsPositions.emplace_back(snowPos);
	particleSystemsPositions.emplace_back(starPos);
	particleSystemsPositions.emplace_back(galaxyPos);
}

//void ParticleSystemMaster::renderParticleSystem(unsigned int particleSysIndex, const Camera& camera)
//{
//	particleSystems[particleSysIndex].generateParticles(particleSystemsPositions[particleSysIndex]);
//	particleSystems[particleSysIndex].render(camera);
//}

void ParticleSystemMaster::GenerateParticles(unsigned int particleSysIndex, const Camera& camera)
{
	particleSystems[particleSysIndex].emitParticles(particleSystemsPositions[particleSysIndex]);
	particleSystems[particleSysIndex].update(camera);
}