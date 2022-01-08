// implementation file for Vector2.h
#include "Vector2.h"
#include "Vector3.h"
#include "../MatrixFiles/Matrix2x2.h"
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

// TODO add [gh] make sure implementation stays in .cpp file
Vector2::Vector2(const float& a, const float& b) : x(a), y(b) {};
Vector2::Vector2(const Vector2& other) : Vector2(other.x, other.y) {};

void Vector2::input(Vector2 &inputvctr) {
    std::cin >> inputvctr.x >> inputvctr.y;
}

void Vector2::printvector() const {
    std::cout << "(" << x << ", " << y << ")" << '\n';
}

//template <typename TYPE> // templated functions must reside in header files
//void Vector2::showResult(TYPE input) { std::cout << input << '\n'; }

void Vector2::showResult(const Vector2& inputvctr) {
    std::cout << '(' << inputvctr.x << ", " << inputvctr.y << ')' << '\n';
}

float Vector2::dotproduct(const Vector2& inputvctr) const {
    return (this->x * inputvctr.x) + (this->y * inputvctr.y);
}

float Vector2::magnitude() const {
    return sqrt(pow(x, 2) + pow(y, 2));
}

float Vector2::angle(const Vector2& inputvctr) const {
    float Product = this->dotproduct(inputvctr);
    float Magnitude = this->magnitude() * inputvctr.magnitude();
    return acos(Product / Magnitude) * (180 / PI);
}

Vector2 Vector2::unitvector() const {
    float denominator = magnitude();
    return Vector2{
        x/denominator,
        y/denominator
    };
}

Vector2 Vector2::resultant(const Vector2& inputvctr) const {
    return Vector2{this->x + inputvctr.x, this->y + inputvctr.y};
}

Vector2 Vector2::add(const Vector2& inputvctr) const { 
    return Vector2{this->x + inputvctr.x, this->y + inputvctr.y};
}

Vector2 Vector2::subtract(const Vector2& inputvctr) const {
    return Vector2{this->x - inputvctr.x, this->y - inputvctr.y};
}

Vector2 Vector2::scale(const float& scale) const {
    return Vector2{x * scale, y * scale};
}

Vector2 Vector2::scale(const Matrix2x2& inputmtrx) const {
    return Vector2{
        x * inputmtrx.matrix[0][0],
        y * inputmtrx.matrix[1][1]
    };
}

Vector2 Vector2::rotate(const Matrix2x2& inputmtrx) const {
    return Vector2{
        (x * inputmtrx.matrix[0][0]) + (y * inputmtrx.matrix[0][1]),
        (x * inputmtrx.matrix[1][0]) + (y * inputmtrx.matrix[1][1])
    };
}

Vector2 Vector2::translate(const Matrix2x2& inputmtrx) const {
    return Vector2{
        x + inputmtrx.matrix[0][1],
        y + inputmtrx.matrix[1][1]
    };
}
// TODO look back at this function and test
Vector3 Vector2::crossproduct(const Vector2& inputvctr) const {
    return Vector3(
             0
            ,0
            ,Matrix2x2{
            this->x, this->y, 
            inputvctr.x, inputvctr.y}.determinant()
            );
}

Vector2 Vector2::operator*(const Matrix2x2& right) const {
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

Vector3 Vector2::operator*(const Vector2& right) const {
    return this->crossproduct(right);
}

Vector2 Vector2::operator+(const Vector2& right) const {
    return this->add(right);
}

Vector2& Vector2::operator+=(const Vector2& right) {
    return *this = this->add(right);
}

Vector2 Vector2::operator-(const Vector2& right) const {
    return this->subtract(right);
}

Vector2& Vector2::operator-=(const Vector2& right) {
    return *this = this->subtract(right);
}

float Vector2::operator[](const int& index) const { // very weak hack for now, it's functional, but will definitely find a way to improve in the future
    if (index == 0) { return this->x; } else if (index == 1) { return this->y; }
    else { throw index; }
}
