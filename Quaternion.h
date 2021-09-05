// Header + Implementation file for Quaternion object
// Templated functions must reside in Header file, therefore there is no .cpp Implementation file like the other files in this library
#pragma once
#include <iostream>
#include "Vector4.h"
#include "Vector3.h"
#include "../MatrixFiles/Matrix4x4.h"
#include "../MatrixFiles/Matrix3x3.h"
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342
#define INT_MIN -2147483648
#define INT_MAX  2147483647

class Quaternion : public Vector4 {
public:
    Quaternion() = default;
    Quaternion(const float a, const float b, const float c, const float d) : Vector4(a, b, c, d) {};
    Quaternion(const float a, const float b, const float c) : Vector4(a, b, c) {};
    Quaternion(const float a, const float b) : Vector4(a, b) {};
    Quaternion(const float a) : Vector4(a) {};
    Quaternion(const Vector4& Vector_4D) : Quaternion(Vector_4D.x, Vector_4D.y, Vector_4D.z, Vector_4D.w) {};

    template <typename numerictype = float>
    Quaternion& operator<<(const numerictype Real) {
        static_assert(std::is_same<numerictype, float>::value 
                || std::is_same<numerictype, double>::value 
                || std::is_same<numerictype, int>::value, 
                "'<<' operator should only be used with [int], [double], or [float] values for assignment of W/Real");

        w = static_cast<float>(Real);
        return *this;
    }

    Quaternion& operator<<(const Vector4& Vprime) { return *this = {Vprime.x, Vprime.y, Vprime.z, Vprime.w}; }
    
    Quaternion& operator<<(const Vector3& Vprime) { return *this = {Vprime.x, Vprime.y, Vprime.z, w}; }

    static void input(Vector4 &inputvctr) { 
        std::cin >> inputvctr.x >> inputvctr.y >> inputvctr.z >> inputvctr.w;
    }

    void printquaternion() {
        std::cout << '[' << w;
        if (x >= 0) { std::cout << " + " << x << 'i'; }
        else { std::cout << " - " << -x << 'i'; }

        if (y >= 0) { std::cout << " + " << y << 'j'; }
        else { std::cout << " - " << -y << 'j'; }

        if (z >= 0) { std::cout << " + " << z << 'k'; }
        else { std::cout << " - " << -z << 'k'; }
        std::cout << ']' << std::endl;
    }

    template <typename TYPE>
    static void showResult(TYPE input) {
        std::cout << input << '\n';
    }

    // TODO: check if you can allow to be templated function for quat obj to be printed as Vec4 or Quat
    static void showResult(Quaternion inputquat) {
        inputquat.printquaternion();
    }

    static void showResult(Vector4 inputvctr) {
        Vector4::showResult(inputvctr);
    }

    // Ready for GitHub
    template <typename objtype>
    float dotproduct(objtype inputvctr) {
        static_assert(std::is_same<objtype, Quaternion>::value
                || std::is_same<objtype, Vector4>::value 
                || std::is_same<objtype, Vector3>::value, 
                "\nERROR: float dotproduct<ARG>(ARG) function argument must be a Quaternion[default], Vector4, or Vector3 object\nwith <Vector4>[default] or <Vector3> template argument specification for Quaternion function argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (std::is_same<objtype, Quaternion>::value || std::is_same<objtype, Vector4>::value) {
            return (x * inputvctr.x) 
                +(y * inputvctr.y) 
                +(z * inputvctr.z) 
                +(w * inputvctr.w);
        }
        else if constexpr (std::is_same<objtype, Vector3>::value) {
            return (x * inputvctr.x) 
                +(y * inputvctr.y) 
                +(z * inputvctr.z);
        }
        else {
            std::cerr << "ERROR: float dotproduct<ARG>(ARG) function argument must be a Quaternion[default], Vector4, or Vector3 object\nwith <Vector4>[default] or <Vector3> template argument specification for Quaternion function argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return INT_MIN;
        }
    }

    // Ready for GitHub
    template <class objtype = Vector4>
    float magnitude() {
        static_assert(std::is_same<objtype, Quaternion>::value
                || std::is_same<objtype, Vector4>::value
                || std::is_same<objtype, Vector3>::value, 
                "\nERROR: float magnitude<ARG>() template argument must be <Quaternion>[default], <Vector4>, or <Vector3> specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (std::is_same<objtype, Quaternion>::value || std::is_same<objtype, Vector4>::value) {
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
        }
        else if constexpr (std::is_same<objtype, Vector3>::value) {
            return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        }
        else {
            std::cerr << "ERROR: float magnitude<ARG>() template argument must be <Quaternion>[default], <Vector4>, or <Vector3> specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return INT_MIN;
        }
    }

