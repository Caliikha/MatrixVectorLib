#pragma once
#include <iostream>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

class Matrix4x4 {
private:
	const unsigned static int Rows = 4;
	const unsigned static int Cols = 4;
public:
	float matrix[Rows][Cols] = { };

	Matrix4x4 identity() {
        	Matrix4x4 resultMtrx = {};
        	resultMtrx.matrix[0][0] = 1;
        	resultMtrx.matrix[1][1] = 1;
        	resultMtrx.matrix[2][2] = 1;
        	resultMtrx.matrix[3][3] = 1;

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


	static void showResult(Matrix4x4 inputmtrx) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				std::cout << inputmtrx.matrix[i][j] << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

	static void input(Matrix4x4 inputmtrx) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				std::cin >> inputmtrx.matrix[i][j];
			}
		}
	}

//	float determinant() { 
        	// TODO: Complete when 3x3 determinant exists, using cofactor method or some dynamic matrix alternative
//	}

//	Matrix4x4 inverse() { // not fully developed, incorrect values will be returned
        	// TODO: Complete when determinant function exists 
//	}

	Matrix4x4 transpose(){
        	Matrix4x4 resultMtrx;
        	for (int i = 0; i < Rows; i++){
            		for (int j = 0; j < Cols; j++){
                		resultMtrx.matrix[j][i] = matrix[i][j];
            		}
        	}
        
        	return resultMtrx;
    	}

	float trace() {
        	return (matrix[0][0] + matrix[1][1] + matrix[2][2] + matrix[3][3]);
    	}
	
	Matrix4x4 scale(float scale) {
		Matrix4x4 resultMtrx;
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				resultMtrx.matrix[i][j] = (scale * matrix[i][j]);
			}
		}

		return resultMtrx;
	}

	Matrix4x4 multiply(Matrix4x4 inputmtrx) {
		Matrix4x4 resultMtrx = {};
        	for (int i = 0; i < Rows; i++){
            		for (int j = 0; j < Cols; j++){
                		for (int k = 0; k < Rows; k++){
                     			resultMtrx.matrix[i][j] += matrix[i][k] * inputmtrx.matrix[k][j];
                		}
            		}
        	}

		return resultMtrx;
	}


//	Matrix4x4 divide(Matrix4x4 inputmtrx) {
	  // TODO:Complete when determinant and inverse function exists 
      
// 	     return multiply(inputmtrx.inverse());
//	}


	Matrix4x4 add(Matrix4x4 inputmtrx) {
		Matrix4x4 resultMtrx;
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				resultMtrx.matrix[i][j] = { matrix[i][j] + inputmtrx.matrix[i][j] };
			}
		}

		return resultMtrx;
	}

	Matrix4x4 subtract(Matrix4x4 inputmtrx) {
		Matrix4x4 resultMtrx = { };
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				resultMtrx.matrix[i][j] = { matrix[i][j] - inputmtrx.matrix[i][j] };
			}
		}

		return resultMtrx;
	}

	Matrix4x4 operator*(const Matrix4x4& right) {
		return multiply(right);    
	}
	
	Matrix4x4& operator*=(const Matrix4x4& right) {
		Matrix4x4 resultMtrx = multiply(right);
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				matrix[i][j] = resultMtrx.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix4x4 operator+(const Matrix4x4& right) {
		return add(right);    
	}
	
	Matrix4x4& operator+=(const Matrix4x4& right) {
		Matrix4x4 resultMtrx = add(right);
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				matrix[i][j] = resultMtrx.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix4x4 operator-(const Matrix4x4& right) {
		return subtract(right);
	}
	
	Matrix4x4& operator-=(const Matrix4x4& right) {
		Matrix4x4 resultMtrx = subtract(right);
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				matrix[i][j] = resultMtrx.matrix[i][j];
			}
		}
		return *this;
	}
};
