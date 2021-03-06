#pragma once
#include <iostream>
#include "Matrix4x4.cpp"

class vector4 {
public:
	float x = 0, y = 0, z = 0, w = 0;

	void input() {
		std::cin >> x, y, z, w;
	}

	void printvector() {
		std::cout << "(" << x << ", " << y << ", " << z << ", " << w << ")" << "\n";
	}
	
	float dotproduct(vector4 inputvctr) {
		return (x * inputvctr.x) + (y * inputvctr.y) + (z * inputvctr.z);
	}

	float angle(vector4 inputvctr) {
		float Product = dotproduct(inputvctr);
		float Magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) * sqrt(pow(inputvctr.x, 2) + pow(inputvctr.y, 2) + pow(inputvctr.z, 2));
		return acos(Product / Magnitude) * (180 / PI);
	}
	
	vector4 resultant(vector4 inputvctr) {
		vector4 resultVector;
		resultVector.x = sqrt(pow(x, 2) + pow(inputvctr.x, 2));
		resultVector.y = sqrt(pow(y, 2) + pow(inputvctr.y, 2));
		resultVector.z = sqrt(pow(z, 2) + pow(inputvctr.z, 2));
		return resultVector;
	}
	
	vector4 scale(float scale) {
		vector4 resultVector;
		resultVector.x = x * scale;
		resultVector.y = y * scale;
		resultVector.z = z * scale;
		resultVector.w = w * scale;

		return resultVector;
	}

	vector4 scale(Matrix4x4 mtrx) {
		vector4 resultVector;
		resultVector.x = x * mtrx.matrix[0][0];
		resultVector.y = y * mtrx.matrix[1][1];
		resultVector.z = z * mtrx.matrix[2][2];
		resultVector.w = w * mtrx.matrix[3][3];
		return resultVector;
	}

	vector4 rotate(Matrix4x4 mtrx) { // not functioning correctly, mathematics is probably incorrect
		vector4 resultVector = { 0, 0, 0, 0 };
		for (int i = 0; i < 4; i++) {
			resultVector.x += x * mtrx.matrix[0][i];
		}
		for (int i = 0; i < 4; i++) {
			resultVector.y += y * mtrx.matrix[1][i];
		}
		for (int i = 0; i < 4; i++) {
			resultVector.z += z * mtrx.matrix[2][i];
		}
		for (int i = 0; i < 4; i++) {
			resultVector.w += w * mtrx.matrix[3][i];
		}
		return resultVector;
	}

	vector4 testrotate(Matrix4x4 mtrx) { // not functioning correctly, mathematics is probably incorrect
		vector4 resultVector;
		resultVector.x = (mtrx.matrix[1][1] * x) + (mtrx.matrix[1][2] * y) + (mtrx.matrix[1][3] * z);
		resultVector.y = (mtrx.matrix[2][1] * x) + (mtrx.matrix[2][2] * y) + (mtrx.matrix[2][3] * z);
		resultVector.z = (mtrx.matrix[3][1] * x) + (mtrx.matrix[3][2] * y) + (mtrx.matrix[3][3] * z);
		resultVector.w = w;
		return resultVector;
	}

	vector4 translate(Matrix4x4 mtrx) {
		vector4 resultVector;
		resultVector.x = x + mtrx.matrix[0][3];
		resultVector.y = y + mtrx.matrix[1][3];
		resultVector.z = z + mtrx.matrix[2][3];
		if (mtrx.matrix[3][3] == 1) {
			resultVector.w = w;
		}
		else {
			resultVector.w = w + mtrx.matrix[3][3];
		}
		return resultVector;
	}
};
