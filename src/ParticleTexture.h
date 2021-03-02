enum Particle_Type{ FIREWORKS, FIRE, SMOKE, SNOW, STAR, COSTMIC, DEFAULT}; //ö������ �������ӵ���������

class ParticleTexture{
private:
	unsigned int textureID;
	unsigned int numberOfRows;
	Particle_Type type;
	bool isAdditive; //�Ƿ�ʹ��additive���
	/*����Ϊ��Ԫ ��ô�Ϳ���������������������ڵķǹ��г�Ա 
	friend bool operator<(const ParticleTexture &lhs, const ParticleTexture &rhs)
	{
		return lhs.textureID < rhs.textureID;
	}*/

public:
	ParticleTexture() :textureID(0), numberOfRows(0){} //Ĭ�Ϲ��캯��
	ParticleTexture(int textureID, int numberOfRows, Particle_Type type, bool isAdditive) 
		:textureID(textureID), numberOfRows(numberOfRows), type(type), isAdditive(isAdditive){}
	int getTextureID() const
	{
		return textureID;
	}
	int getNumberOfRows() const
	{
		return numberOfRows;
	}
	Particle_Type getParticleType() const
	{
		return type;
	}
	bool getIsAdditve() const
	{
		return isAdditive;	
	}
	
};