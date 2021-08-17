// header file for Matrix3x3 object
// find implementations in Matrix3x3.cpp
#pragma once
#include <iostream>

class Matrix2x2;

class Matrix3x3 {
private: // Static Matrix dimensions
	const static int Rows = 3;
	const static int Cols = 3;
public: // Matrix 2D array
	float matrix[Rows][Cols] = { };

	// Callable member functions
	Matrix3x3 identity();
	void printmtrx();
	template <typename TYPE>
        static void showResult(TYPE input) { std::cout << input << '\n'; }
	static void showResult(Matrix3x3 inputmtrx);
	static void input(Matrix3x3 inputmtrx);
	float determinant(); 
//	Matrix3x3 inverse(); // TODO:Complete when determinant and inverse function exists 
	Matrix3x3 transpose(); 
	float trace(); 
	Matrix3x3 scale(float scale);
	Matrix3x3 multiply(Matrix3x3 inputmtrx);
//	Matrix3x3 divide(Matrix3x3 inputmtrx); // TODO:Complete when determinant and inverse function exists 
	Matrix3x3 add(Matrix3x3 inputmtrx);
	Matrix3x3 subtract(Matrix3x3 inputmtrx);
	Matrix3x3 operator*(const Matrix3x3& right);
	Matrix3x3& operator*=(const Matrix3x3& right);
	Matrix3x3 operator+(const Matrix3x3& right);
	Matrix3x3& operator+=(const Matrix3x3& right);
	Matrix3x3 operator-(const Matrix3x3& right);
	Matrix3x3& operator-=(const Matrix3x3& right);
};
