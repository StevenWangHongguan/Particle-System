#pragma once

#include <xmmintrin.h>
#include <glm/mat4x4.hpp>

__m128 mulVectorMatrix(__m128 v, __m128 Mrow1, __m128 Mrow2, __m128 Mrow3, __m128 Mrow4);
glm::mat4 mutiMatrixBySimd(const glm::mat4& A, const glm::mat4& B);