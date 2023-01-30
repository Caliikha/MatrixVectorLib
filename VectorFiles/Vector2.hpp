// header file for Vector2 object
// find implementation in Vector2.cpp
#pragma once
#include <iostream>
#include "Vector3.hpp"
#include "../MatrixFiles/Matrix2x2.h"

class Vector3;
//class Matrix2x2;

class Vector2 {
public:
	float x, y;

    constexpr Vector2(const float& a, const float& b) : x(a), y(b) {};
    constexpr Vector2(const Vector2& other) : Vector2(other.x, other.y) {};

    void input(Vector2 &inputvctr) {
        std::cin >> inputvctr.x >> inputvctr.y;
    }

    void printvector() const {
        std::cout << "(" << x << ", " << y << ")" << '\n';
    }

    template <typename TYPE>
        static void showResult(TYPE input) { std::cout << input << '\n'; }

    void showResult(const Vector2& inputvctr) {
        std::cout << '(' << inputvctr.x << ", " << inputvctr.y << ')' << '\n';
    }

    constexpr float dotproduct(const Vector2& inputvctr) const noexcept {
        return (this->x * inputvctr.x) + (this->y * inputvctr.y);
    }

    constexpr float magnitude() const noexcept {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    constexpr float angle(const Vector2& inputvctr) const noexcept {
        float Product = this->dotproduct(inputvctr);
        float Magnitude = this->magnitude() * inputvctr.magnitude();
        return acos(Product / Magnitude) * (180 / PI);
    }

    constexpr Vector2 unitvector() const noexcept {
        float denominator = magnitude();
        return Vector2{
            x/denominator,
            y/denominator
        };
    }

    constexpr Vector2 resultant(const Vector2& inputvctr) const noexcept {
        return Vector2{this->x + inputvctr.x, this->y + inputvctr.y};
    }

    constexpr Vector2 add(const Vector2& inputvctr) const noexcept {
        return Vector2{this->x + inputvctr.x, this->y + inputvctr.y};
    }

    constexpr Vector2 subtract(const Vector2& inputvctr) const noexcept {
        return Vector2{this->x - inputvctr.x, this->y - inputvctr.y};
    }

    constexpr Vector2 scale(const float& scale) const noexcept {
        return Vector2{x * scale, y * scale};
    }

    constexpr Vector2 scale(const Matrix2x2& inputmtrx) const noexcept {
        return Vector2{
            x * inputmtrx.matrix[0][0],
            y * inputmtrx.matrix[1][1]
        };
    }

    constexpr Vector2 rotate(const Matrix2x2& inputmtrx) const noexcept {
        return Vector2{
            (x * inputmtrx.matrix[0][0]) + (y * inputmtrx.matrix[0][1]),
            (x * inputmtrx.matrix[1][0]) + (y * inputmtrx.matrix[1][1])
        };
    }

    constexpr Vector2 translate(const Matrix2x2& inputmtrx) const noexcept {
        return Vector2{
            x + inputmtrx.matrix[0][1],
            y + inputmtrx.matrix[1][1]
        };
    }
    // TODO look back at this function and test
    constexpr Vector3 crossproduct(const Vector2& inputvctr) const noexcept {
        return Vector3(
                 0
                ,0
                ,
                this->x*inputvctr.y - this->y*inputvctr.x
                );
    }

    constexpr Vector2 operator*(const Matrix2x2& right) const noexcept {
        float local_vector_array[2] = {x, y};
        float result_vector_array[3] = {0, 0};
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                result_vector_array[i] += right.matrix[i][j] * local_vector_array[j];
            }
        }
        return Vector2{
            result_vector_array[0],
            result_vector_array[1]
        };
    }

    constexpr Vector3 operator*(const Vector2& right) const noexcept {
        return this->crossproduct(right);
    }

    constexpr Vector2 operator+(const Vector2& right) const noexcept {
        return this->add(right);
    }

    constexpr Vector2& operator+=(const Vector2& right) noexcept {
        return *this = this->add(right);
    }

    constexpr Vector2 operator-(const Vector2& right) const noexcept {
        return this->subtract(right);
    }

    constexpr Vector2& operator-=(const Vector2& right) noexcept {
        return *this = this->subtract(right);
    }

    constexpr float operator[](const int& index) const { // very weak hack for now, it's functional, but will definitely find a way to improve in the future
        switch (index) {
            case 0:
                return this->x;
                break;
            case 1:
                return this->y;
                break;
            default:
                throw index;
        }
    }
};
