// header file for Vector2 object
// find implementation in Vector2.cpp
#pragma once
#include <iostream>

class Vector3;
class Matrix2x2;

class Vector2 {
public:
	float x = 0, y = 0; // Cartesian components

	// Assignment constructors
	Vector2() = default;
	Vector2(const float a, const float b) : x(a), y(b) {};
	Vector2(const float a) : x(a) {};
	Vector2(const Vector2& other) : Vector2(other.x, other.y) {};
	
	// Callable member functions for Vector2 type
	static void input(Vector2 &inputvctr);
	void printvector();
	template <typename TYPE>
		static void showResult(TYPE input) { std::cout << input << '\n'; }
	static void showResult(Vector2 inputvctr);
	float dotproduct(Vector2 inputvctr);
	float magnitude();
	float angle(Vector2 inputvctr);
	Vector2 unitvector();
	Vector2 resultant(Vector2 inputvctr);
	Vector2 add(Vector2 inputvctr); 
	Vector2 subtract(Vector2 inputvctr); 
	Vector2 scale(float scale);
	Vector2 scale(Matrix2x2 inputmtrx);
	Vector2 rotate(Matrix2x2 inputmtrx); 
	Vector2 translate(Matrix2x2 inputmtrx);
	Vector3 crossproduct(Vector2 inputvctr); 
	Vector2 operator*(const Matrix2x2& right);
	Vector3 operator*(const Vector2& right);
	Vector2 operator+(const Vector2& right);
	Vector2& operator+=(const Vector2& right);
	Vector2 operator-(const Vector2& right);
	Vector2& operator-=(const Vector2& right);
};
