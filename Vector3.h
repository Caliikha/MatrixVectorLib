// header file for Vector3 object
// find implementation in Vector3.cpp file
#pragma once
#include <iostream>

class Matrix3x3;

class Vector3 {
public:
	float x = 0, y = 0, z = 0; // Cartesian components
    
	// Assignment constructors
	Vector3() = default;
	Vector3(const float a, const float b, const float c) : x(a), y(b), z(c) {};
	Vector3(const float a, const float b) : x(a), y(b) {};
	Vector3(const float a) : x(a) {};
	Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z) {};
	
	// Callable member functions
	static void input(Vector3 &inputvctr); 
	void printvector();
	template <typename TYPE>
		static void showResult(TYPE input) { std::cout << input << '\n'; }
	static void showResult(Vector3 inputvctr);
	float dotproduct(Vector3 inputvctr);
	float magnitude();
	float angle(Vector3 inputvctr);
	Vector3 unitvector(); 
	Vector3 resultant(Vector3 inputvctr);
	Vector3 add(Vector3 inputvctr); 
	Vector3 subtract(Vector3 inputvctr); 
	Vector3 scale(float scale);
	Vector3 scale(Matrix3x3 inputmtrx);
//	Vector3 rotate(Matrix3x3 inputmtrx); // TODO: will complete when Quaternion based rotation is implemented
	Vector3 translate(Matrix3x3 inputmtrx);
	Vector3 crossproduct(Vector3 inputvctr); 
	Vector3 operator*(const Matrix3x3& right);
	Vector3 operator*(const Vector3& right);
	Vector3& operator*=(const Vector3& right);
	Vector3 operator+(const Vector3& right);
	Vector3& operator+=(const Vector3& right);
	Vector3 operator-(const Vector3& right);
	Vector3& operator-=(const Vector3& right);
};
