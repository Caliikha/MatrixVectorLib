// header file for Matrix2x2 object
// check Matrix2x2.cpp for implmenetations
#pragma once
#include <iostream>

class Matrix2x2 {
private: // Static Matrix dimensions
	static const int Rows = 2;
	static const int Cols = 2;
public: // Matrix 2D array
	float matrix[Rows][Cols] = { };

	// Callable member functions
	Matrix2x2 identity();
	void printmtrx();
	template <typename TYPE>
	static void showResult(TYPE input) { std::cout << input << '\n'; }
	static void showResult(Matrix2x2 inputmtrx);
	static void input(Matrix2x2 inputmtrx);
	float determinant();
	Matrix2x2 inverse();
	Matrix2x2 transpose();
	float trace();
	Matrix2x2 scale(float scale);
	Matrix2x2 multiply(Matrix2x2 inputmtrx);
	Matrix2x2 divide(Matrix2x2 inputmtrx);
	Matrix2x2 add(Matrix2x2 inputmtrx);
	Matrix2x2 subtract(Matrix2x2 inputmtrx);
	Matrix2x2 operator*(const Matrix2x2& right);
	Matrix2x2& operator*=(const Matrix2x2& right);
	Matrix2x2 operator/(const Matrix2x2& right);
	Matrix2x2& operator/=(const Matrix2x2& right);
	Matrix2x2 operator+(const Matrix2x2& right);
	Matrix2x2& operator+=(const Matrix2x2& right);
	Matrix2x2 operator-(const Matrix2x2& right);
	Matrix2x2& operator-=(const Matrix2x2& right);
};
