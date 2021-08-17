// Header file for Vector4 object type
// Check Vector4.cpp for implementation of functions
#pragma once
#include <iostream>
#include <cmath>

class Vector3;
class Matrix3x3;
class Matrix4x4;

class Vector4 {
public:
	float x = 0, y = 0, z = 0, w = 0; // Cartesian components

	// Assignment constructors
	Vector4() = default;
	Vector4(const float a, const float b, const float c, const float d) : x(a), y(b), z(c), w(d) {};
	Vector4(const float a, const float b, const float c) : x(a), y(b), z(c) {};
	Vector4(const float a, const float b) : x(a), y(b) {};
	Vector4(const float a) : x(a) {};
	Vector4(const Vector4& other) : Vector4(other.x, other.y, other.z, other.w) {};
	
	// Callable member functions
	static void input(Vector4 &inputvctr); 
	void printvector();
	template <typename TYPE>
	static void showResult(TYPE input) { std::cout << input << '\n'; }
	static void showResult(Vector4 inputvctr);
	float dotproduct(Vector4 inputvctr);
	float magnitude();
	float angle(Vector4 inputvctr);
	Vector4 unitvector();
	Vector4 resultant(Vector4 inputvctr);
	Vector4 add(Vector4 inputvctr);
	Vector4 subtract(Vector4 inputvctr);
	Vector4 scale(float scale); // TODO investigate overload function not accepting int/double inputs
	Vector4 scale(Matrix4x4 inputmtrx);
//	Vector4 rotate(Matrix4x4 inputmtrx); // TODO investigate after completing Quaternion based rotations
	Vector4 translate(Matrix4x4 inputmtrx);
//      Vector3 crossproduct(Vector3 inputvctr); // TODO:experimenting with this function
	Vector4 operator*(const Matrix4x4& right); 
//      Vector4 operator*(const Vector4& right); // TODO experimenting based on crossproduct() conclusion
//      Vector4& operator*=(const Vector4& right);
	Vector4 operator+(const Vector4& right);
	Vector4& operator+=(const Vector4& right);
	Vector4 operator-(const Vector4& right);
	Vector4& operator-=(const Vector4& right);
	Vector4 operator^(const float power);
};
