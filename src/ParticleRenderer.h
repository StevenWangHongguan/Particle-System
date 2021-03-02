#ifndef PARTICLE_RENDERER_H
#define PARTICLE_RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/shader.h>
#include <learnopengl/camera.h>

#include "Particle.h"
#include "Quad.h"
using namespace std;

typedef glm::mat4 mat4;

extern unsigned int SCR_WIDTH;
extern unsigned int SCR_HEIGHT;

//����Ϊstatic ֻ���ڱ��ļ���ʹ��
static const int MAX_INSTANCES = 10000; //ÿ�γ������Ƶ���������� ʮ��� �������˰� ��Ϊ1��� ֡����������
static const int INSTANCE_DATA_LENGTH = 21; //ÿ��ʵ�����������ݳ���
static float *vboData = new float[MAX_INSTANCES * INSTANCE_DATA_LENGTH]; //����ʹ�þ�̬����ᱨ��

class ParticleRenderer{
private:
	Quad *quad;
	Shader *particleShader;
	unsigned int VBO;
	unsigned int pointer; //����ָ��vboData��ÿ��λ�ø�ֵ

	unsigned int createEmptyVBO(int floatCount);
	void setUpAttributes(unsigned int VAO, unsigned int VBO);

	void prepare(); //������ɫ���еĶ�������
	void bindTexture(ParticleTexture texture); //������ɫ���е�����Ԫ ����1��uniform
	void updateModelViewMatrix(const vec3& position, float rotation, float scale, mat4 view, float vboData[]);
	void storeMatrixData(const mat4& matrix, float data[]);
	void updateTexCoordsInfo(const Particle& particle, float data[]);
	void updateVBOdata(unsigned int VBO, float data[]);
	void finishRendering();

public:
	ParticleRenderer();
	void setProjection(const mat4& projection);
	void render(const vector<Particle>& particles, Camera camera); // list to vector
};

#endif

// ��ע 
// ��һ�����ж���һ�������Զ���������ʱ�� �����Ҫӵ��Ĭ�Ϲ��캯�� �����������ڶ�����Զ�������м򵥵�����
// ����Shader�� û��Ĭ�Ϲ��캯�� ֻ�������ж������Shader��ʱ��ֱ�Ӵ���һ������
// ��� ��ȷ����ͨ��*(new xxx)�ķ�ʽ����һ������� ����������һ��ָ��
