#pragma once
#include <math.h>
#include <stdlib.h>

const float PI = 3.141592653;
const float EXPONENT = 2.718281828;

float randomFloat() // 返回0-1的随机数
{
	return (rand() % 1000 / 1000.0); //返回精度为三位小数 0-1的数
}

float random() // 返回[-1, 1]的随机数
{
	return randomFloat() * 2 - 1.0f;
}