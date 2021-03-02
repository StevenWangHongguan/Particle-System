enum Particle_Type{ FIREWORKS, FIRE, SMOKE, SNOW, STAR, COSTMIC, DEFAULT}; //枚举类型 定义粒子的纹理类型

class ParticleTexture{
private:
	unsigned int textureID;
	unsigned int numberOfRows;
	Particle_Type type;
	bool isAdditive; //是否使用additive混合
	/*声明为友元 那么就可以允许这个函数访问类内的非公有成员 
	friend bool operator<(const ParticleTexture &lhs, const ParticleTexture &rhs)
	{
		return lhs.textureID < rhs.textureID;
	}*/

public:
	ParticleTexture() :textureID(0), numberOfRows(0){} //默认构造函数
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