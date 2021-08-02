#pragma once
#include <iostream>
#include <cmath>
#include "Matrix4x4.h"
#include "Vector3.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342
#define INT_MIN -2147483648
#define INT_MAX  2147483647

class Vector4 {
public:
	float x = 0, y = 0, z = 0, w = 0;

	static void input(Vector4 &inputvctr) {
        	std::cin >> inputvctr.x >> inputvctr.y >> inputvctr.z >> inputvctr.w;
	}

	void printvector() {
        	std::cout << '(' << x << ", " << y << ", " << z << ", " << w << ')' << '\n';
	}

	void printquaternion() {
		std::cout << '[' << w;
		if (x >= 0) {
			std::cout << " + " << x << 'i';
		}
		else {
			std::cout << " - " << -x << 'i';
		}
		
		if (y >= 0) {
			std::cout << " + " << y << 'j';
		}
		else {
			std::cout << " - " << -y << 'j';        
		}

		if (z >= 0) {
			std::cout << " + " << z << 'k';
		}
		else {
			std::cout << " - " << -z << 'k';
		}
		std::cout << ']' << '\n';    
	}

    	template <typename TYPE>
    	static void showResult(TYPE input) {
        	std::cout << input << '\n';
    	}

    	static void showResult(Vector4 inputvctr) {
        	std::cout << '(' << inputvctr.x << ", " << inputvctr.y << ", " << inputvctr.z << ", " << inputvctr.w << ')' << '\n';
    	}

    	template <typename vectordimension>
	float dotproduct(vectordimension inputvctr) {
        	static_assert(std::is_same<vectordimension, Vector4>::value || std::is_same<vectordimension, Vector3>::value, "vector input must be a Vector4 or Vector3 type");

        	if constexpr (std::is_same<vectordimension, Vector4>::value) {
            		return (x * inputvctr.x) 
                  	      +(y * inputvctr.y) 
                  	      +(z * inputvctr.z) 
                  	      +(w * inputvctr.w);
        	}
        	else if constexpr (std::is_same<vectordimension, Vector3>::value) {
            		return (x * inputvctr.x) 
                  	      +(y * inputvctr.y) 
                  	      +(z * inputvctr.z);
        	}
        	else {
            		std::cerr << "vector input must be a Vector4 or Vector3 type" << std::endl;
            		return INT_MIN;
        	}
	}

    	template <class vectordimension = Vector4>
    	float magnitude() {
        	static_assert(std::is_same<vectordimension, Vector4>::value || std::is_same<vectordimension, Vector3>::value, "associated class must be of default[Vector4] type or specified Vector3 type");

        	if constexpr (std::is_same<vectordimension, Vector4>::value) {
            		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
        	}
        	else if constexpr (std::is_same<vectordimension, Vector3>::value) {
            		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        	}
        	else {
            		std::cerr << "associated template class must be of default[Vector4] type or specified Vector3 type" << std::endl;
            		return INT_MIN;
        	}
    	}

    	template <typename vectordimension>
	float angle(vectordimension inputvctr) {
        	static_assert(std::is_same<vectordimension, Vector4>::value || std::is_same<vectordimension, Vector3>::value, "vector input must be a Vector4 or Vector3 type");

        	if constexpr (std::is_same<vectordimension, Vector4>::value){
            		float Product = dotproduct(inputvctr);
            		float Magnitude = magnitude() * inputvctr.magnitude();
            		return acos(Product / Magnitude) * (180 / PI);
        	}
        	else if constexpr (std::is_same<vectordimension, Vector3>::value) {
            		float Product = dotproduct(inputvctr);
            		float Magnitude = magnitude<Vector3>() * inputvctr.magnitude(); 
            		return acos(Product / Magnitude) * (180 / PI);
        	}
        	else {
            		std::cerr << "vector input must be a Vector4 or Vector3 type" << std::endl;
            		return INT_MIN;
        	}
	}
	    
	Vector4 conjugate(){
		Vector4 resultQuaternion;
		return resultQuaternion = {
			-x, -y, -z, w
		};
	}

