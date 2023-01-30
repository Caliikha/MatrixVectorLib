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

	static Matrix3x3 identity();
	void printmtrx() const;
    template <typename TYPE>
        static void showResult(const TYPE& input) { std::cout << input << '\n'; }
	static void showResult(const Matrix3x3& inputmtrx);
	static void input(Matrix3x3& inputmtrx);
    Matrix2x2 minormtrx(const int& row, const int& col) const noexcept;
    float minor(const int& row, const int& col) const noexcept;
    Matrix2x2 cofactormtrx(const int& row, const int& col) const noexcept;
    float cofactor(const int& row, const int& col) const noexcept;
	float determinant() const noexcept;
	Matrix3x3 inverse() const noexcept; // TODO:Complete when determinant and inverse function exists 
	Matrix3x3 transpose() const noexcept;
	float trace() const noexcept;
	Matrix3x3 scale(const float& scale) const noexcept;
	Matrix3x3 multiply(const Matrix3x3& inputmtrx) const noexcept;
//	Matrix3x3 divide(Matrix3x3 inputmtrx); // TODO:Complete when determinant and inverse function exists 
	Matrix3x3 add(const Matrix3x3& inputmtrx) const noexcept;
	Matrix3x3 subtract(const Matrix3x3& inputmtrx) const noexcept;
    Matrix3x3 operator*(const Matrix3x3& right) const noexcept;
    Matrix3x3& operator*=(const Matrix3x3& right) noexcept;
    Matrix3x3 operator+(const Matrix3x3& right) const noexcept;
    Matrix3x3& operator+=(const Matrix3x3& right) noexcept;
    Matrix3x3 operator-(const Matrix3x3& right) const noexcept;
    Matrix3x3& operator-=(const Matrix3x3& right) noexcept;
    const float* operator[](const int& index) const;
};
