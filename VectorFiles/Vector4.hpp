// Header file for Vector4 object type
// Check Vector4.cpp for implementation of functions
#pragma once
#include <iostream>
#include <cmath>
#include "../MatrixFiles/Matrix4x4.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

class Vector3;
class Matrix3x3;
class Matrix4x4;

class Vector4 {
public:
	float x, y, z, w;

    constexpr Vector4(const float& a = 0, const float& b = 0, const float& c = 0, const float& d = 0) : x(a), y(b), z(c), w(d) {}

	static void input(Vector4 &inputvctr) {
        std::cin >> inputvctr.x >> inputvctr.y >> inputvctr.z >> inputvctr.w;
    }

	void printvector() const {
        std::cout << '(' << x << ", " << y << ", " << z << ", " << w << ')' << '\n';
    }

    template <typename TYPE>
        static void showResult(TYPE input) { std::cout << input << '\n'; }

    static void showResult(const Vector4& inputvctr) {
        std::cout << '(' << inputvctr.x << ", " << inputvctr.y << ", " << inputvctr.z << ", " << inputvctr.w << ')' << '\n';
    }

    constexpr float dotproduct(const Vector4& inputvctr) const noexcept {
        return 
             (x * inputvctr.x) 
            +(y * inputvctr.y) 
            +(z * inputvctr.z) 
            +(w * inputvctr.w);
    }

    constexpr float magnitude() const noexcept {
        return sqrt(
                    pow(x, 2) 
                   +pow(y, 2) 
                   +pow(z, 2) 
                   +pow(w, 2)
        );
    }

    constexpr float angle(const Vector4& inputvctr) const noexcept {
        return acos(dotproduct(inputvctr) / magnitude() * inputvctr.magnitude()) * (180 / PI);
    }

    constexpr Vector4 unitvector() const noexcept {
        const float denominator = magnitude();
        return Vector4{
            x/denominator,
            y/denominator,
            z/denominator,
            w/denominator
        };
    }

    constexpr Vector4 resultant(const Vector4& inputvctr) const noexcept {
        return Vector4{
            this->x + inputvctr.x,
            this->y + inputvctr.y,
            this->z + inputvctr.z,
            this->w + inputvctr.w
        };
    }

    constexpr Vector4 add(const Vector4& inputvctr) const noexcept {
        return Vector4{
            this->x + inputvctr.x,
            this->y + inputvctr.y,
            this->z + inputvctr.z,
            this->w + inputvctr.w
        };
    }

    constexpr Vector4 subtract(const Vector4& inputvctr) const noexcept {
        return Vector4{
            this->x - inputvctr.x,
            this->y - inputvctr.y,
            this->z - inputvctr.z,
            this->w - inputvctr.w
        };
    }

    constexpr Vector4 scale(const float& scale) const noexcept{
        return Vector4 {
            x * scale,
            y * scale,
            z * scale,
            w * scale
        };
    } // TODO investigate overload function not accepting int/double inputs

    constexpr Vector4 scale(const Matrix4x4& inputmtrx) const noexcept {
        return Vector4 {
            x * inputmtrx.matrix[0][0],
            y * inputmtrx.matrix[1][1],
            z * inputmtrx.matrix[2][2],
            w * inputmtrx.matrix[3][3]
        };
    }

    //	Vector4 rotate(Matrix4x4 inputmtrx); // TODO investigate after completing Quaternion based rotations
    
    constexpr Vector4 translate(const Matrix4x4& inputmtrx) const noexcept {
        return Vector4{
            x + inputmtrx.matrix[0][3],
            y + inputmtrx.matrix[1][3],
            z + inputmtrx.matrix[2][3],
            w + inputmtrx.matrix[3][3]
        };
    }

    //  Vector3 crossproduct(Vector3 inputvctr); // TODO:experimenting with this function
    
    constexpr Vector4 operator*(const Matrix4x4& right) const noexcept{
        float local_vector_array[4] = {x, y, z, w};
        float result_vector_array[4] = {0, 0, 0, 0};
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                result_vector_array[i] += right.matrix[i][j] * local_vector_array[j];
            }
        }
        return Vector4{
            result_vector_array[0],
            result_vector_array[1],
            result_vector_array[2],
            result_vector_array[3]
        };
    }

    //  Vector4 operator*(const Vector4& right); // TODO experimenting based on crossproduct() conclusion
    
    //  Vector4& operator*=(const Vector4& right);
    
    constexpr Vector4 operator+(const Vector4& right) const noexcept{
        return this->add(right);
    }

    constexpr Vector4& operator+=(const Vector4& right) noexcept{
        return *this = this->add(right);
    }

    constexpr Vector4 operator-(const Vector4& right) const noexcept{
        return this->subtract(right);
    }

    constexpr Vector4& operator-=(const Vector4& right) noexcept{
        return *this = this->subtract(right);
    }

    constexpr Vector4 operator^(const float& power) const noexcept{
        return {
            static_cast<float>(pow(x, power)),
            static_cast<float>(pow(y, power)),
            static_cast<float>(pow(z, power)),
            static_cast<float>(pow(w, power))
        };
    }

    constexpr float operator[](const int& index) const { // bad hack for now, but will fix in the future
        switch(index) {
            case 0:
                return this->x;
                break;
            case 1:
                return this->y;
                break;
            case 2:
                return this->z;
                break;
            case 3:
                return this->w;
                break;
            default:
                throw index;
        }
    }
};