    	template <typename vectordimension>
	Vector4 resultant(vectordimension inputvctr) {
		Vector4 resultVector;
        	static_assert(std::is_same<vectordimension, Vector4>::value || std::is_same<vectordimension, Vector3>::value, "vector input must be a Vector4 or Vector3 type");

        	if constexpr (std::is_same<vectordimension, Vector4>::value){
            		return resultVector = {
                		x + inputvctr.x,
                		y + inputvctr.y,
                		z + inputvctr.z,
                		w + inputvctr.w
            		};
        	}
        	else if constexpr (std::is_same<vectordimension, Vector3>::value){
            		return resultVector = {
                		x + inputvctr.x,
                		y + inputvctr.y,
                		z + inputvctr.z,
                		w
            		};
        	}
        	else {
            		std::cerr << "vector input must be a Vector4 or Vector3 type" << std::endl;
            		return resultVector = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        	}

	}

    	template <typename vectordimension = Vector4>
    	Vector4 add(vectordimension inputvctr) {
        	Vector4 resultVector;
        	static_assert(std::is_same<vectordimension, Vector4>::value || std::is_same<vectordimension, Vector3>::value, "vector input must be paired with Vector3 template specification or default Vector4 input without any specification");
        	if constexpr (std::is_same<vectordimension, Vector4>::value) {
            		return resultVector = {
                		x + inputvctr.x,
                		y + inputvctr.y,
                		z + inputvctr.z,
                		w + inputvctr.w
            		};
        	}
        	else if constexpr (std::is_same<vectordimension, Vector3>::value) {
            		return resultVector = {
                		x + inputvctr.x,
                		y + inputvctr.y,
                		z + inputvctr.z,
                		w
            		};
        	}
        	else {
            		std::cerr << "vector input must be paired with Vector3 template specification or default Vector4 input without any specification" << std::endl;
            		return resultVector = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        	}
    	}

    	template <typename vectordimension = Vector4>
    	Vector4 subtract(vectordimension inputvctr) {
        	Vector4 resultVector;
        	static_assert(std::is_same<vectordimension, Vector4>::value || std::is_same<vectordimension, Vector3>::value, "vector input must be paired with Vector3 template specification or default Vector4 input without any specification");

        	if constexpr (std::is_same<vectordimension, Vector4>::value) {
            		return resultVector = {
                		x - inputvctr.x,
                		y - inputvctr.y,
                		z - inputvctr.z,
                		w - inputvctr.w
            		};
        	}
        	else if constexpr (std::is_same<vectordimension, Vector3>::value) {
            		return resultVector = {
                		x - inputvctr.x,
                		y - inputvctr.y,
                		z - inputvctr.z,
                		w
            		};
        	}
        	else {
            		std::cerr << "vector input must be paired with Vector3 template specification or default Vector4 input without any specification" << std::endl;
            		return resultVector = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        	}
    	}

    	template <class vectordimension = Vector4>
	Vector4 scale(float scale) {
		Vector4 resultVector;
        	static_assert(std::is_same<vectordimension, Vector4>::value || std::is_same<vectordimension, Vector3>::value, "vector input must be a Vector4 or Vector3 type");

        	if constexpr (std::is_same<vectordimension, Vector4>::value){
            		return resultVector = {
                		x * scale,
                		y * scale,
                		z * scale,
                		w * scale
            		};
        	}
        	else if constexpr (std::is_same<vectordimension, Vector3>::value){
            		return resultVector = {
                		x * scale,
                		y * scale,
                		z * scale,
                		w
            		};
        	}
        	else {
            		std::cerr << "vector input must be a Vector4 or Vector3 type" << std::endl;
            		return resultVector = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        	}
	}

