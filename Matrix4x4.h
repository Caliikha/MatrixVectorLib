// header file for Matrix4x4 object
// find implementations in Matrix3x3.cpp file
#pragma once
#include <iostream>

class Matrix3x3;

class Matrix4x4 {
private: // Static Matrix dimensions
	const static int Rows = 4;
	const static int Cols = 4;
public: // Matrix 2D array
	float matrix[Rows][Cols] = { };

	// Callable member functions
	Matrix4x4 identity();
	void printmtrx();
	template <typename TYPE>
        	static void showResult(TYPE input) { std::cout << input << '\n'; }
	static void showResult(Matrix4x4 inputmtrx);
	static void input(Matrix4x4 inputmtrx);
	Matrix3x3 minormtrx(int, int);
	float minor(int, int);
	Matrix3x3 cofactormtrx(int, int);
	float cofactor(int, int);
	float determinant();	
	Matrix4x4 inverse();
//	float determinant(); TODO: Complete when 3x3 determinant exists 
//	Matrix4x4 inverse(); // TODO:Complete when determinant function exists 
	Matrix4x4 transpose();
	float trace();
	Matrix4x4 scale(float scale);
	Matrix4x4 multiply(Matrix4x4 inputmtrx);
//	Matrix4x4 divide(Matrix4x4 inputmtrx); // TODO:Complete when determinant and inverse function exists 
	Matrix4x4 add(Matrix4x4 inputmtrx);
	Matrix4x4 subtract(Matrix4x4 inputmtrx);
	Matrix4x4 operator*(const Matrix4x4& right);
	Matrix4x4& operator*=(const Matrix4x4& right);
	Matrix4x4 operator+(const Matrix4x4& right);
	Matrix4x4& operator+=(const Matrix4x4& right);
	Matrix4x4 operator-(const Matrix4x4& right);
	Matrix4x4& operator-=(const Matrix4x4& right);
};
