// Header + Implementation file for Quaternion object
// Templated functions must reside in Header file, therefore there is no .cpp Implementation file like the other files in this library
#pragma once
#include <iostream>
#include "Vector4.hpp"
#include "Vector3.hpp"
#include "Vector2.hpp"
#include "../MatrixFiles/Matrix4x4.h"
#include "../MatrixFiles/Matrix3x3.h"
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342
#define INT_MIN -2147483648
#define INT_MAX  2147483647

class Quaternion : public Vector4 {
public:
    constexpr Quaternion(const float& a = 0, const float& b = 0, const float& c = 0, const float& d = 0) : Vector4(a, b, c, d) {};
    constexpr Quaternion(const Vector4& Vector_4D) : Quaternion(Vector_4D.x, Vector_4D.y, Vector_4D.z, Vector_4D.w) {};
    constexpr Quaternion(const Vector3& Vector_3D) : Quaternion(Vector_3D.x, Vector_3D.y, Vector_3D.z) {};
    constexpr Quaternion(const float& a, const Vector3& Vector_3D) : Quaternion(Vector_3D.x, Vector_3D.y, Vector_3D.z, a) {}
    constexpr Quaternion(const Vector3& Vector_3D, const float& a) : Quaternion(Vector_3D.x, Vector_3D.y, Vector_3D.z, a) {}

    template <typename numerictype = float>
    inline constexpr Quaternion& operator<<(const numerictype& Real) noexcept {
        static_assert(
                   std::is_same<numerictype, float>::value 
                || std::is_same<numerictype, double>::value 
                || std::is_same<numerictype, int>::value, 
                "'<<' operator should only be used with [int], [double], or [float] values for assignment of W/Real");

        w = static_cast<float>(Real);
        return *this;
    }

    inline Quaternion& operator<<(const Vector4& Vprime) noexcept { return *this = {Vprime.x, Vprime.y, Vprime.z, Vprime.w}; }
    
    inline Quaternion& operator<<(const Vector3& Vprime) noexcept { return *this = {Vprime.x, Vprime.y, Vprime.z, w}; }

    inline static void input(Vector4 &inputvctr) {
        std::cin >> inputvctr.x >> inputvctr.y >> inputvctr.z >> inputvctr.w;
    }

    inline void printquaternion() const noexcept {
        std::cout << '[' << w;
        if (x >= 0) { std::cout << " + " << x << 'i'; }
        else { std::cout << " - " << -x << 'i'; }

        if (y >= 0) { std::cout << " + " << y << 'j'; }
        else { std::cout << " - " << -y << 'j'; }

        if (z >= 0) { std::cout << " + " << z << 'k'; }
        else { std::cout << " - " << -z << 'k'; }
        std::cout << ']' << std::endl;
    }

//    template <class TYPE> this function breaks everything
//    static void showResult(TYPE input) noexcept {
//        std::cout << input << '\n';
//    }

    // TODO: check if you can allow to be templated function for quat obj to be printed as Vec4 or Quat
    inline static void showResult(Quaternion& inputquat) noexcept {
        inputquat.printquaternion();
    }

    inline static void showResult(const Vector4& inputvctr) noexcept {
        Vector4::showResult(inputvctr);
    }