    	template <class vectordimension = Vector4, class matrixdimension = Matrix4x4>
	Vector4 scale(matrixdimension inputmtrx) {
		Vector4 resultVector;
        	static_assert((std::is_same<vectordimension, Vector4>::value && std::is_same<matrixdimension, Matrix4x4>::value) || (std::is_same<vectordimension, Vector3>::value && std::is_same<matrixdimension, Matrix3x3>::value),"inputs must have a Vector4 paired with Matrix4x4 type [OR] a Vector3 paired with Matrix3x3 type");
        
        	if constexpr (std::is_same<vectordimension, Vector4>::value && std::is_same<matrixdimension, Matrix4x4>::value){
            		return resultVector = {
                		x * inputmtrx.matrix[0][0],
                		y * inputmtrx.matrix[1][1],
                		z * inputmtrx.matrix[2][2],
                		w * inputmtrx.matrix[3][3]
            		};
        	}
        	else if constexpr (std::is_same<vectordimension, Vector3>::value && std::is_same<matrixdimension, Matrix3x3>::value){
            		return resultVector = {
                		x * inputmtrx.matrix[0][0],
                		y * inputmtrx.matrix[1][1],
                		z * inputmtrx.matrix[2][2],
                		w
            		};
        	}
        	else {
            		std::cerr << "inputs must have a Vector4 paired with Matrix4x4 type [OR] a Vector3 paired with Matrix3x3 type" << std::endl;
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

    	template <class vectordimension = Vector4, class matrixdimension = Matrix4x4> 
	Vector4 translate(matrixdimension inputmtrx) {
		Vector4 resultVector;
        	static_assert(std::is_same<vectordimension, Vector4>::value && std::is_same<matrixdimension, Matrix4x4>::value || std::is_same<vectordimension, Vector3>::value && std::is_same<matrixdimension, Matrix3x3>::value, "inputs must have a Vector4 paired with Matrix4x4 type [OR] a Vector3 paired with Matrix3x3 type");

        	if constexpr (std::is_same<vectordimension, Vector4>::value && std::is_same<matrixdimension, Matrix4x4>::value) {
            		return resultVector = {
                		x + inputmtrx.matrix[0][3],
                		y + inputmtrx.matrix[1][3],
                		z + inputmtrx.matrix[2][3],
                		w + inputmtrx.matrix[3][3]
            		};
        	}
        	else if constexpr (std::is_same<vectordimension, Vector3>::value && std::is_same<matrixdimension, Matrix3x3>::value){
            		return resultVector = {
                		x + inputmtrx.matrix[0][2],
                		y + inputmtrx.matrix[1][2],
                		z + inputmtrx.matrix[2][2],
                		w
            		};
        	}
        	else {
            		std::cerr << "inputs must have a Vector4 paired with Matrix4x4 type [OR] a Vector3 paired with Matrix3x3 type" << std::endl;
            		return resultVector = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        	}
	}

    
	template <class vectordimension = Vector4>
	vectordimension crossproduct(vectordimension inputvctr) {
		vectordimension resultVector;
		static_assert(std::is_same<vectordimension, Vector4>::value || std::is_same<vectordimension, Vector3>::value, "template argument must be the same as function argument input. && input must be of either Vector3 or Vector4 type");
		if constexpr (std::is_same<vectordimension, Vector4>::value) {
			Vector3 quaternionVector_local = {x, y, z};
			Vector3 quaternionVector_input = {inputvctr.x, inputvctr.y, inputvctr.z};
			Vector3 resultVector_3D = quaternionVector_local.crossproduct(quaternionVector_input);
			return resultVector = {resultVector_3D.x, resultVector_3D.y, resultVector_3D.z, w};
		}
		else if constexpr (std::is_same<vectordimension, Vector3>::value) {
			Vector3 quaternionVector_local = {x, y, z};
			return resultVector = quaternionVector_local.crossproduct(inputvctr);
		}
		else {
			std::cerr << "template argument must be the same as function argument input && input must be of either Vector3 or Vector4 type" << std::endl;
			return resultVector = {INT_MIN, INT_MIN, INT_MIN};
		}
	}
	    
	template <class vectordimension = Vector4>    
	Vector4 multiply(Vector4 inputvctr) {        
		Vector4 resultVector;        
		static_assert(std::is_same<vectordimension, Vector4>::value || std::is_same<vectordimension, Vector3>::value, "class specification must be of Vector3 or Vector4[default] type");
		        
		if constexpr (std::is_same<vectordimension, Vector4>::value) {            
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
			std::cerr << "Class specification must be of Vector3 or Vector4[default] type" << std::endl;
			return resultVector = {INT_MIN, INT_MIN, INT_MIN};        
		}    
	}
};
