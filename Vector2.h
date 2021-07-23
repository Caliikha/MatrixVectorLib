#pragma once
#include <iostream>
#include <cmath>
#include "../MatrixFiles/Matrix2x2.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

class Vector2 {
public:
	float x = 0, y = 0;

	static void input(Vector2 inputvctr) {
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

//    Vector2 crossproduct(Vector2 inputvctr) {
        // TODO
//    }
};