// Header file for Vector4 object type
// Check Vector4.cpp for implementation of functions
#pragma once
#include <iostream>

class Vector3;
class Matrix3x3;
class Matrix4x4;

class Vector4 {
public:
	float x, y, z, w;

    Vector4(const float& a = 0, const float& b = 0, const float& c = 0, const float& d = 0);
    // TODO: check if the copy constructor is really needed? 
    //Vector4(const Vector4& other) : Vector4(other.x, other.y, other.z, other.w) {};

	static void input(Vector4 &inputvctr);
	void printvector() const;
    template <typename TYPE>
        static void showResult(TYPE input) { std::cout << input << '\n'; }
    static void showResult(const Vector4& inputvctr);
	float dotproduct(const Vector4& inputvctr) const;
    float magnitude() const;
	float angle(const Vector4& inputvctr) const;
    Vector4 unitvector() const;
	Vector4 resultant(const Vector4& inputvctr) const;
    Vector4 add(const Vector4& inputvctr) const;
    Vector4 subtract(const Vector4& inputvctr) const;
	Vector4 scale(const float& scale) const; // TODO investigate overload function not accepting int/double inputs
	Vector4 scale(const Matrix4x4& inputmtrx) const;
//	Vector4 rotate(Matrix4x4 inputmtrx); // TODO investigate after completing Quaternion based rotations
	Vector4 translate(const Matrix4x4& inputmtrx) const;
//  Vector3 crossproduct(Vector3 inputvctr); // TODO:experimenting with this function
    Vector4 operator*(const Matrix4x4& right) const; 
//  Vector4 operator*(const Vector4& right); // TODO experimenting based on crossproduct() conclusion
//  Vector4& operator*=(const Vector4& right);
    Vector4 operator+(const Vector4& right) const;
    Vector4& operator+=(const Vector4& right);
    Vector4 operator-(const Vector4& right) const;
    Vector4& operator-=(const Vector4& right);
    Vector4 operator^(const float& power) const;
    float operator[](const int& index) const;
};
