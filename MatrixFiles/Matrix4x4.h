// header file for Matrix4x4 object
// find implementations in Matrix3x3.cpp file
#pragma once
#include <iostream>

class Matrix3x3;

class Matrix4x4 {
private:
	static constexpr const int Rows = 4;
	static constexpr const int Cols = 4;
public:
	float matrix[Rows][Cols];

    Matrix4x4(
            const float& a0 = 0, const float& a1 = 0, const float& a2 = 0, const float& a3 = 0,
            const float& a4 = 0, const float& a5 = 0, const float& a6 = 0, const float& a7 = 0,
            const float& a8 = 0, const float& a9 = 0, const float& a10 = 0, const float& a11 = 0,
            const float& a12 = 0, const float& a13 = 0, const float& a14 = 0, const float& a15 = 0
            );

	static Matrix4x4 identity();
	void printmtrx() const;
    template <typename TYPE>
        static void showResult(TYPE input) { std::cout << input << '\n'; }
	static void showResult(const Matrix4x4& inputmtrx);
    static void input(Matrix4x4& inputmtrx);
    Matrix3x3 minormtrx(const int& row, const int& col) const noexcept;
    float minor(const int& row, const int& col) const noexcept;
    Matrix3x3 cofactormtrx(const int& row, const int& col) const noexcept;
    float cofactor(const int& row, const int& col) const noexcept;
	float determinant() const noexcept;
	Matrix4x4 inverse() const noexcept;
    Matrix4x4 transpose() const noexcept;
    float trace() const noexcept;
	Matrix4x4 scale(const float& scale) const noexcept;
	Matrix4x4 multiply(const Matrix4x4& inputmtrx) const noexcept;
//	Matrix4x4 divide(Matrix4x4 inputmtrx); // TODO:Complete when determinant and inverse function exists 
	Matrix4x4 add(const Matrix4x4& inputmtrx) const noexcept;
	Matrix4x4 subtract(const Matrix4x4& inputmtrx) const noexcept;
    Matrix4x4 operator*(const Matrix4x4& right) const noexcept;
    Matrix4x4& operator*=(const Matrix4x4& right) noexcept;
    Matrix4x4 operator+(const Matrix4x4& right) const noexcept;
    Matrix4x4& operator+=(const Matrix4x4& right) noexcept;
    Matrix4x4 operator-(const Matrix4x4& right) const noexcept;
    Matrix4x4& operator-=(const Matrix4x4& right) noexcept;
    const float* operator[](const int& index) const;
};