    template <typename objtype>
    inline constexpr float dotproduct(objtype inputvctr) const noexcept {
        constexpr const bool is_4D = std::is_same<objtype, Quaternion>::value
                                  || std::is_same<objtype, Vector4>::value;
        constexpr const bool is_3D = std::is_same<objtype, Vector3>::value;
        constexpr const bool is_2D = std::is_same<objtype, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "\nERROR: float dotproduct<ARG>(ARG) function argument must be a Quaternion[default], Vector4, or Vector3 object\nwith <Vector4>[default] or <Vector3> template argument specification for Quaternion function argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (is_4D) {
            return (x * inputvctr.x) 
                +(y * inputvctr.y) 
                +(z * inputvctr.z) 
                +(w * inputvctr.w);
        }
        else if constexpr (is_3D) {
            return (x * inputvctr.x) 
                +(y * inputvctr.y) 
                +(z * inputvctr.z);
        }
        else if constexpr (is_2D) {
            return (x * inputvctr.x)
                +(y * inputvctr.y);
        }
        else {
            std::cerr << "ERROR: float dotproduct<ARG>(ARG) function argument must be a Quaternion[default], Vector4, or Vector3 object\nwith <Vector4>[default] or <Vector3> template argument specification for Quaternion function argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return INT_MIN;
        }
    }

    template <class objtype = Vector4>
    inline constexpr float magnitude() const noexcept {
        constexpr const bool is_4D = std::is_same<objtype, Quaternion>::value
                                  || std::is_same<objtype, Vector4>::value;
        constexpr const bool is_3D = std::is_same<objtype, Vector3>::value;
        constexpr const bool is_2D = std::is_same<objtype, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "\nERROR: float magnitude<ARG>() template argument must be <Quaternion>[default], <Vector4>, <Vector3>, or <Vector2> specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (is_4D) {
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
        }
        else if constexpr (is_3D) {
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        }
        else if constexpr (is_2D) {
            return sqrt(pow(x, 2) + pow(y, w));
        }
        else {
            std::cerr << "ERROR: float magnitude<ARG>() template argument must be <Quaternion>[default], <Vector4>, or <Vector3> specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return INT_MIN;
        }
    }

    template <typename objtype>
    inline constexpr float angle(const objtype& inputobj) const noexcept {
        constexpr const bool is_4D = std::is_same<objtype, Quaternion>::value
                                  || std::is_same<objtype, Vector4>::value;
        constexpr const bool is_3D = std::is_same<objtype, Vector3>::value;
        constexpr const bool is_2D = std::is_same<objtype, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "\nERROR: float angle<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object\nwith <Quaternion>[default], <Vector4>, or <Vector3> template argument specifications for Quaternion function argument inputs\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (is_4D){
            return acos(this->dotproduct<Vector4>(inputobj) / this->magnitude<Vector4>() * inputobj.magnitude());
        }
        else if constexpr (is_3D) {
            return acos(this->dotproduct<Vector3>(inputobj) / this->magnitude<Vector2>() * inputobj.magnitude());
        }
        else if constexpr (is_2D) {
            return acos(this->dotproduct<Vector2>(inputobj) / (this->magnitude<Vector2>() * inputobj.magnitude())) * (180 / PI);
        }
        else {
            std::cerr << "ERROR: float angle<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object\nwith <Quaternion>[default], <Vector4>, or <Vector3> template argument specifications for Quaternion function argument inputs\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return INT_MIN;
        }
    }

    template <typename objtype>
    inline constexpr Vector4 unitvector() const noexcept {
        constexpr const bool is_4D = std::is_same<objtype, Quaternion>::value
                                  || std::is_same<objtype, Vector4>::value;
        constexpr const bool is_3D = std::is_same<objtype, Vector3>::value;
        constexpr const bool is_2D = std::is_same<objtype, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "ERROR: Vector4 unitvector<ARG>() template argument must be explicitly defined\nwith <Quaternion>, <Vector4>, or <Vector3> argument specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib");

        if constexpr (is_4D) {
            const float denominator = this->magnitude();
            return Vector4 {
                x/denominator,
                y/denominator,
                z/denominator,
                w/denominator
            };
        }
        else if constexpr (is_3D) {
            const float denominator = this->magnitude<Vector3>();
            return Vector4 {
                x/denominator,
                y/denominator,
                z/denominator,
                w
            };
        }
        else if constexpr (is_2D) {
            const float denominator = this->magnitude<Vector2>();
            return Vector4 {
                x/denominator,
                y/denominator,
                z,
                w
            };
        }
        else {
            std::cerr << "ERROR: Vector4 unitvector<ARG>() template argument must be explicitly defined\nwith <Quaternion>, <Vector4>, or <Vector3> argument specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    inline Quaternion unitquaternion() const noexcept {
        return unitvector<Vector4>();
    }

    inline Quaternion conjugate() const noexcept {
        return {-x, -y, -z, w};
    }

    template <typename objtype = Vector4>
    inline constexpr Quaternion inverse() const noexcept {
        constexpr const bool is_4D = std::is_same<objtype, Quaternion>::value
                                  || std::is_same<objtype, Vector4>::value;
        constexpr const bool is_3D = std::is_same<objtype, Vector3>::value;
        constexpr const bool is_2D = std::is_same<objtype, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "ERROR: Quaternion inverse<ARG>() template arguments must be <Quaternion>[default], <Vector4> or <Vector3> specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        float denominator = (x*x) + (y*y) + (z*z) + (w*w);
        if constexpr (is_4D) {
            return Quaternion {
                -x/denominator,
                -y/denominator,
                -z/denominator,
                w/denominator
            };
        }
        else if constexpr (is_3D) {
            return Quaternion {
                -x/denominator,
                -y/denominator,
                -z/denominator,
                w
            };
        }
        else if constexpr (is_2D) {
            return Quaternion {
                -x/denominator,
                -y/denominator,
                -z,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion inverse<ARG>() template arguments must be <Quaternion>[default], <Vector4> or <Vector3> specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    template <typename objtype>
    inline constexpr Quaternion resultant(const objtype& inputvctr) const noexcept {
        constexpr const bool is_4D = std::is_same<objtype, Quaternion>::value
                                  || std::is_same<objtype, Vector4>::value;
        constexpr const bool is_3D = std::is_same<objtype, Vector3>::value;
        constexpr const bool is_2D = std::is_same<objtype, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "ERROR: Quaternion resultant<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object\nwith <Vector4>[default] or <Vector3> template argument specification for Quaternion function argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (is_4D) {
            return Quaternion {
                x + inputvctr.x,
                y + inputvctr.y,
                z + inputvctr.z,
                w + inputvctr.w
            };
        }
        else if constexpr (is_3D) {
            return Quaternion {
                x + inputvctr.x,
                y + inputvctr.y,
                z + inputvctr.z,
                w
            };
        }
        else if constexpr (is_2D) {
            return Quaternion {
                x + inputvctr.x,
                y + inputvctr.y,
                z,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion resultant<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object\nwith <Vector4>[default] or <Vector3> template argument specification for Quaternion function argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    template <typename objtype>
    inline constexpr Quaternion add(const objtype& inputvctr) const noexcept {
        constexpr const bool is_4D = std::is_same<objtype, Quaternion>::value
                                  || std::is_same<objtype, Vector4>::value;
        constexpr const bool is_3D = std::is_same<objtype, Vector3>::value;
        constexpr const bool is_2D = std::is_same<objtype, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "ERROR: Quaternion add<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object type\nwith <Quaternion>, <Vector4>, or <Vector3> template argument specification for Quaterinon function argument\nFor reference documentation please visit the Main.cpp file in https:://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (is_4D) {
            return Quaternion {
                x + inputvctr.x,
                y + inputvctr.y,
                z + inputvctr.z,
                w + inputvctr.w
            };
        }
        else if constexpr (is_3D) {
            return Quaternion {
                x + inputvctr.x,
                y + inputvctr.y,
                z + inputvctr.z,
                w
            };
        }
        else if constexpr (is_2D) {
            return Quaternion {
                x + inputvctr.x,
                y + inputvctr.y,
                z,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion add<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object type\nwith <Quaternion>, <Vector4>, or <Vector3> template argument specification for Quaterinon function argument\nFor reference documentation please visit the Main.cpp file in https:://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    template <typename objtype>
    inline constexpr Quaternion subtract(const objtype& inputvctr) const noexcept {
        constexpr const bool is_4D = std::is_same<objtype, Quaternion>::value
                                  || std::is_same<objtype, Vector4>::value;
        constexpr const bool is_3D = std::is_same<objtype, Vector3>::value;
        constexpr const bool is_2D = std::is_same<objtype, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "ERROR: Quaternion subtract<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object type\nwith <Quaternion>, <Vector4>, or <Vector3> template argument specification for Quaterinon function argument\nFor reference documentation please visit the Main.cpp file in https:://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (is_4D) {
            return Quaternion {
                x - inputvctr.x,
                y - inputvctr.y,
                z - inputvctr.z,
                w - inputvctr.w
            };
        }
        else if constexpr (is_3D) {
            return Quaternion {
                x - inputvctr.x,
                y - inputvctr.y,
                z - inputvctr.z,
                w
            };
        }
        else if constexpr (is_2D) {
            return Quaternion {
                x - inputvctr.x,
                y - inputvctr.y,
                z,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion subtract<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object type\nwith <Quaternion>, <Vector4>, or <Vector3> template argument specification for Quaterinon function argument\nFor reference documentation please visit the Main.cpp file in https:://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    template <class objtype = Vector4>
    inline constexpr Quaternion scalef(const float& scale) const noexcept {
        constexpr const bool is_4D = std::is_same<objtype, Quaternion>::value
                                  || std::is_same<objtype, Vector4>::value;
        constexpr const bool is_3D = std::is_same<objtype, Vector3>::value;
        constexpr const bool is_2D = std::is_same<objtype, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "ERROR: Quaternion scale<ARG>(ARG) function argument only accepts float numeric values, Matrix4x4, or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paired with (Matrix3x3) argument or <Vector4> paired with (Matrix4x4) argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (is_4D) {
            return Quaternion {
                x * scale,
                y * scale,
                z * scale,
                w * scale
            };
        }
        else if constexpr (is_3D) {
            return Quaternion {
                x * scale,
                y * scale,
                z * scale,
                w
            };
        }
        else if constexpr (is_2D) {
            return Quaternion {
                x * scale,
                y * scale,
                z,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion scale<ARG>(ARG) function argument only accepts float numeric values, Matrix4x4, or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paired with (Matrix3x3) argument or <Vector4> paired with (Matrix4x4) argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return Vector4{INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    template <class objtype = Vector4>
    inline constexpr Quaternion scale(const float& scale) const noexcept {
        constexpr const bool is_4D = std::is_same<objtype, Quaternion>::value
                                  || std::is_same<objtype, Vector4>::value;
        constexpr const bool is_3D = std::is_same<objtype, Vector3>::value;
        constexpr const bool is_2D = std::is_same<objtype, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "ERROR: Quaternion scale<ARG>(ARG) function argument only accepts float numeric values, Matrix4x4, or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paired with (Matrix3x3) argument or <Vector4> paired with (Matrix4x4) argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (is_4D){
            return Quaternion {
                x * scale,
                y * scale,
                z * scale,
                w * scale
            };
        }
        else if constexpr (is_3D){
            return Quaternion {
                x * scale,
                y * scale,
                z * scale,
                w
            };
        }
        else if constexpr (is_2D) {
            return Quaternion {
                x * scale,
                y * scale,
                z,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion scale<ARG>(ARG) function argument only accepts float numeric values, Matrix4x4, or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paired with (Matrix3x3) argument or <Vector4> paired with (Matrix4x4) argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    template <class vectorobj = Vector4, class matrixobj = Matrix4x4>
    inline constexpr Quaternion scale(const matrixobj& inputmtrx) const noexcept {
        constexpr const bool is_4D = (std::is_same<vectorobj, Quaternion>::value
                                  || std::is_same<vectorobj, Vector4>::value)
                                  && std::is_same<matrixobj, Matrix4x4>::value;
        constexpr const bool is_3D = std::is_same<vectorobj, Vector3>::value
                                  && std::is_same<matrixobj, Matrix3x3>::value;
        constexpr const bool is_2D = std::is_same<vectorobj, Vector2>::value
                                  && std::is_same<matrixobj, Matrix2x2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "ERROR: Quaternion scale<ARG>(ARG) function argument only accepts float numeric values, Matrix4x4, or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paired with (Matrix3x3) argument or <Vector4> paired with (Matrix4x4) argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (is_4D){
            return Quaternion {
                x * inputmtrx.matrix[0][0],
                y * inputmtrx.matrix[1][1],
                z * inputmtrx.matrix[2][2],
                w * inputmtrx.matrix[3][3]
            };
        }
        else if constexpr (is_3D){
            return Quaternion {
                x * inputmtrx.matrix[0][0],
                y * inputmtrx.matrix[1][1],
                z * inputmtrx.matrix[2][2],
                w
            };
        }
        else if constexpr (is_2D) {
            return Quaternion {
                x * inputmtrx.matrix[0][0],
                y * inputmtrx.matrix[1][1],
                z,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion scale<ARG>(ARG) function argument only accepts float numeric values, Matrix4x4, or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paired with (Matrix3x3) argument or <Vector4> paired with (Matrix4x4) argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    //	Vector4 rotate(Matrix4x4 inputmtrx) { // not functioning correctly, mathematics is probably incorrect
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
    //	Vector4 test_rotate(Matrix4x4 inputmtrx) { // not functioning correctly, mathematics is probably incorrect
    //		Vector4 resultVector;
    //		resultVector.x = (inputmtrx.matrix[0][0] * x) + (inputmtrx.matrix[0][1] * y) + (inputmtrx.matrix[0][2] * z);
    //		resultVector.y = (inputmtrx.matrix[1][0] * x) + (inputmtrx.matrix[1][1] * y) + (inputmtrx.matrix[1][2] * z);
    //		resultVector.z = (inputmtrx.matrix[2][0] * x) + (inputmtrx.matrix[2][1] * y) + (inputmtrx.matrix[2][2] * z);
    //		resultVector.w = w;
    //		return resultVector;
    //	}

    template <class vectorobj = Vector4, class matrixobj = Matrix4x4> 
    inline constexpr Vector4 translate(const matrixobj& inputmtrx) const noexcept {
        constexpr const bool is_4D = (std::is_same<vectorobj, Quaternion>::value
                                  || std::is_same<vectorobj, Vector4>::value)
                                  && std::is_same<matrixobj, Matrix4x4>::value;
        constexpr const bool is_3D = std::is_same<vectorobj, Vector3>::value
                                  && std::is_same<matrixobj, Matrix3x3>::value;
        constexpr const bool is_2D = std::is_same<vectorobj, Vector2>::value
                                  && std::is_same<matrixobj, Matrix2x2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "ERROR: Quaternion translate<ARG>(ARG) function argument only accepts Matrix4x4 or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paaired with (Matrix3x3) argument or <Vector4> paired with Matrix4x4 argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib");

        if constexpr (is_4D) {
            return Quaternion {
                x + inputmtrx.matrix[0][3],
                y + inputmtrx.matrix[1][3],
                z + inputmtrx.matrix[2][3],
                w + inputmtrx.matrix[3][3]
            };
        }
        else if constexpr (is_3D) {
            return Quaternion {
                x + inputmtrx.matrix[0][2],
                y + inputmtrx.matrix[1][2],
                z + inputmtrx.matrix[2][2],
                w
            };
        }
        else if constexpr (is_2D) {
            return Quaternion {
                x + inputmtrx.matrix[0][2],
                y + inputmtrx.matrix[1][2],
                z,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion translate<ARG>(ARG) function argument only accepts Matrix4x4 or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paaired with (Matrix3x3) argument or <Vector4> paired with Matrix4x4 argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    template <class objtype = Vector4>
    inline constexpr Quaternion crossproduct(const Quaternion& inputquat) const noexcept {
        constexpr const bool is_4D = std::is_same<objtype, Quaternion>::value
                                  || std::is_same<objtype, Vector4>::value;
        constexpr const bool is_3D = std::is_same<objtype, Vector3>::value;
        constexpr const bool is_2D = std::is_same<objtype, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                   "Quaternion crossproduct<ARG>(Quaternion) accepts Quaternion function arguments with a specified <Vector4>[default] or <Vector3> template specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib");
        if constexpr (is_4D) {
            return Quaternion { Vector3(this->x,this->y,this->z).crossproduct(Vector3(inputquat.x, inputquat.y, inputquat.z))};
        }
        else if constexpr (is_3D) {
            return Quaternion { Vector3(this->x,this->y,this->z).crossproduct(Vector3(inputquat.x, inputquat.y, inputquat.z))};
        }
        else if constexpr (is_2D) {
            return Quaternion {Vector2(x, y).crossproduct(Vector2(inputquat.x, inputquat.y))};
        }
        else {
            std::cerr << "Quaternion crossproduct<ARG>(Quaternion) accepts Quaternion function arguments with a specified <Vector4>[default] or <Vector3> template specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    template <class vectordimension = Vector4>
    inline constexpr vectordimension crossproduct(const vectordimension& inputvctr) const noexcept {
        constexpr const bool is_4D = std::is_same<vectordimension, Vector4>::value;
        constexpr const bool is_3D = std::is_same<vectordimension, Vector3>::value;
        constexpr const bool is_2D = std::is_same<vectordimension, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "Quaternion crossproduct<ARG>(ARG) accepts (Quaternion), (Vector4), or (Vector3) function arguments with a specified <Vector4>[default] or <Vector3> template specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib");

        if constexpr (is_4D) {
            Vector3 Vprime_local = {x, y, z};
            Vector3 Vprime_input = {inputvctr.x, inputvctr.y, inputvctr.z};
            Vector3 Vprime_result = Vprime_local.crossproduct(Vprime_input);
            return vectordimension {Vprime_result.x, Vprime_result.y, Vprime_result.z, w};
        }
        else if constexpr (is_3D) {
            Vector3 quaternionVector_local = {x, y, z};
            return quaternionVector_local.crossproduct(inputvctr);
        }
        else if constexpr (is_2D) {
            Vector2 quaternionVector_local = {x, y};
            return quaternionVector_local.crossproduct(inputvctr);
        }
        else {
            std::cerr << "input_vector_type crossproduct<ARG>(ARG) accepts (Quaternion), (Vector4), or (Vector3) function arguments with a specified <Vector4>[default] or <Vector3> template specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN};
        }
    }

    template <class vectordimension = Vector4>
    inline constexpr Quaternion multiply(const Quaternion& inputvctr) const noexcept {
        constexpr const bool is_4D = std::is_same<vectordimension, Quaternion>::value
                                  || std::is_same<vectordimension, Vector4>::value;
        constexpr const bool is_3D = std::is_same<vectordimension, Vector3>::value;
        constexpr const bool is_2D = std::is_same<vectordimension, Vector2>::value;
        static_assert(
                is_4D || is_3D || is_2D,
                "Quaternion multiply<ARG>(Quaternion) accepts (Quaternion) as a function argument with a specified <Vector4>[default] or <Vector3> template specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib");

        if constexpr (is_4D) {
            return Quaternion {
                w*inputvctr.x + x*inputvctr.w + y*inputvctr.z - z*inputvctr.y,
                w*inputvctr.y - x*inputvctr.z + y*inputvctr.w + z*inputvctr.x,
                w*inputvctr.z + x*inputvctr.y - y*inputvctr.x + z*inputvctr.w,
                w*inputvctr.w - x*inputvctr.x - y*inputvctr.y - z*inputvctr.z
            };
        }
        else if constexpr (is_3D) {
            return Quaternion {
                w*inputvctr.x + x*inputvctr.w + y*inputvctr.z - z*inputvctr.y,
                w*inputvctr.y - x*inputvctr.z + y*inputvctr.w + z*inputvctr.x,
                w*inputvctr.z + x*inputvctr.y - y*inputvctr.x + z*inputvctr.w,
                w
            };
        }
        else if constexpr (is_2D) {
            return Quaternion {
                w*inputvctr.x + x*inputvctr.w + y*inputvctr.z - z*inputvctr.y,
                w*inputvctr.y - x*inputvctr.z + y*inputvctr.w + z*inputvctr.x,
                z,
                w
            };
        }
        else {
            std::cerr << "Quaternion multiply<ARG>(Quaternion) accepts (Quaternion) as a function argument with a specified <Vector4>[default] or <Vector3> template specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN};
        }
    }

    inline constexpr Quaternion operator*(const Matrix4x4& right) const noexcept {
        Quaternion resultVector;
        float local_vector_array[4] = {x, y, z, w};
        float result_vector_array[4] = {0, 0, 0, 0};
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                result_vector_array[i] += right.matrix[i][j] * local_vector_array[j];
            }
        }
        return resultVector = {
            result_vector_array[0],
            result_vector_array[1],
            result_vector_array[2],
            result_vector_array[3]
        };
    }

    inline constexpr Quaternion operator*(const Vector4& right) const noexcept {
        return crossproduct<Vector4>(right);
    }

    inline constexpr Quaternion& operator*=(const Vector4& right) noexcept {
        return *this = crossproduct<Vector4>(right);
    }

    inline constexpr Quaternion operator+(const Vector4& right) const noexcept {
        return add<Quaternion>(right);
    }

    inline constexpr Quaternion& operator+=(const Vector4& right) noexcept {
        return *this = add<Quaternion>(right);
    }

    inline constexpr Quaternion operator-(const Vector4& right) const noexcept {
        return subtract<Quaternion>(right);
    }

    inline constexpr Quaternion& operator-=(const Vector4& right) noexcept {
        return *this = subtract<Quaternion>(right);
    }

    inline constexpr Quaternion operator^(const float& power) const noexcept {
        if (power == -1) {
            return inverse();
        }
        return {
            static_cast<float>(pow(x, power)),
            static_cast<float>(pow(y, power)),
            static_cast<float>(pow(z, power)),
            static_cast<float>(pow(w, power))
        };
    }
};
