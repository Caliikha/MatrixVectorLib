#include "Vector3.hpp"
#include "../MatrixFiles/Matrix3x3.h"
#include "../MatrixFiles/Matrix2x2.h"
// TODO add [gh]
#include "Quaternion.hpp"
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

// TODO add [gh]
constexpr Vector3::Vector3(const float a, const float b, const float c) : x(a), y(b), z(c) {}

constexpr Vector3::Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z) {};

//inline constexpr Vector3::Vector3(const Quaternion& other) : x(other.x), y(other.y), z(other.z) {};

void Vector3::input(Vector3 &inputvctr) { 
    std::cin >> inputvctr.x >> inputvctr.y >> inputvctr.z;
}

void Vector3::printvector() const {
    std::cout << '(' << x << ", " << y << ", " << z << ')' << '\n';
}

//template <typename TYPE> // templated functions must reside in header file
//void Vector3::showResult(TYPE input) { std::cout << input << '\n'; }

void Vector3::showResult(const Vector3& inputvctr) {
    std::cout << '(' << inputvctr.x << ", " << inputvctr.y << ", " << inputvctr.z << ')' << '\n';
}

inline constexpr float Vector3::dotproduct(const Vector3& inputvctr) const noexcept {
    return (x * inputvctr.x) 
        +(y * inputvctr.y) 
        +(z * inputvctr.z);
}

inline constexpr float Vector3::magnitude() const noexcept {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

inline constexpr float Vector3::angle(const Vector3& inputvctr) const noexcept {
    return acos(dotproduct(inputvctr) / this->magnitude() * inputvctr.magnitude()) * (180 / PI);
}

inline constexpr Vector3 Vector3::unitvector() const noexcept {
    constexpr const float denominator = magnitude();
    return Vector3{
        x/denominator,
        y/denominator,
        z/denominator
    };
}

inline constexpr Vector3 Vector3::resultant(const Vector3& inputvctr) const noexcept {
    return Vector3 {
        this->x + inputvctr.x, 
        this->y + inputvctr.y, 
        this->z + inputvctr.z
    };
}

inline constexpr Vector3 Vector3::add(const Vector3& inputvctr) const noexcept {
    return Vector3 {
        this->x + inputvctr.x, 
        this->y + inputvctr.y, 
        this->z + inputvctr.z
    };
}

inline constexpr Vector3 Vector3::subtract(const Vector3& inputvctr) const noexcept {
    return Vector3{
        this->x - inputvctr.x, 
        this->y - inputvctr.y, 
        this->z - inputvctr.z
    };
}

inline constexpr Vector3 Vector3::scale(const float& scale) const noexcept {
    return Vector3 {
        x * scale,
        y * scale,
        z * scale
    };
}

inline constexpr Vector3 Vector3::scale(const Matrix3x3& inputmtrx) const noexcept {
    return Vector3 {
        x * inputmtrx.matrix[0][0], 
        y * inputmtrx.matrix[1][1],
        z * inputmtrx.matrix[2][2]
    };
}

// TODO add [gh] [recheck this function to make sure there's nothing more to
// optimize, there's probably a lot you can do
//inline constexpr Vector3 Vector3::rotate(const Vector3& axisvector, const float& angle) const noexcept {
//    Quaternion local(*this,0);
//    Quaternion rotor = {static_cast<float>(cos(angle/2)), axisvector.unitvector().scale(sin(angle/2))};
//    return static_cast<Vector3>(rotor * local * rotor.inverse());
//}

// TODO add [gh]
inline constexpr Vector3 Vector3::rodrigues_rotate(const Vector3& axisvector, const float& angle) const noexcept {
    Vector3 Uaxisvector = axisvector.unitvector();
    Vector3 Uthis = this->unitvector();
    return Uthis.subtract(Uaxisvector.scale(Uaxisvector.dotproduct(Uthis))).scale(cos(angle)).add(Uaxisvector.crossproduct(Uthis).scale(sin(angle))).add(Uaxisvector.scale(Uaxisvector.dotproduct(Uthis))).scale(this->magnitude());
}

inline constexpr Vector3 Vector3::rodrigues_slerp(const Vector3& axisvector, const float& angle) const noexcept {
    return (*this - axisvector.scale(axisvector.dotproduct(*this)).scale(sin(angle))) + (axisvector.crossproduct(*this).scale(cos(angle)));
    return (axisvector.crossproduct(*this).scale(cos(angle)) - (*this - axisvector.scale(axisvector.dotproduct(*this)).scale(sin(angle)))).scale(-1);
}

//	Vector3 rotate(Matrix3x3 inputmtrx) { // function doesn't work 
//		Vector3 resultVector;
//		resultVector.x = (x * inputmtrx.matrix[0][0]) + (y * inputmtrx.matrix[0][1]) + (z * inputmtrx.matrix[0][2]);
//		resultVector.y = (x * inputmtrx.matrix[1][0]) + (y * inputmtrx.matrix[1][1]) + (z * inputmtrx.matrix[1][2]);
//		resultVector.z = (x * inputmtrx.matrix[2][0]) + (y * inputmtrx.matrix[2][1]) + (z * inputmtrx.matrix[2][2]);
//		return resultVector;
//	}

inline constexpr Vector3 Vector3::translate(const Matrix3x3& inputmtrx) const noexcept {
    return Vector3{
        x + inputmtrx.matrix[0][2],
        y + inputmtrx.matrix[1][2],
        z + inputmtrx.matrix[2][2]
    };
}

inline constexpr Vector3 Vector3::crossproduct(const Vector3& inputvctr) const noexcept {
    return Vector3{
        this->y*inputvctr.z - this->z*inputvctr.y
       ,this->z*inputvctr.x - this->x*inputvctr.z
       ,this->x*inputvctr.y - this->y*inputvctr.x
    };
}

inline constexpr Vector3 Vector3::operator*(const Matrix3x3& right) const noexcept {
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

inline constexpr Vector3 Vector3::operator*(const Vector3& right) const noexcept {
    return this->crossproduct(right);
}

inline constexpr Vector3& Vector3::operator*=(const Vector3& right) noexcept {
    return *this = this->crossproduct(right);
}

inline constexpr Vector3 Vector3::operator*(const float& right) const noexcept {
    return this->scale(right);
}

inline constexpr Vector3& Vector3::operator*=(const float& right) noexcept {
    return *this = this->scale(right);
}

inline constexpr Vector3 Vector3::operator+(const Vector3& right) const noexcept {
    return this->add(right);
}

inline constexpr Vector3& Vector3::operator+=(const Vector3& right) noexcept {
    return *this = this->add(right);
}

inline constexpr Vector3 Vector3::operator-(const Vector3& right) const noexcept {
    return this->subtract(right);
}

inline constexpr Vector3& Vector3::operator-=(const Vector3& right) noexcept {
    return *this = this->subtract(right);
}

inline constexpr float Vector3::operator[](const int& index) const { // bad hack for now, will change in the future
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
