#include "Simd.h"

#define SHUFFLE_PARAM(x, y, z, w) \
  ((x) | ((y) << 2) | ((z) << 4) | ((w) << 6))

#define _mm_replicate_x_ps(v) \
  _mm_shuffle_ps((v), (v), SHUFFLE_PARAM(0, 0, 0, 0))

#define _mm_replicate_y_ps(v) \
  _mm_shuffle_ps((v), (v), SHUFFLE_PARAM(1, 1, 1, 1))

#define _mm_replicate_z_ps(v) \
  _mm_shuffle_ps((v), (v), SHUFFLE_PARAM(2, 2, 2, 2))

#define _mm_replicate_w_ps(v) \
  _mm_shuffle_ps((v), (v), SHUFFLE_PARAM(3, 3, 3, 3))

#define _mm_madd_ps(a, b, c) \
  _mm_add_ps(_mm_mul_ps((a), (b)), (c))

__m128 mulVectorMatrix(__m128 v, __m128 Mrow1, __m128 Mrow2, __m128 Mrow3, __m128 Mrow4)
{
	__m128 result;
	result = _mm_mul_ps(_mm_replicate_x_ps(v), Mrow1);
	result = _mm_madd_ps(_mm_replicate_y_ps(v), Mrow2, result);
	result = _mm_madd_ps(_mm_replicate_z_ps(v), Mrow3, result);
	result = _mm_madd_ps(_mm_replicate_w_ps(v), Mrow4, result);

	return result;
}

glm::mat4 mutiMatrixBySimd(const glm::mat4& A, const glm::mat4& B)
{
	__declspec(align(16)) float Arow1[] = {A[0][0], A[1][0], A[2][0], A[3][0]};
	__declspec(align(16)) float Arow2[] = {A[0][1], A[1][1], A[2][1], A[3][1]};
	__declspec(align(16)) float Arow3[] = {A[0][2], A[1][2], A[2][2], A[3][2]};
	__declspec(align(16)) float Arow4[] = {A[0][3], A[1][3], A[2][3], A[3][3]};

	__declspec(align(16)) float Brow1[] = {B[0][0], B[1][0], B[2][0], B[3][0]};
	__declspec(align(16)) float Brow2[] = {B[0][1], B[1][1], B[2][1], B[3][1]};
	__declspec(align(16)) float Brow3[] = {B[0][2], B[1][2], B[2][2], B[3][2]};
	__declspec(align(16)) float Brow4[] = {B[0][3], B[1][3], B[2][3], B[3][3]};

	__declspec(align(16)) float resRow1[] = {0.0f, 0.0f, 0.0f, 0.0f};
	__declspec(align(16)) float resRow2[] = {0.0f, 0.0f, 0.0f, 0.0f};
	__declspec(align(16)) float resRow3[] = {0.0f, 0.0f, 0.0f, 0.0f};
	__declspec(align(16)) float resRow4[] = {0.0f, 0.0f, 0.0f, 0.0f};

	__m128 arow1 = _mm_load_ps(&Arow1[0]);
	__m128 arow2 = _mm_load_ps(&Arow2[0]);
	__m128 arow3 = _mm_load_ps(&Arow3[0]);
	__m128 arow4 = _mm_load_ps(&Arow4[0]);

	__m128 brow1 = _mm_load_ps(&Brow1[0]);
	__m128 brow2 = _mm_load_ps(&Brow2[0]);
	__m128 brow3 = _mm_load_ps(&Brow3[0]);
	__m128 brow4 = _mm_load_ps(&Brow4[0]);

	__m128 resrow1 = mulVectorMatrix(arow1, brow1, brow2, brow3, brow4);
	__m128 resrow2 = mulVectorMatrix(arow2, brow1, brow2, brow3, brow4);
	__m128 resrow3 = mulVectorMatrix(arow3, brow1, brow2, brow3, brow4);
	__m128 resrow4 = mulVectorMatrix(arow4, brow1, brow2, brow3, brow4);

	_mm_store_ps(&Arow1[0], arow1);
	_mm_store_ps(&Arow2[0], arow2);
	_mm_store_ps(&Arow3[0], arow3);
	_mm_store_ps(&Arow4[0], arow4);

	_mm_store_ps(&Brow1[0], brow1);
	_mm_store_ps(&Brow2[0], brow2);
	_mm_store_ps(&Brow3[0], brow3);
	_mm_store_ps(&Brow4[0], brow4);

	_mm_store_ps(&resRow1[0], resrow1);
	_mm_store_ps(&resRow2[0], resrow2);
	_mm_store_ps(&resRow3[0], resrow3);
	_mm_store_ps(&resRow4[0], resrow4);

	glm::mat4 result;
	
	result[0] = {resRow1[0], resRow2[0], resRow3[0], resRow4[0]};
	result[1] = {resRow1[1], resRow2[1], resRow3[1], resRow4[1]};
	result[2] = {resRow1[2], resRow2[2], resRow3[2], resRow4[2]};
	result[3] = {resRow1[3], resRow2[3], resRow3[3], resRow4[3]};

	return result;
}