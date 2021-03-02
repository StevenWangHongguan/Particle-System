//����VAO VBO���� ���ݶ�������vertices �洢VAO��ID 
#ifndef QUAD_H
#define QUAD_H

#include <glad/glad.h>

class Quad{
private:
	static float vertices[8];//Ӳ����
	unsigned int vertexCount;
	unsigned int quadVAO;
	unsigned int quadVBO;
	void loadToVAO(); //����VAO
public:
	Quad()
	{	
		//����vertices��Ӳ���� ���Խ��Ҫ��ֻ�ø��������ľ������ݾ�����
		vertexCount = sizeof(vertices)/sizeof(float); 
		loadToVAO();
	}
	unsigned int getVertexCount(){ return vertexCount;}
	unsigned int getQuadVAO(){ return quadVAO; }
};

#endif // !QUAD_H
