#include "Vector3.h"
#include "../MatrixFiles/Matrix3x3.h"
#include "../MatrixFiles/Matrix2x2.h"
// TODO add [gh]
#include "Quaternion.h"
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

// TODO add [gh]
Vector3::Vector3(const float a, const float b, const float c) : x(a), y(b), z(c) {}

Vector3::Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z) {};

Vector3::Vector3(const Quaternion& other) : x(other.x), y(other.y), z(other.z) {};

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

float Vector3::dotproduct(const Vector3& inputvctr) const {
    return (x * inputvctr.x) 
        +(y * inputvctr.y) 
        +(z * inputvctr.z);
}

float Vector3::magnitude() const {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float Vector3::angle(const Vector3& inputvctr) const {
    float Product = dotproduct(inputvctr);
    float Magnitude = magnitude() * inputvctr.magnitude();
    return acos(Product / Magnitude) * (180 / PI);
}

Vector3 Vector3::unitvector() const {
    float denominator = magnitude();
    return Vector3{
        x/denominator,
        y/denominator,
        z/denominator
    };
}

Vector3 Vector3::resultant(const Vector3& inputvctr) const {
    return Vector3 {
        this->x + inputvctr.x, 
        this->y + inputvctr.y, 
        this->z + inputvctr.z
    };
}

Vector3 Vector3::add(const Vector3& inputvctr) const {
    return Vector3 {
        this->x + inputvctr.x, 
        this->y + inputvctr.y, 
        this->z + inputvctr.z
    };
}

Vector3 Vector3::subtract(const Vector3& inputvctr) const {
    return Vector3{
        this->x - inputvctr.x, 
        this->y - inputvctr.y, 
        this->z - inputvctr.z
    };
}

Vector3 Vector3::scale(const float& scale) const {
    return Vector3 {
        x * scale,
        y * scale,
        z * scale
    };
}

Vector3 Vector3::scale(const Matrix3x3& inputmtrx) const {
    return Vector3 {
        x * inputmtrx.matrix[0][0], 
        y * inputmtrx.matrix[1][1],
        z * inputmtrx.matrix[2][2]
    };
}

// TODO add [gh] [recheck this function to make sure there's nothing more to
// optimize, there's probably a lot you can do
Vector3 Vector3::rotate(const Vector3& axisvector, const float& angle) const {
    Quaternion local;
    local << *this << 0;
    Quaternion rotor = {static_cast<float>(cos(angle/2)), axisvector.unitvector().scale(sin(angle/2))};
    return static_cast<Vector3>(rotor * local * rotor.inverse());
}

// TODO add [gh]
Vector3 Vector3::rodrigues_rotate(const Vector3& axisvector, const float& angle) const {
    Vector3 Uaxisvector = axisvector.unitvector();
    Vector3 Uthis = this->unitvector();
    return Uthis.subtract(Uaxisvector.scale(Uaxisvector.dotproduct(Uthis))).scale(cos(angle)).add(Uaxisvector.crossproduct(Uthis).scale(sin(angle))).add(Uaxisvector.scale(Uaxisvector.dotproduct(Uthis))).scale(this->magnitude());
}

Vector3 Vector3::rodrigues_slerp(const Vector3& axisvector, const float& angle) const {
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

Vector3 Vector3::translate(const Matrix3x3& inputmtrx) const {
    return Vector3{
        x + inputmtrx.matrix[0][2],
        y + inputmtrx.matrix[1][2],
        z + inputmtrx.matrix[2][2]
    };
}

Vector3 Vector3::crossproduct(const Vector3& inputvctr) const {
    return Vector3{
        Matrix2x2 { 
            this->y, this->z,
            inputvctr.y, inputvctr.z
        }.determinant()

       ,-1 * Matrix2x2 {
            this->x, this->z,
            inputvctr.x, inputvctr.z
       }.determinant()

       ,Matrix2x2 { 
            this->x, this->y,
            inputvctr.x, inputvctr.y
       }.determinant()
    };
}

Vector3 Vector3::operator*(const Matrix3x3& right) const {
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

Vector3 Vector3::operator*(const Vector3& right) const {
    return this->crossproduct(right);
}

Vector3& Vector3::operator*=(const Vector3& right) {
    return *this = this->crossproduct(right);
}

Vector3 Vector3::operator*(const float& right) const {
    return this->scale(right);
}

Vector3& Vector3::operator*=(const float& right) {
    return *this = this->scale(right);
}

Vector3 Vector3::operator+(const Vector3& right) const {
    return this->add(right);
}

Vector3& Vector3::operator+=(const Vector3& right) {
    return *this = this->add(right);
}

Vector3 Vector3::operator-(const Vector3& right) const {
    return this->subtract(right);
}

Vector3& Vector3::operator-=(const Vector3& right) {
    return *this = this->subtract(right);
}

float Vector3::operator[](const int& index) const { // bad hack for now, will change in the future
    if (index == 0) { return x; } else if (index == 1) { return y; } else if (index == 2) { return z; }
    else { throw index; }
}
