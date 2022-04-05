// header file for Vector3 object
// find implementation in Vector3.cpp file
#pragma once
#include <iostream>
#include <cmath>
#include "../MatrixFiles/Matrix3x3.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342
//#include "./Quaternion.h"

class Matrix3x3;
class Quaternion;

class Vector3 {
public:
	float x, y, z;

    constexpr Vector3(const float a = 0, const float b = 0, const float c = 0) : x(a), y(b), z(c) {}
    constexpr Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z) {}
    //constexpr Vector3(const Quaternion& other); issue with file dependencies

	static void input(Vector3 &inputvctr) {
        std::cin >> inputvctr.x >> inputvctr.y >> inputvctr.z;
    }

	void printvector() const {
        std::cout << '(' << x << ", " << y << ", " << z << ')' << '\n';
    }

    template <typename TYPE>
        static void showResult(const TYPE& input) { 
            std::cout << input << '\n'; 
        }

	static void showResult(const Vector3& inputvctr) {
        std::cout << '(' << inputvctr.x << ", " << inputvctr.y << ", " << inputvctr.z << ')' << '\n';
    }

	inline constexpr float dotproduct(const Vector3& inputvctr) const noexcept {
        return (x * inputvctr.x) 
            +(y * inputvctr.y) 
            +(z * inputvctr.z);
    }

    inline constexpr float magnitude() const noexcept {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

	inline constexpr float angle(const Vector3& inputvctr) const noexcept {
        return acos(dotproduct(inputvctr) / this->magnitude() * inputvctr.magnitude()) * (180 / PI);
    }

    inline constexpr Vector3 unitvector() const noexcept {
        const float denominator = magnitude();
        return Vector3{
            x/denominator,
            y/denominator,
            z/denominator
        };
    }

    inline constexpr Vector3 resultant(const Vector3& inputvctr) const noexcept {
        return Vector3 {
            this->x + inputvctr.x, 
            this->y + inputvctr.y, 
            this->z + inputvctr.z
        };
    }

    inline constexpr Vector3 add(const Vector3& inputvctr) const noexcept {
        return Vector3 {
            this->x + inputvctr.x, 
                this->y + inputvctr.y, 
                this->z + inputvctr.z
        };
    }

    inline constexpr Vector3 subtract(const Vector3& inputvctr) const noexcept {
        return Vector3{
            this->x - inputvctr.x, 
            this->y - inputvctr.y, 
            this->z - inputvctr.z
        };
    }

    inline constexpr Vector3 scale(const float& scale) const noexcept {
        return Vector3 {
            x * scale,
            y * scale,
            z * scale
        };
    }

    inline constexpr Vector3 scale(const Matrix3x3& inputmtrx) const noexcept {
        return Vector3 {
            x * inputmtrx.matrix[0][0], 
            y * inputmtrx.matrix[1][1],
            z * inputmtrx.matrix[2][2]
        };
    }

    //inline constexpr Vector3 rotate(const Vector3& axisvector, const float& angle) const noexcept; issue with file dependencies
    inline constexpr Vector3 rodrigues_rotate(const Vector3& axisvector, const float& angle) const noexcept {
        Vector3 Uaxisvector = axisvector.unitvector();
        Vector3 Uthis = this->unitvector();
        return Uthis.subtract(Uaxisvector.scale(Uaxisvector.dotproduct(Uthis))).scale(cos(angle)).add(Uaxisvector.crossproduct(Uthis).scale(sin(angle))).add(Uaxisvector.scale(Uaxisvector.dotproduct(Uthis))).scale(this->magnitude());
    }

    inline constexpr Vector3 rodrigues_slerp(const Vector3& axisvector, const float& angle) const noexcept {
        return (*this - axisvector.scale(axisvector.dotproduct(*this)).scale(sin(angle))) + (axisvector.crossproduct(*this).scale(cos(angle)));
    }

    inline constexpr Vector3 rotate(const Matrix3x3& inputmtrx) const noexcept {
        return {
            (x * inputmtrx.matrix[0][0]) + (y * inputmtrx.matrix[0][1]) + (z * inputmtrx.matrix[0][2]),
            (x * inputmtrx.matrix[1][0]) + (y * inputmtrx.matrix[1][1]) + (z * inputmtrx.matrix[1][2]),
            (x * inputmtrx.matrix[2][0]) + (y * inputmtrx.matrix[2][1]) + (z * inputmtrx.matrix[2][2])
        };
    }

    inline constexpr Vector3 translate(const Matrix3x3& inputmtrx) const noexcept {
        return Vector3{
            x + inputmtrx.matrix[0][2],
            y + inputmtrx.matrix[1][2],
            z + inputmtrx.matrix[2][2]
        };
    }

    inline constexpr Vector3 crossproduct(const Vector3& inputvctr) const noexcept {
        return Vector3{
            this->y*inputvctr.z - this->z*inputvctr.y
           ,this->z*inputvctr.x - this->x*inputvctr.z
           ,this->x*inputvctr.y - this->y*inputvctr.x
        };
    }

    inline constexpr Vector3 operator*(const Matrix3x3& right) const noexcept {
        float local_vector_array[3] = {x, y, z};
        float result_vector_array[3] = {0, 0, 0};
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                result_vector_array[i] += right.matrix[i][j] * local_vector_array[j];
            }
        }
        return Vector3{
            result_vector_array[0],
            result_vector_array[1],
            result_vector_array[2]
        };
    }

    inline constexpr Vector3 operator*(const Vector3& right) const noexcept {
        return this->crossproduct(right);
    }

    inline constexpr Vector3& operator*=(const Vector3& right) noexcept {
        return *this = this->crossproduct(right);
    }

    inline constexpr Vector3 operator*(const float& right) const noexcept {
        return this->scale(right);
    }

    inline constexpr Vector3& operator*=(const float& right) noexcept {
        return *this = this->scale(right);
    }

    inline constexpr Vector3 operator+(const Vector3& right) const noexcept {
        return this->add(right);
    }

    inline constexpr Vector3& operator+=(const Vector3& right) noexcept {
        return *this = this->add(right);
    }

    inline constexpr Vector3 operator-(const Vector3& right) const noexcept {
        return this->subtract(right);
    }

    inline constexpr Vector3& operator-=(const Vector3& right) noexcept {
        return *this = this->subtract(right);
    }

    inline constexpr float operator[](const int& index) const {
        switch (index) {
            case 0:
                return this->x;
                break;
            case 1:
                return this->y;
                break;
            case 2:
                return this->z;
                break;
            default:
                throw index;
        }
    }
};
