#include "Vector4.h"
#include "Vector3.h"
#include "../MatrixFiles/Matrix3x3.h"
#include "../MatrixFiles/Matrix4x4.h"
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342
#define INT_MIN -2147483648
#define INT_MAX  2147483647

constexpr Vector4::Vector4(const float& a, const float& b, const float& c, const float& d) : x(a), y(b), z(c), w(d) {};

void Vector4::input(Vector4 &inputvctr) { 
    std::cin >> inputvctr.x >> inputvctr.y >> inputvctr.z >> inputvctr.w;
}

void Vector4::printvector() const {
    std::cout << '(' << x << ", " << y << ", " << z << ", " << w << ')' << '\n';
}

//template <typename TYPE> // Templated function's definitions must reside in the header file
//void Vector4::showResult(TYPE input) { std::cout << input << '\n'; }

void Vector4::showResult(const Vector4& inputvctr) {
    std::cout << '(' << inputvctr.x << ", " << inputvctr.y << ", " << inputvctr.z << ", " << inputvctr.w << ')' << '\n';
}

constexpr float Vector4::dotproduct(const Vector4& inputvctr) const noexcept{
    return 
         (x * inputvctr.x) 
        +(y * inputvctr.y) 
        +(z * inputvctr.z) 
        +(w * inputvctr.w);
}

constexpr float Vector4::magnitude() const noexcept{
    return sqrt(
                pow(x, 2) 
               +pow(y, 2) 
               +pow(z, 2) 
               +pow(w, 2)
    );
}

constexpr float Vector4::angle(const Vector4& inputvctr) const noexcept{
    float Product = dotproduct(inputvctr);
    float Magnitude = magnitude() * inputvctr.magnitude();
    return acos(Product / Magnitude) * (180 / PI);
}

constexpr Vector4 Vector4::unitvector() const noexcept{ 
    float denominator = magnitude();
    return Vector4{
        x/denominator,
        y/denominator,
        z/denominator,
        w/denominator
    };
}

constexpr Vector4 Vector4::resultant(const Vector4& inputvctr) const noexcept{
    return Vector4{
        this->x + inputvctr.x,
        this->y + inputvctr.y,
        this->z + inputvctr.z,
        this->w + inputvctr.w
    };
}

constexpr Vector4 Vector4::add(const Vector4& inputvctr) const noexcept{
    return Vector4{
        this->x + inputvctr.x,
        this->y + inputvctr.y,
        this->z + inputvctr.z,
        this->w + inputvctr.w
    };
}

constexpr Vector4 Vector4::subtract(const Vector4& inputvctr) const noexcept{
    return Vector4{
        this->x - inputvctr.x,
        this->y - inputvctr.y,
        this->z - inputvctr.z,
        this->w - inputvctr.w
    };
}

// TODO FIX THIS STUPID OVERLOAD
constexpr Vector4 Vector4::scale(const float& scale) const noexcept{
    return Vector4 {
        x * scale,
        y * scale,
        z * scale,
        w * scale
    };
}

constexpr Vector4 Vector4::scale(const Matrix4x4& inputmtrx) const noexcept{
    return Vector4 {
        x * inputmtrx.matrix[0][0],
        y * inputmtrx.matrix[1][1],
        z * inputmtrx.matrix[2][2],
        w * inputmtrx.matrix[3][3]
    };
}

