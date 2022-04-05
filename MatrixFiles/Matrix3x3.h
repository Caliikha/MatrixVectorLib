// header file for Matrix3x3 object
// find implementations in Matrix3x3.cpp
#pragma once
#include <iostream>

class Matrix2x2;
class Vector3;

class Matrix3x3 {
private:
	static constexpr const int Rows = 3;
	static constexpr const int Cols = 3;
public:
	float matrix[Rows][Cols];

    Matrix3x3(
            const float& a0 = 0, const float& a1 = 0, const float& a2 = 0,
            const float& a3 = 0, const float& a4 = 0, const float& a5 = 0,
            const float& a6 = 0, const float& a7 = 0, const float& a8 = 0
            );

	inline static Matrix3x3 identity();
	void printmtrx() const;
    template <typename TYPE>
        static void showResult(const TYPE& input) { std::cout << input << '\n'; }
	static void showResult(const Matrix3x3& inputmtrx);
	static void input(Matrix3x3& inputmtrx);
    inline Matrix2x2 minormtrx(const int& row, const int& col) const noexcept;
    inline float minor(const int& row, const int& col) const noexcept;
    inline Matrix2x2 cofactormtrx(const int& row, const int& col) const noexcept;
    inline float cofactor(const int& row, const int& col) const noexcept;
	inline float determinant() const noexcept;
	inline Matrix3x3 inverse() const noexcept; // TODO:Complete when determinant and inverse function exists 
	inline Matrix3x3 transpose() const noexcept;
	inline float trace() const noexcept;
	inline Matrix3x3 scale(const float& scale) const noexcept;
	inline Matrix3x3 multiply(const Matrix3x3& inputmtrx) const noexcept;
//	inline Matrix3x3 divide(Matrix3x3 inputmtrx); // TODO:Complete when determinant and inverse function exists 
	inline Matrix3x3 add(const Matrix3x3& inputmtrx) const noexcept;
	inline Matrix3x3 subtract(const Matrix3x3& inputmtrx) const noexcept;
    inline Matrix3x3 operator*(const Matrix3x3& right) const noexcept;
    inline Matrix3x3& operator*=(const Matrix3x3& right) noexcept;
    inline Matrix3x3 operator+(const Matrix3x3& right) const noexcept;
    inline Matrix3x3& operator+=(const Matrix3x3& right) noexcept;
    inline Matrix3x3 operator-(const Matrix3x3& right) const noexcept;
    inline Matrix3x3& operator-=(const Matrix3x3& right) noexcept;
    inline const float* operator[](const int& index) const;
};
