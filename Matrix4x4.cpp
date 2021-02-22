#pragma once
#include <iostream>

class Matrix4x4 {
private:
	const unsigned static int Rows = 4;
	const unsigned static int Cols = 4;
public:
	float matrix[Rows][Cols] = { };

	void identity() {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				matrix[i][j] = 0;
			}
			matrix[i][i] = 1;
		}
	}

	template<typename TYPE>
	void printVal(TYPE value) {
		std::cout << value << std::endl;
	}

	void printVal() {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

	//void define(float a = INT_MAX, float b = INT_MAX, float c = INT_MAX, float d = INT_MAX) { // useless function, you can use CML::Matrix4x4 mtrx = { ... };
	//	matrix[0][0] = a;
	//	matrix[0][1] = b;
	//	matrix[1][0] = c;
	//	matrix[1][1] = d;
	//}

	static void showResult(Matrix4x4 mtrx) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				std::cout << mtrx.matrix[i][j] << " ";
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

	void input() {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				std::cin >> matrix[i][j];
			}
		}
	}

	float determinant() {
		return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
	}

	Matrix4x4 inverse() {
		Matrix4x4 InvMat;
		float C = 1 / determinant();

		InvMat.matrix[0][0] = { C * matrix[1][1] };
		InvMat.matrix[0][1] = { C * -matrix[0][1] };
		InvMat.matrix[1][0] = { C * -matrix[1][0] };
		InvMat.matrix[1][1] = { C * matrix[0][0] };

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				std::cout << InvMat.matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";

		return InvMat;
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

	Matrix4x4 multiply(Matrix4x4 MtrxB) {
		Matrix4x4 resultMtrx = { };

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				resultMtrx.matrix[i][j] = { (matrix[i][0] * MtrxB.matrix[0][j]) + (matrix[i][1] * MtrxB.matrix[1][j]) };
				std::cout << resultMtrx.matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";

		return resultMtrx;
	}

	Matrix4x4 divide(Matrix4x4 MtrxB) {
		Matrix4x4 resultMtrx;
		Matrix4x4 InvB = MtrxB.inverse();

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				resultMtrx.matrix[i][j] = { (matrix[i][0] * InvB.matrix[0][j]) + (matrix[i][1] * InvB.matrix[1][j]) };
				std::cout << resultMtrx.matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";

		return resultMtrx;
	}

	Matrix4x4 add(Matrix4x4 MtrxB) {
		Matrix4x4 resultMtrx;
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				resultMtrx.matrix[i][j] = { matrix[i][j] + MtrxB.matrix[i][j] };
				std::cout << resultMtrx.matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		
		return resultMtrx;
	}

	Matrix4x4 subtract(Matrix4x4 MtrxB) {
		Matrix4x4 resultMtrx = { };

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				resultMtrx.matrix[i][j] = { matrix[i][j] - MtrxB.matrix[i][j] };
				std::cout << resultMtrx.matrix[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		
		return resultMtrx;
	}
};
