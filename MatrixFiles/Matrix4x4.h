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

	Matrix4x4 identity() const;
	void printmtrx() const;
    template <typename TYPE>
        static void showResult(TYPE input) { std::cout << input << '\n'; }
	static void showResult(const Matrix4x4& inputmtrx);
    static void input(Matrix4x4& inputmtrx);
    // TODO add [gh]
    Matrix3x3 minormtrx(const int& row, const int& col) const;
    // TODO add [gh]
    float minor(const int& row, const int& col) const;
    // TODO add [gh]
    Matrix3x3 cofactormtrx(const int& row, const int& col) const;
    // TODO add [gh]
    float cofactor(const int& row, const int& col) const;
    // TODO add [gh]
	float determinant() const; //TODO: Complete when 3x3 determinant exists 
    // TODO add [gh]
	Matrix4x4 inverse() const; // TODO:Complete when determinant function exists 
    Matrix4x4 transpose() const;
    float trace() const;
	Matrix4x4 scale(const float& scale) const;
	Matrix4x4 multiply(const Matrix4x4& inputmtrx) const;
//	Matrix4x4 divide(Matrix4x4 inputmtrx); // TODO:Complete when determinant and inverse function exists 
	Matrix4x4 add(const Matrix4x4& inputmtrx) const;
	Matrix4x4 subtract(const Matrix4x4& inputmtrx) const;
    Matrix4x4 operator*(const Matrix4x4& right) const;
    Matrix4x4& operator*=(const Matrix4x4& right);
    Matrix4x4 operator+(const Matrix4x4& right) const;
    Matrix4x4& operator+=(const Matrix4x4& right);
    Matrix4x4 operator-(const Matrix4x4& right) const;
    Matrix4x4& operator-=(const Matrix4x4& right);
    const float* operator[](const int& index) const;
};
