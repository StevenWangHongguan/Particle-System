# Particle Special Effect System
This is a particle special effects system based on OpenGL.

这是一个基于OpenGL实现的粒子特效系统。

## 项目结构
- **src**： 源文件
- **include**： 头文件
- **lib**： 相关库
- **resource**： 相关资源，包括纹理、天空盒
- **shader**： 着色器文件

## 配置方法
- 运行平台：windows10+visual studio 2019
- 步骤一：打开vs2019->点击项目右键属性->VC++目录->设置包含目录为上述的include文件夹路径->设置库目录为上述lib下的lib-vc2019路径
- 步骤二：同样进入到项目属性中的链接器一栏->附加依赖项->加入opengl32.lib和glfw3.lib->记得编译环境是Debug/Realse x86
- 然后编译运行就可以跑了。
