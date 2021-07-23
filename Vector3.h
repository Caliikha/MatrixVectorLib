#pragma once
#include <iostream>
#include <cmath>
#include "../MatrixFiles/Matrix3x3.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

class Vector3 {
public:
	float x = 0, y = 0, z = 0;

	static void input(Vector3 inputvctr) {
		std::cin >> inputvctr.x >> inputvctr.y >> inputvctr.z;
	}

	void printvector() {
        	std::cout << '(' << x << ", " << y << ", " << z << ')' << '\n';
	}

	template <typename TYPE>
	static void showResult(TYPE input) {
		std::cout << input << '\n';
	}

	static void showResult(Vector3 inputvctr) {
        	std::cout << '(' << inputvctr.x << ", " << inputvctr.y << ", " << inputvctr.z << ')' << '\n';
	}

	float dotproduct(Vector3 inputvctr) {
		return (x * inputvctr.x) 
              	      +(y * inputvctr.y) 
              	      +(z * inputvctr.z);
	}

    	float magnitude() {
        	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    	}

	float angle(Vector3 inputvctr) {
		float Product = dotproduct(inputvctr);
		float Magnitude = magnitude() * inputvctr.magnitude();
		return acos(Product / Magnitude) * (180 / PI);
	}

	Vector3 resultant(Vector3 inputvctr) {
		Vector3 resultVector;
		return resultVector = {
            		x + inputvctr.x, 
            		y + inputvctr.y, 
            		z + inputvctr.z
        	};
	}

	Vector3 add(Vector3 inputvctr) { 
		Vector3 resultVector;
		return resultVector = {
            		x + inputvctr.x, 
            		y + inputvctr.y, 
            		z + inputvctr.z
        	};
	}

	Vector3 subtract(Vector3 inputvctr) { 
		Vector3 resultVector;
		return resultVector = {
            		x - inputvctr.x, 
            		y - inputvctr.y, 
            		z - inputvctr.z
        	};
	}

	Vector3 scale(float scale) {
		Vector3 resultVector;
        	return resultVector = {
            		x * scale,
            		y * scale,
            		z * scale
        	};
	}

	Vector3 scale(Matrix3x3 inputmtrx) {
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

    	Vector3 translate(Matrix3x3 inputmtrx){
        	Vector3 resultVector;
        	return resultVector = {
            		x + inputmtrx.matrix[0][2],
            		y + inputmtrx.matrix[1][2],
            		z + inputmtrx.matrix[2][2]
        	};
    	}

//    Vector3 crossproduct(Vector3 inputvctr){
        // TODO
//    }
};
