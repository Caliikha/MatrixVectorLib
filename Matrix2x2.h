#pragma once
#include <iostream>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

class Matrix2x2 {
private:
	static const int Rows = 2;
	static const int Cols = 2;
public:
	float matrix[Rows][Cols] = { };

	Matrix2x2 identity() {
        	Matrix2x2 resultMtrx = {};
			matrix[0][0] = 1;
			matrix[1][1] = 1;
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

	static void showResult(Matrix2x2 inputmtrx) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				std::cout << inputmtrx.matrix[i][j] << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

	static void input(Matrix2x2 inputmtrx) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				std::cin >> inputmtrx.matrix[i][j];
			}
		}
	}

	float determinant() {
		return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
	}

	Matrix2x2 inverse() {
		Matrix2x2 InvMat;
		float Const = 1 / determinant();

		InvMat.matrix[0][0] = { Const * matrix[1][1] };
		InvMat.matrix[0][1] = { Const * -matrix[0][1] };
		InvMat.matrix[1][0] = { Const * -matrix[1][0] };
		InvMat.matrix[1][1] = { Const * matrix[0][0] };

		return InvMat;
	}

    	Matrix2x2 transpose() {
        	Matrix2x2 resultMtrx;

        	for (int i = 0; i < Rows; i++){
            		for (int j = 0; j < Cols; j++){
                		resultMtrx.matrix[j][i] = matrix[i][j];
            		}
        	}

        	return resultMtrx;
    	}

    	float trace() {
        	return (matrix[0][0] + matrix[1][1]);
    	}

	Matrix2x2 scale(float scale) {
		Matrix2x2 resultMtrx;

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				resultMtrx.matrix[i][j] = (scale * matrix[i][j]);
			}
		}

		return resultMtrx;
	}

	Matrix2x2 multiply(Matrix2x2 inputmtrx) {
		Matrix2x2 resultMtrx = {};
        
        	for (int i = 0; i < Rows; i++){
            		for (int j = 0; j < Cols; j++){
                		for (int k = 0; k < Rows; k++){
                     			resultMtrx.matrix[i][j] += matrix[i][k] * inputmtrx.matrix[k][j];
                		}
            		}
        	}

		return resultMtrx;
	}

	Matrix2x2 divide(Matrix2x2 inputmtrx) {
        	return multiply(inputmtrx.inverse());
	}

	Matrix2x2 add(Matrix2x2 MtrxB) {
		Matrix2x2 resultMtrx = { };

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				resultMtrx.matrix[i][j] = { matrix[i][j] + MtrxB.matrix[i][j] };
			}
		}

		return resultMtrx;
	}

	Matrix2x2 subtract(Matrix2x2 MtrxB) {
		Matrix2x2 resultMtrx = { };

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				resultMtrx.matrix[i][j] = { matrix[i][j] - MtrxB.matrix[i][j] };
			}
		}

		return resultMtrx;
	}
	
	Matrix2x2 operator*(const Matrix2x2& right) {
		return multiply(right);    
	}

	Matrix2x2& operator*=(const Matrix2x2& right) {
		Matrix2x2 resultMtrx = multiply(right);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				matrix[i][j] = resultMtrx.matrix[i][j];
			}
		}
		return *this;
	}
	
	Matrix2x2 operator/(const Matrix2x2& right) {
		return divide(right);    
	}

	Matrix2x2& operator/=(const Matrix2x2& right) {
		Matrix2x2 resultMtrx = divide(right);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				matrix[i][j] = resultMtrx.matrix[i][j];
			}
		}
		return *this;
	}
	
	Matrix2x2 operator+(const Matrix2x2& right) {
		return add(right);    
	}
	
	Matrix2x2& operator+=(const Matrix2x2& right) {
		Matrix2x2 resultMtrx = add(right);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				matrix[i][j] = resultMtrx.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix2x2 operator-(const Matrix2x2& right) {
		return subtract(right);
	}
};
