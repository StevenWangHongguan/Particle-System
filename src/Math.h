#pragma once
#include <math.h>
#include <stdlib.h>

const float PI = 3.141592653;
const float EXPONENT = 2.718281828;

float randomFloat() // ����0-1�������
{
	return (rand() % 1000 / 1000.0); //���ؾ���Ϊ��λС�� 0-1����
}

float random() // ����[-1, 1]�������
{
	return randomFloat() * 2 - 1.0f;
}