//	Vector4 Vector4::rotate(Matrix4x4 inputmtrx) { // not functioning correctly, mathematics is probably incorrect
//		Vector4 resultVector = { 0, 0, 0, 0 };
//		for (int i = 0; i < 4; i++) {
//			resultVector.x += x * inputmtrx.matrix[0][i];
//		}
//		for (int i = 0; i < 4; i++) {
//			resultVector.y += y * inputmtrx.matrix[1][i];
//		}
//		for (int i = 0; i < 4; i++) {
//			resultVector.z += z * inputmtrx.matrix[2][i];
//		}
//		for (int i = 0; i < 4; i++) {
//			resultVector.w += w * inputmtrx.matrix[3][i];
//		}
//		return resultVector;
//	}
//
//	Vector4 Vector4::test_rotate(Matrix4x4 inputmtrx) { // not functioning correctly, mathematics is probably incorrect
//		Vector4 resultVector;
//		resultVector.x = (inputmtrx.matrix[0][0] * x) + (inputmtrx.matrix[0][1] * y) + (inputmtrx.matrix[0][2] * z);
//		resultVector.y = (inputmtrx.matrix[1][0] * x) + (inputmtrx.matrix[1][1] * y) + (inputmtrx.matrix[1][2] * z);
//		resultVector.z = (inputmtrx.matrix[2][0] * x) + (inputmtrx.matrix[2][1] * y) + (inputmtrx.matrix[2][2] * z);
//		resultVector.w = w;
//		return resultVector;
//	}

constexpr Vector4 Vector4::translate(const Matrix4x4& inputmtrx) const noexcept{
    return Vector4{
        x + inputmtrx.matrix[0][3],
        y + inputmtrx.matrix[1][3],
        z + inputmtrx.matrix[2][3],
        w + inputmtrx.matrix[3][3]
    };
}

//template <class vectordimension = Vector4>
//vectordimension Vector4::crossproduct(vectordimension inputvctr) {
//    vectordimension resultVector;
//    static_assert(std::is_same<vectordimension, Vector4>::value || std::is_same<vectordimension, Vector3>::value, "template argument must be the same as function argument input. && input must be of either Vector3 or Vector4 type");
//    if constexpr (std::is_same<vectordimension, Vector4>::value) {
//        Vector3 quaternionVector_local = {x, y, z};
//        Vector3 quaternionVector_input = {inputvctr.x, inputvctr.y, inputvctr.z};
//        Vector3 resultVector_3D = quaternionVector_local.crossproduct(quaternionVector_input);
//        return resultVector = {resultVector_3D.x, resultVector_3D.y, resultVector_3D.z, w};
//    }
//    else if constexpr (std::is_same<vectordimension, Vector3>::value) {
//        Vector3 quaternionVector_local = {x, y, z};
//        return resultVector = quaternionVector_local.crossproduct(inputvctr);
//    }
//    else {
//        std::cerr << "template argument must be the same as function argument input && input must be of either Vector3 or Vector4 type" << std::endl;
//        return resultVector = {INT_MIN, INT_MIN, INT_MIN};
//    }
//}

constexpr Vector4 Vector4::operator*(const Matrix4x4& right) const noexcept{
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

//Vector4 Vector4::operator*(const Vector4& right) {
//    return crossproduct(right);
//}
//
//Vector4& Vector4::operator*=(const Vector4& right) {
//    Vector4 resultVector = crossproduct(right);
//    x = resultVector.x;
//    y = resultVector.y;
//    z = resultVector.z;
//    w = resultVector.w;
//    return *this;
//}

constexpr Vector4 Vector4::operator+(const Vector4& right) const noexcept{
    return this->add(right);
}

constexpr Vector4& Vector4::operator+=(const Vector4& right) noexcept{
    return *this = this->add(right);
}

constexpr Vector4 Vector4::operator-(const Vector4& right) const noexcept{
    return this->subtract(right);
}

constexpr Vector4& Vector4::operator-=(const Vector4& right) noexcept{
    return *this = this->subtract(right);
}

constexpr Vector4 Vector4::operator^(const float& power) const noexcept{
    return {
        static_cast<float>(pow(x, power)),
        static_cast<float>(pow(y, power)),
        static_cast<float>(pow(z, power)),
        static_cast<float>(pow(w, power))
    };
}

constexpr float Vector4::operator[](const int& index) const { // bad hack for now, but will fix in the future
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
