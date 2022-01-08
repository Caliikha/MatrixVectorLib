// header file for Vector2 object
// find implementation in Vector2.cpp
#pragma once
#include <iostream>

class Vector3;
class Matrix2x2;

class Vector2 {
public:
	float x, y;

    Vector2(const float& a = 0, const float& b = 0);
    Vector2(const Vector2& other);

	static void input(Vector2 &inputvctr);
	void printvector() const ;
    template <typename TYPE>
        static void showResult(TYPE input) { std::cout << input << '\n'; }
	static void showResult(const Vector2& inputvctr);
	float dotproduct(const Vector2& inputvctr) const;
    float magnitude() const;
	float angle(const Vector2& inputvctr) const;
    Vector2 unitvector() const;
	Vector2 resultant(const Vector2& inputvctr) const;
	Vector2 add(const Vector2& inputvctr) const; 
	Vector2 subtract(const Vector2& inputvctr) const; 
	Vector2 scale(const float& scale) const;
    Vector2 scale(const Matrix2x2& inputmtrx) const;
	Vector2 rotate(const Matrix2x2& inputmtrx) const; 
    Vector2 translate(const Matrix2x2& inputmtrx) const;
    Vector3 crossproduct(const Vector2& inputvctr) const; 
    Vector2 operator*(const Matrix2x2& right) const;
    Vector3 operator*(const Vector2& right) const;
    Vector2 operator+(const Vector2& right) const;
    Vector2& operator+=(const Vector2& right);
    Vector2 operator-(const Vector2& right) const;
    Vector2& operator-=(const Vector2& right);
    float operator[](const int& index) const;
};
