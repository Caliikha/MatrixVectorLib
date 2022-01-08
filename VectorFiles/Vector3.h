// header file for Vector3 object
// find implementation in Vector3.cpp file
#pragma once
#include <iostream>

class Matrix3x3;
class Quaternion;

class Vector3 {
public:
	float x, y, z;

    Vector3(const float a = 0, const float b = 0, const float c = 0);
    Vector3(const Vector3& other);
    // TODO add [gh]
    Vector3(const Quaternion& other);

	static void input(Vector3 &inputvctr); 
	void printvector() const;
    template <typename TYPE>
        static void showResult(const TYPE& input) { std::cout << input << '\n'; }
	static void showResult(const Vector3& inputvctr);
	float dotproduct(const Vector3& inputvctr) const;
    float magnitude() const;
	float angle(const Vector3& inputvctr) const;
    Vector3 unitvector() const; 
	Vector3 resultant(const Vector3& inputvctr) const;
	Vector3 add(const Vector3& inputvctr) const;
	Vector3 subtract(const Vector3& inputvctr) const;
	Vector3 scale(const float& scale) const;
	Vector3 scale(const Matrix3x3& inputmtrx) const;
    Vector3 rotate(const Vector3& axisvector, const float& angle) const;
    // TODO add [gh]
    Vector3 rodrigues_rotate(const Vector3& axisvector, const float& angle) const;
    Vector3 rodrigues_slerp(const Vector3& axisvector, const float& angle) const;
//	Vector3 rotate(Matrix3x3 inputmtrx); // function doesn't work 
    Vector3 translate(const Matrix3x3& inputmtrx) const;
    Vector3 crossproduct(const Vector3& inputvctr) const;
    Vector3 operator*(const Matrix3x3& right) const;
    Vector3 operator*(const Vector3& right) const;
    Vector3& operator*=(const Vector3& right);
    Vector3 operator*(const float& right) const;
    Vector3& operator*=(const float& right);
    Vector3 operator+(const Vector3& right) const;
    Vector3& operator+=(const Vector3& right);
    Vector3 operator-(const Vector3& right) const;
    Vector3& operator-=(const Vector3& right);
    float operator[](const int& index) const;
};