    // Ready for GitHub
    template <typename objtype>
    float angle(objtype inputobj) {
        static_assert(std::is_same<objtype, Quaternion>::value
                || std::is_same<objtype, Vector4>::value 
                || std::is_same<objtype, Vector3>::value, 
                "\nERROR: float angle<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object\nwith <Quaternion>[default], <Vector4>, or <Vector3> template argument specifications for Quaternion function argument inputs\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (std::is_same<objtype, Quaternion>::value || std::is_same<objtype, Vector4>::value){
            float Product = dotproduct(inputobj);
            float Magnitude = magnitude() * inputobj.magnitude();
            return acos(Product / Magnitude) * (180 / PI);
        }
        else if constexpr (std::is_same<objtype, Vector3>::value) {
            float Product = dotproduct<Vector3>(inputobj);
            float Magnitude = magnitude<Vector3>() * inputobj.magnitude(); 
            return acos(Product / Magnitude) * (180 / PI);
        }
        else {
            std::cerr << "ERROR: float angle<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object\nwith <Quaternion>[default], <Vector4>, or <Vector3> template argument specifications for Quaternion function argument inputs\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return INT_MIN;
        }
    }

    // Ready for GitHub
    template <typename objtype>
    Vector4 unitvector() { 
        Vector4 resultVector;
        static_assert(std::is_same<objtype, Quaternion>::value
                || std::is_same<objtype, Vector4>::value 
                || std::is_same<objtype, Vector3>::value, 
                "ERROR: Vector4 unitvector<ARG>() template argument must be explicitly defined\nwith <Quaternion>, <Vector4>, or <Vector3> argument specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib");

        if constexpr (std::is_same<objtype, Quaternion>::value || std::is_same<objtype, Vector4>::value) {
            float denominator = magnitude();
            return resultVector = {
                x/denominator,
                y/denominator,
                z/denominator,
                w/denominator
            };
        }
        else if constexpr (std::is_same<objtype, Vector3>::value) {
            float denominator = magnitude<Vector3>();
            return resultVector = {
                x/denominator,
                y/denominator,
                z/denominator,
                w
            };
        }
        else {
            std::cerr << "ERROR: Vector4 unitvector<ARG>() template argument must be explicitly defined\nwith <Quaternion>, <Vector4>, or <Vector3> argument specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    // Ready for GitHub
    Quaternion unitquaternion() { 
        return unitvector<Vector4>();
    }

    // Ready for GitHub
    Quaternion conjugate(){
        return {-x, -y, -z, w};
    }

    // Ready for GitHub
    template <typename objtype = Vector4>
    Quaternion inverse() { 
        Quaternion resultQuaternion;
        static_assert(std::is_same<objtype, Quaternion>::value
                || std::is_same<objtype, Vector4>::value 
                || std::is_same<objtype, Vector3>::value, 
                "ERROR: Quaternion inverse<ARG>() template arguments must be <Quaternion>[default], <Vector4> or <Vector3> specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        float denominator = pow(magnitude(), 2);

        if constexpr (std::is_same<objtype, Quaternion>::value || std::is_same<objtype, Vector4>::value){
            return resultQuaternion = {
                -x/denominator,
                -y/denominator,
                -z/denominator,
                w/denominator
            };
        }
        else if constexpr (std::is_same<objtype, Vector3>::value) {
            return resultQuaternion = {
                -x/denominator,
                -y/denominator,
                -z/denominator,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion inverse<ARG>() template arguments must be <Quaternion>[default], <Vector4> or <Vector3> specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return resultQuaternion = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    // Ready for GitHub
    template <typename objtype>
    Quaternion resultant(objtype inputvctr) {
        Quaternion resultVector;
        static_assert(std::is_same<objtype, Quaternion>::value
                || std::is_same<objtype, Vector4>::value 
                || std::is_same<objtype, Vector3>::value, 
                "ERROR: Quaternion resultant<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object\nwith <Vector4>[default] or <Vector3> template argument specification for Quaternion function argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (std::is_same<objtype, Quaternion>::value || std::is_same<objtype, Vector4>::value){
            return resultVector = {
                x + inputvctr.x,
                y + inputvctr.y,
                z + inputvctr.z,
                w + inputvctr.w
            };
        }
        else if constexpr (std::is_same<objtype, Vector3>::value){
            return resultVector = {
                x + inputvctr.x,
                y + inputvctr.y,
                z + inputvctr.z,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion resultant<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object\nwith <Vector4>[default] or <Vector3> template argument specification for Quaternion function argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return resultVector = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    // Ready for GitHub
    template <typename objtype>
    Quaternion add(objtype inputvctr) {
        Quaternion resultVector;
        static_assert(std::is_same<objtype, Quaternion>::value
                || std::is_same<objtype, Vector4>::value 
                || std::is_same<objtype, Vector3>::value, 
                "ERROR: Quaternion add<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object type\nwith <Quaternion>, <Vector4>, or <Vector3> template argument specification for Quaterinon function argument\nFor reference documentation please visit the Main.cpp file in https:://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (std::is_same<objtype, Quaternion>::value || std::is_same<objtype, Vector4>::value) {
            return resultVector = {
                x + inputvctr.x,
                y + inputvctr.y,
                z + inputvctr.z,
                w + inputvctr.w
            };
        }
        else if constexpr (std::is_same<objtype, Vector3>::value) {
            return resultVector = {
                x + inputvctr.x,
                y + inputvctr.y,
                z + inputvctr.z,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion add<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object type\nwith <Quaternion>, <Vector4>, or <Vector3> template argument specification for Quaterinon function argument\nFor reference documentation please visit the Main.cpp file in https:://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return resultVector = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    // Ready for GitHub
    template <typename objtype>
    Quaternion subtract(objtype inputvctr) {
        Quaternion resultVector;
        static_assert(std::is_same<objtype, Quaternion>::value
                || std::is_same<objtype, Vector4>::value 
                || std::is_same<objtype, Vector3>::value, 
                "ERROR: Quaternion subtract<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object type\nwith <Quaternion>, <Vector4>, or <Vector3> template argument specification for Quaterinon function argument\nFor reference documentation please visit the Main.cpp file in https:://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (std::is_same<objtype, Quaternion>::value || std::is_same<objtype, Vector4>::value) {
            return resultVector = {
                x - inputvctr.x,
                y - inputvctr.y,
                z - inputvctr.z,
                w - inputvctr.w
            };
        }
        else if constexpr (std::is_same<objtype, Vector3>::value) {
            return resultVector = {
                x - inputvctr.x,
                y - inputvctr.y,
                z - inputvctr.z,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion subtract<ARG>(ARG) function argument must be a Quaternion, Vector4, or Vector3 object type\nwith <Quaternion>, <Vector4>, or <Vector3> template argument specification for Quaterinon function argument\nFor reference documentation please visit the Main.cpp file in https:://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return resultVector = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    // Ready for GitHub
    template <class objtype = Vector4>
    Quaternion scale(float scale) {
        Quaternion resultVector;
        static_assert(std::is_same<objtype, Quaternion>::value
                || std::is_same<objtype, Vector4>::value 
                || std::is_same<objtype, Vector3>::value, 
                "ERROR: Quaternion scale<ARG>(ARG) function argument only accepts float numeric values, Matrix4x4, or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paired with (Matrix3x3) argument or <Vector4> paired with (Matrix4x4) argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr (std::is_same<objtype, Vector4>::value){
            return resultVector = {
                x * scale,
                y * scale,
                z * scale,
                w * scale
            };
        }
        else if constexpr (std::is_same<objtype, Vector3>::value){
            return resultVector = {
                x * scale,
                y * scale,
                z * scale,
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion scale<ARG>(ARG) function argument only accepts float numeric values, Matrix4x4, or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paired with (Matrix3x3) argument or <Vector4> paired with (Matrix4x4) argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return resultVector = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    // Ready for GitHub
    template <class vectorobj = Vector4, class matrixobj = Matrix4x4>
    Quaternion scale(matrixobj inputmtrx) {
        Quaternion resultVector;
        static_assert(((std::is_same<vectorobj, Quaternion>::value || std::is_same<vectorobj, Vector4>::value) && std::is_same<matrixobj, Matrix4x4>::value) 
                || (std::is_same<vectorobj, Vector3>::value && std::is_same<matrixobj, Matrix3x3>::value),
                "ERROR: Quaternion scale<ARG>(ARG) function argument only accepts float numeric values, Matrix4x4, or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paired with (Matrix3x3) argument or <Vector4> paired with (Matrix4x4) argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/");

        if constexpr ((std::is_same<vectorobj, Quaternion>::value || std::is_same<vectorobj, Vector4>::value) && std::is_same<matrixobj, Matrix4x4>::value){
            return resultVector = {
                x * inputmtrx.matrix[0][0],
                y * inputmtrx.matrix[1][1],
                z * inputmtrx.matrix[2][2],
                w * inputmtrx.matrix[3][3]
            };
        }
        else if constexpr (std::is_same<vectorobj, Vector3>::value && std::is_same<matrixobj, Matrix3x3>::value){
            return resultVector = {
                x * inputmtrx.matrix[0][0],
                y * inputmtrx.matrix[1][1],
                z * inputmtrx.matrix[2][2],
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion scale<ARG>(ARG) function argument only accepts float numeric values, Matrix4x4, or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paired with (Matrix3x3) argument or <Vector4> paired with (Matrix4x4) argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib/" << std::endl;
            return resultVector = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
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

    
    // Ready for GitHub
    template <class vectorobj = Vector4, class matrixobj = Matrix4x4> 
    Vector4 translate(matrixobj inputmtrx) {
        Vector4 resultVector;
        static_assert((std::is_same<vectorobj, Quaternion>::value || std::is_same<vectorobj, Vector4>::value) && std::is_same<matrixobj, Matrix4x4>::value 
                || std::is_same<vectorobj, Vector3>::value && std::is_same<matrixobj, Matrix3x3>::value, 
                "ERROR: Quaternion translate<ARG>(ARG) function argument only accepts Matrix4x4 or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paaired with (Matrix3x3) argument or <Vector4> paired with Matrix4x4 argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib");

        if constexpr ((std::is_same<vectorobj, Quaternion>::value || std::is_same<vectorobj, Vector4>::value) && std::is_same<matrixobj, Matrix4x4>::value) {
            return resultVector = {
                x + inputmtrx.matrix[0][3],
                y + inputmtrx.matrix[1][3],
                z + inputmtrx.matrix[2][3],
                w + inputmtrx.matrix[3][3]
            };
        }
        else if constexpr (std::is_same<vectorobj, Vector3>::value && std::is_same<matrixobj, Matrix3x3>::value){
            return resultVector = {
                x + inputmtrx.matrix[0][2],
                y + inputmtrx.matrix[1][2],
                z + inputmtrx.matrix[2][2],
                w
            };
        }
        else {
            std::cerr << "ERROR: Quaternion translate<ARG>(ARG) function argument only accepts Matrix4x4 or Matrix3x3 objects\nwith <Vector4>[default] or <Vector3> template argument specification with <Vector3> paaired with (Matrix3x3) argument or <Vector4> paired with Matrix4x4 argument\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib" << std::endl;
            return resultVector = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    // Ready for GitHub
    template <class objtype = Vector4>
    Quaternion crossproduct(Quaternion inputquat) {
        Quaternion resultQuat;
        static_assert(std::is_same<objtype, Quaternion>::value
                   || std::is_same<objtype, Vector4>::value
                   || std::is_same<objtype, Vector3>::value,
                   "Quaternion crossproduct<ARG>(Quaternion) accepts Quaternion function arguments with a specified <Vector4>[default] or <Vector3> template specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib");
        if constexpr (std::is_same<objtype, Quaternion>::value || std::is_same<objtype, Vector4>::value) {
            Vector3 Vprime_local = {x, y, z};
            Vector3 Vprime_input = {inputquat.x, inputquat.y, inputquat.z};
            Vector3 Vprime_result = Vprime_local.crossproduct(Vprime_input);
            resultQuat << Vprime_result << w;
            return resultQuat;
        }
        else if constexpr (std::is_same<objtype, Vector3>::value) {
            Vector3 Vprime_local = {x, y, z};
            Vector3 Vprime_input = {inputquat.x, inputquat.y, inputquat.z};
            Vector3 Vprime_result = Vprime_local.crossproduct(Vprime_input);
            resultQuat << Vprime_result;
            return resultQuat;
        }
        else {
            std::cerr << "Quaternion crossproduct<ARG>(Quaternion) accepts Quaternion function arguments with a specified <Vector4>[default] or <Vector3> template specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib" << std::endl;
            return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        }
    }

    // Ready for GitHub
    template <class vectordimension = Vector4>
    vectordimension crossproduct(vectordimension inputvctr) {
        vectordimension resultVector;
        static_assert(std::is_same<vectordimension, Vector4>::value 
                || std::is_same<vectordimension, Vector3>::value, 
                "Quaternion crossproduct<ARG>(ARG) accepts (Quaternion), (Vector4), or (Vector3) function arguments with a specified <Vector4>[default] or <Vector3> template specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib");

        if constexpr (std::is_same<vectordimension, Vector4>::value) {
            Vector3 Vprime_local = {x, y, z};
            Vector3 Vprime_input = {inputvctr.x, inputvctr.y, inputvctr.z};
            Vector3 Vprime_result = Vprime_local.crossproduct(Vprime_input);
            return resultVector = {Vprime_result.x, Vprime_result.y, Vprime_result.z, w};
        }
        else if constexpr (std::is_same<vectordimension, Vector3>::value) {
            Vector3 quaternionVector_local = {x, y, z};
            return resultVector = quaternionVector_local.crossproduct(inputvctr);
        }
        else {
            std::cerr << "input_vector_type crossproduct<ARG>(ARG) accepts (Quaternion), (Vector4), or (Vector3) function arguments with a specified <Vector4>[default] or <Vector3> template specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib" << std::endl;
            return resultVector = {INT_MIN, INT_MIN, INT_MIN};
        }
    }

    // Ready for GitHub
    template <class vectordimension = Vector4>
    Quaternion multiply(Quaternion inputvctr) { 
        Quaternion resultVector;
        static_assert(std::is_same<vectordimension, Quaternion>::value
                || std::is_same<vectordimension, Vector4>::value 
                || std::is_same<vectordimension, Vector3>::value, 
                "Quaternion multiply<ARG>(Quaternion) accepts (Quaternion) as a function argument with a specified <Vector4>[default] or <Vector3> template specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib");

        if constexpr (std::is_same<vectordimension, Quaternion>::value || std::is_same<vectordimension, Vector4>::value) {
            return resultVector = {
                w*inputvctr.x + x*inputvctr.w + y*inputvctr.z - z*inputvctr.y,
                w*inputvctr.y - x*inputvctr.z + y*inputvctr.w + z*inputvctr.x,
                w*inputvctr.z + x*inputvctr.y - y*inputvctr.x + z*inputvctr.w,
                w*inputvctr.w - x*inputvctr.x - y*inputvctr.y - z*inputvctr.z
            };
        }
        else if constexpr (std::is_same<vectordimension, Vector3>::value) {
            return resultVector = {
                w*inputvctr.x + x*inputvctr.w + y*inputvctr.z - z*inputvctr.y,
                w*inputvctr.y - x*inputvctr.z + y*inputvctr.w + z*inputvctr.x,
                w*inputvctr.z + x*inputvctr.y - y*inputvctr.x + z*inputvctr.w,
                w
            };
        }
        else {
            std::cerr << "Quaternion multiply<ARG>(Quaternion) accepts (Quaternion) as a function argument with a specified <Vector4>[default] or <Vector3> template specification\nFor reference documentation please visit the Main.cpp file in https://github.com/Caliikha/MatrixVectorLib" << std::endl;
            return resultVector = {INT_MIN, INT_MIN, INT_MIN};
        }
    }

    Quaternion operator*(const Matrix4x4& right) { 
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

    Quaternion operator*(const Vector4& right) {
        return crossproduct<Vector4>(right);
    }

    Quaternion& operator*=(const Vector4& right) {
        Quaternion resultVector = crossproduct<Vector4>(right);
        x = resultVector.x;
        y = resultVector.y;
        z = resultVector.z;
        w = resultVector.w;
        return *this;
    }

    Quaternion operator+(const Vector4& right) {
        return add<Quaternion>(right);
    }

    Quaternion& operator+=(const Vector4& right) {
        Vector4 resultVector = add<Quaternion>(right);
        x = resultVector.x;
        y = resultVector.y;
        z = resultVector.z;
        w = resultVector.w;
        return *this;
    }

    Quaternion operator-(const Vector4& right) {
        return subtract<Quaternion>(right);
    }

    Quaternion& operator-=(const Vector4& right) {
        Quaternion resultVector = subtract<Quaternion>(right);
        x = resultVector.x;
        y = resultVector.y;
        z = resultVector.z;
        w = resultVector.w;
        return *this;
    }

    Quaternion operator^(const float power) {
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
