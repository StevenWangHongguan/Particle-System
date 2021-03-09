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

typedef glm::mat4 mat4;

extern unsigned int SCR_WIDTH;
extern unsigned int SCR_HEIGHT;

//声明为static 只能在本文件中使用
static const int MAX_INSTANCES = 10000; //每次场景绘制的最大粒子数 十万个 够你用了吧 改为1万个 帧率明显上升
static const int INSTANCE_DATA_LENGTH = 21; //每个实例的属性数据长度
static float *vboData = new float[MAX_INSTANCES * INSTANCE_DATA_LENGTH]; //这里使用静态数组会报错

class ParticleRenderer{
private:
	Quad *quad;
	Shader *particleShader;
	unsigned int VBO;
	unsigned int pointer; //用于指向vboData给每个位置赋值

	unsigned int createEmptyVBO(int floatCount);
	void setUpAttributes(unsigned int VAO, unsigned int VBO);

	void prepare(); //激活着色器中的顶点属性
	void bindTexture(ParticleTexture texture); //激活着色器中的纹理单元 设置1个uniform
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

// 备注 
// 在一个类中定义一个其他自定义类对象的时候 这个类要拥有默认构造函数 否则不能再类内对这个自定义类进行简单的声明
// 比如Shader类 没有默认构造函数 只能在类中定义这个Shader的时候直接创建一个对象
// 其次 的确可以通过*(new xxx)的方式创建一个类对象 而不必须用一个指针
