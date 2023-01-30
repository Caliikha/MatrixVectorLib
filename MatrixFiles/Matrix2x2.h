// header file for Matrix2x2 object
// check Matrix2x2.cpp for implmenetations
#pragma once
#include <iostream>

class Vector2;

class Matrix2x2 {
private:
	static constexpr const int Rows = 2;
	static constexpr const int Cols = 2;
public:
	float matrix[Rows][Cols];

    Matrix2x2(
            const float& a0 = 0, const float& a1 = 0,
            const float& a2 = 0, const float& a3 = 0
            );

    static Matrix2x2 identity();
	void printmtrx() const;
    template <typename TYPE>
        static void showResult(const TYPE& input) { std::cout << input << '\n'; }
	static void showResult(const Matrix2x2& inputmtrx);
	static void input(Matrix2x2& inputmtrx);
	float determinant() const noexcept;
	Matrix2x2 inverse() const noexcept;
    Matrix2x2 transpose() const noexcept;
    float trace() const noexcept;
	Matrix2x2 scale(const float& scale) const noexcept;
	Matrix2x2 multiply(const Matrix2x2& inputmtrx) const noexcept;
	Matrix2x2 divide(const Matrix2x2& inputmtrx) const noexcept;
	Matrix2x2 add(const Matrix2x2& inputmtrx) const noexcept;
	Matrix2x2 subtract(const Matrix2x2& inputmtrx) const noexcept;
    Matrix2x2 operator*(const Matrix2x2& right) const noexcept;
    Matrix2x2& operator*=(const Matrix2x2& right) noexcept;
    Matrix2x2 operator/(const Matrix2x2& right) const noexcept;
    Matrix2x2& operator/=(const Matrix2x2& right) noexcept;
    Matrix2x2 operator+(const Matrix2x2& right) const noexcept;
    Matrix2x2& operator+=(const Matrix2x2& right) noexcept;
    Matrix2x2 operator-(const Matrix2x2& right) const noexcept;
    Matrix2x2& operator-=(const Matrix2x2& right) noexcept;
    const float* operator[](const int& index) const;
};
