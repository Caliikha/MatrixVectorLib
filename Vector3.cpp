#include "Vector3.h"
#include "../MatrixFiles/Matrix3x3.h"
#include "../MatrixFiles/Matrix2x2.h"
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

void Vector3::input(Vector3 &inputvctr) { 
    std::cin >> inputvctr.x >> inputvctr.y >> inputvctr.z;
}

void Vector3::printvector() {
    std::cout << '(' << x << ", " << y << ", " << z << ')' << '\n';
}

//template <typename TYPE> // templated functions must reside in header file
//void Vector3::showResult(TYPE input) { std::cout << input << '\n'; }

void Vector3::showResult(Vector3 inputvctr) {
    std::cout << '(' << inputvctr.x << ", " << inputvctr.y << ", " << inputvctr.z << ')' << '\n';
}

float Vector3::dotproduct(Vector3 inputvctr) {
    return (x * inputvctr.x) 
        +(y * inputvctr.y) 
        +(z * inputvctr.z);
}

float Vector3::magnitude() {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float Vector3::angle(Vector3 inputvctr) {
    float Product = dotproduct(inputvctr);
    float Magnitude = magnitude() * inputvctr.magnitude();
    return acos(Product / Magnitude) * (180 / PI);
}

Vector3 Vector3::unitvector() { 
    Vector3 resultVector;
    float denominator = magnitude();
    return resultVector = {
        x/denominator,
        y/denominator,
        z/denominator
    };
}

Vector3 Vector3::resultant(Vector3 inputvctr) {
    Vector3 resultVector;
    return resultVector = {
        x + inputvctr.x, 
        y + inputvctr.y, 
        z + inputvctr.z
    };
}

Vector3 Vector3::add(Vector3 inputvctr) { 
    Vector3 resultVector;
    return resultVector = {
        x + inputvctr.x, 
        y + inputvctr.y, 
        z + inputvctr.z
    };
}

Vector3 Vector3::subtract(Vector3 inputvctr) { 
    Vector3 resultVector;
    return resultVector = {
        x - inputvctr.x, 
        y - inputvctr.y, 
        z - inputvctr.z
    };
}

Vector3 Vector3::scale(float scale) {
    Vector3 resultVector;
    return resultVector = {
        x * scale,
        y * scale,
        z * scale
    };
}

Vector3 Vector3::scale(Matrix3x3 inputmtrx) {
    Vector3 resultVector;
    return resultVector = {
        x * inputmtrx.matrix[0][0], 
        y * inputmtrx.matrix[1][1],
        z * inputmtrx.matrix[2][2]
    };
}

//	Vector3 rotate(Matrix3x3 inputmtrx) { // function doesn't work 
//		Vector3 resultVector;
//		resultVector.x = (x * inputmtrx.matrix[0][0]) + (y * inputmtrx.matrix[0][1]) + (z * inputmtrx.matrix[0][2]);
//		resultVector.y = (x * inputmtrx.matrix[1][0]) + (y * inputmtrx.matrix[1][1]) + (z * inputmtrx.matrix[1][2]);
//		resultVector.z = (x * inputmtrx.matrix[2][0]) + (y * inputmtrx.matrix[2][1]) + (z * inputmtrx.matrix[2][2]);
//		return resultVector;
//	}

Vector3 Vector3::translate(Matrix3x3 inputmtrx){
    Vector3 resultVector;
    return resultVector = {
        x + inputmtrx.matrix[0][2],
        y + inputmtrx.matrix[1][2],
        z + inputmtrx.matrix[2][2]
    };
}

Vector3 Vector3::crossproduct(Vector3 inputvctr) { 
    Vector3 resultVector;
    Matrix2x2 i_matrix = {
        y, z,
        inputvctr.y, inputvctr.z
    };
    Matrix2x2 j_matrix = {
        x, z,
        inputvctr.x, inputvctr.z
    };
    Matrix2x2 k_matrix = { 
        x, y,
        inputvctr.x, inputvctr.y
    };

    return resultVector = {
        i_matrix.determinant(),
        -j_matrix.determinant(),
        k_matrix.determinant()
    };
}

Vector3 Vector3::operator*(const Matrix3x3& right) {
    Vector3 resultVector;
    float local_vector_array[3] = {x, y, z};
    float result_vector_array[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            result_vector_array[i] += right.matrix[i][j] * local_vector_array[j];
        }
    }
    return resultVector = {
        result_vector_array[0],
        result_vector_array[1],
        result_vector_array[2]
    };
}

Vector3 Vector3::operator*(const Vector3& right) {
    return crossproduct(right);
}

Vector3& Vector3::operator*=(const Vector3& right) {
    Vector3 resultVector = crossproduct(right);
    x = resultVector.x;
    y = resultVector.y;
    z = resultVector.z;
    return *this;
}

Vector3 Vector3::operator+(const Vector3& right) {
    return add(right);
}

Vector3& Vector3::operator+=(const Vector3& right) {
    Vector3 resultVector = add(right);
    x = resultVector.x;
    y = resultVector.y;
    z = resultVector.z;
    return *this;
}

Vector3 Vector3::operator-(const Vector3& right) {
    return subtract(right);
}

Vector3& Vector3::operator-=(const Vector3& right) {
    Vector3 resultVector = subtract(right);
    x = resultVector.x;
    y = resultVector.y;
    z = resultVector.z;
    return *this;
}
