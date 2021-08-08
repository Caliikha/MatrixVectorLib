#pragma once
#include <iostream>
#include "Matrix2x2.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

class Matrix3x3 {
private:
	const static int Rows = 3;
	const static int Cols = 3;
public:
	float matrix[Rows][Cols] = { };

	Matrix3x3 identity() {
        	Matrix3x3 resultMtrx = {};
        	resultMtrx.matrix[0][0] = 1;
        	resultMtrx.matrix[1][1] = 1;
        	resultMtrx.matrix[2][2] = 1;

        	return resultMtrx;
	}

	void printmtrx() {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				std::cout << matrix[i][j] << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

	template <typename TYPE>
	static void showResult(TYPE input) { 
		std::cout << input << '\n';
	}

	static void showResult(Matrix3x3 inputmtrx) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				std::cout << inputmtrx.matrix[i][j] << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

	static void input(Matrix3x3 inputmtrx) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				std::cin >> inputmtrx.matrix[i][j];
			}
		}
	}

	float determinant() { 
	        Matrix2x2 Cofactor_1 = {
            		matrix[1][1], matrix[1][2],
            		matrix[2][1], matrix[2][2]
        	};
        	Matrix2x2 Cofactor_2 = {
            		matrix[1][0], matrix[1][2],
            		matrix[2][0], matrix[2][2]
        	};
        	Matrix2x2 Cofactor_3 = {
            		matrix[1][0], matrix[1][1],
            		matrix[2][0], matrix[2][1]
        	};
        	return (matrix[0][0] * Cofactor_1.determinant()) 
               	      -(matrix[0][1] * Cofactor_2.determinant())
             	      +(matrix[0][2] * Cofactor_3.determinant());
	}

//	Matrix3x3 inverse() { // incorrect mathematics not developed
        // TODO: Will complete soon after completing determinant() function
//	}

	Matrix3x3 transpose() { 
		Matrix3x3 resultMtrx;

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				resultMtrx.matrix[j][i] = matrix[i][j];
			}
		}

		return resultMtrx;
	}

	float trace() { 
        	return (matrix[0][0] + matrix[1][1] + matrix[2][2]);
	}

	Matrix3x3 scale(float scale) {
		Matrix3x3 resultMtrx;

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				resultMtrx.matrix[i][j] = (scale * matrix[i][j]);
			}
		}

		return resultMtrx;
	}

	Matrix3x3 multiply(Matrix3x3 inputmtrx) {
		Matrix3x3 resultMtrx = {};

        	for (int i = 0; i < Rows; i++){
            		for (int j = 0; j < Cols; j++){
                		for (int k = 0; k < Rows; k++){
                     			resultMtrx.matrix[i][j] += matrix[i][k] * inputmtrx.matrix[k][j];
                		}
            		}
        	}

		return resultMtrx;
	}

//	Matrix3x3 divide(Matrix3x3 inputmtrx) {
      // TODO:Complete when determinant and inverse function exists 

//      return multiply(inputmtrx.inverse());
//    }

	Matrix3x3 add(Matrix3x3 inputmtrx) {
		Matrix3x3 resultMtrx;
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				resultMtrx.matrix[i][j] = { matrix[i][j] + inputmtrx.matrix[i][j] };
			}
		}

		return resultMtrx;
	}

	Matrix3x3 subtract(Matrix3x3 inputmtrx) {
		Matrix3x3 resultMtrx = { };

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				resultMtrx.matrix[i][j] = { matrix[i][j] - inputmtrx.matrix[i][j] };
			}
		}

		return resultMtrx;
	}
	
	Matrix3x3 operator*(const Matrix3x3& right) {
		return multiply(right);    
	}

	Matrix3x3 operator+(const Matrix3x3& right) {
		return add(right);    
	}

	Matrix3x3 operator-(const Matrix3x3& right) {
		return subtract(right);
	}
};
