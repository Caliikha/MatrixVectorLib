//Matrix Class as of 20/01/2021

#pragma once
#include <iostream>

class Matrix2x2 {
private:
	static unsigned const int Rows = 2;
	static unsigned const int Cols = 2;
public:
	float matrix[Rows][Cols] = { };

	void identity() {
		matrix[0][0] = 1;
		matrix[0][1] = 0;
		matrix[1][0] = 0;
		matrix[1][1] = 1;
	}

	void define(float a, float b, float c, float d) {
		matrix[0][0] = a;
		matrix[0][1] = b;
		matrix[1][0] = c;
		matrix[1][1] = d;
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

	static void showResult(Matrix2x2 mtrx) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				std::cout << mtrx.matrix[i][j] << " ";
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

	//void showMtrx() {
	//	for (int i = 0; i < 2; i++) {
	//		for (int j = 0; j < 2; j++) {
	//			std::cout << matrix[i][j] << " ";
	//		}
	//		std::cout << "\n";
	//	}
	//	std::cout << "\n";
	//}

	void input() {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				std::cin >> matrix[i][j];
			}
		}
	}

	float determinant() {
		return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
	}

	Matrix2x2 inverse() {
		Matrix2x2 InvMat;
		float C = 1 / determinant();

		InvMat.matrix[0][0] = { C * matrix[1][1] };
		InvMat.matrix[0][1] = { C * -matrix[0][1] };
		InvMat.matrix[1][0] = { C * -matrix[1][0] };
		InvMat.matrix[1][1] = { C * matrix[0][0] };

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				std::cout << InvMat.matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";

		return InvMat;
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

	Matrix2x2 multiply(Matrix2x2 MtrxB) {
		Matrix2x2 resultMtrx = { };
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				resultMtrx.matrix[i][j] = { (matrix[i][0] * MtrxB.matrix[0][j]) + (matrix[i][1] * MtrxB.matrix[1][j]) };
				std::cout << resultMtrx.matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";

		return resultMtrx;
	}

	Matrix2x2 divide(Matrix2x2 MtrxB) {
		Matrix2x2 resultMtrx = { };
		Matrix2x2 InvB = MtrxB.inverse();

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				resultMtrx.matrix[i][j] = { (matrix[i][0] * InvB.matrix[0][j]) + (matrix[i][1] * InvB.matrix[1][j]) };
				std::cout << resultMtrx.matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";

		return resultMtrx;
	}

	Matrix2x2 add(Matrix2x2 MtrxB) {
		Matrix2x2 resultMtrx = { };

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				resultMtrx.matrix[i][j] = { matrix[i][j] + MtrxB.matrix[i][j] };
				std::cout << resultMtrx.matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}

	Matrix2x2 subtract(Matrix2x2 MtrxB) {
		Matrix2x2 resultMtrx = { };
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				resultMtrx.matrix[i][j] = { matrix[i][j] - MtrxB.matrix[i][j] };
				std::cout << resultMtrx.matrix[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
};
