#pragma once
#include <iostream>
#include <cmath>
#include "Matrix2x2.h"
#include "Vector3.h" 
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

class Vector2 {
public:
	float x = 0, y = 0;

	static void input(Vector2 &inputvctr) {
		std::cin >> inputvctr.x >> inputvctr.y;
	}

	void printvector() {
		std::cout << "(" << x << ", " << y << ")" << '\n';
	}

	template <typename TYPE>
	static void showResult(TYPE input) {
		std::cout << input << '\n';
	}

	static void showResult(Vector2 inputvctr) {
        	std::cout << '(' << inputvctr.x << ", " << inputvctr.y << ')' << '\n';
	}

	float dotproduct(Vector2 inputvctr) {
		return (x * inputvctr.x) + (y * inputvctr.y);
	}

    	float magnitude() {
        	return sqrt(pow(x, 2) + pow(y, 2));
    	}

	float angle(Vector2 inputvctr) {
		float Product = dotproduct(inputvctr);
		float Magnitude = magnitude() * inputvctr.magnitude();
		return acos(Product / Magnitude) * (180 / PI);
	}

	Vector2 unitvector() {
		Vector2 resultVector;
		float denominator = magnitude();
		return resultVector = {
			x/denominator,
			y/denominator
		};
	}
	
	Vector2 resultant(Vector2 inputvctr) {
		Vector2 resultVector;
		return resultVector = {x + inputvctr.x, y + inputvctr.y};
	}

	Vector2 add(Vector2 inputvctr) { 
		Vector2 resultVector;
		return resultVector = {x + inputvctr.x, y + inputvctr.y};
	}

	Vector2 subtract(Vector2 inputvctr) { 
		Vector2 resultVector;
		return resultVector = { x - inputvctr.x, y - inputvctr.y};
	}

	Vector2 scale(float scale) {
		Vector2 resultVector;
            	return resultVector = {x * scale, y * scale};
	}

    	Vector2 scale(Matrix2x2 inputmtrx) {
        	Vector2 resultVector;
        	return resultVector = {
            		x * inputmtrx.matrix[0][0],
            		y * inputmtrx.matrix[1][1]
        	};
    	}

	Vector2 rotate(Matrix2x2 inputmtrx) { 
		Vector2 resultVector;
		return resultVector = {
            		(x * inputmtrx.matrix[0][0]) + (y * inputmtrx.matrix[0][1]),
            		(x * inputmtrx.matrix[1][0]) + (y * inputmtrx.matrix[1][1])
        	};
	}

    	Vector2 translate(Matrix2x2 inputmtrx) {
        	Vector2 resultVector;
        	return resultVector = {
            		x + inputmtrx.matrix[0][1],
            		y + inputmtrx.matrix[1][1]
        	};
    	}

	Vector3 crossproduct(Vector2 inputvctr) {
		Vector3 resultVector = {};
		Matrix2x2 operatorMatrix = {
			x, y,
			inputvctr.x, inputvctr.y
		};

		resultVector.z = operatorMatrix.determinant();        
		return resultVector;
	}
	    
	Vector2 operator*(const Matrix2x2& right) {
		Vector2 resultVector;
		float local_vector_array[2] = {x, y};
		float result_vector_array[3] = {0, 0};
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				result_vector_array[i] += right.matrix[i][j] * local_vector_array[j];
			}
		}
		return resultVector = {
			result_vector_array[0],
			result_vector_array[1]
		};
	}
	
	Vector2 operator+(const Vector2& right) {
		return add(right);    
	}

	Vector2 operator-(const Vector2& right) {
		return subtract(right);
	}
};
