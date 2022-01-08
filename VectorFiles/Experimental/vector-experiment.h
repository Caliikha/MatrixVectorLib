#include <iostream>
#include "../MatrixFiles/Matrix4x4.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342
#include <cmath>

template <int size>
class Evector {
public:
	float x = 0, y = 0, z = 0, w = 0;

private:
    float **vector;

public:
    Evector(float X = 0, float Y = 0, float Z = 0, float W = 0){
        if (size == 1){
            vector = new (std::nothrow) float*[1]{&x};
            *vector[0] = X;
        }

        else if (size == 2){
            vector = new (std::nothrow) float*[2]{&x,&y};
            *vector[0] = X;
            *vector[1] = Y;
        }

        else if (size == 3){
            vector = new (std::nothrow) float*[3]{&x,&y,&z};
            *vector[0] = X;
            *vector[1] = Y;
            *vector[2] = Z;
        }
        else {
            vector = new (std::nothrow) float*[size]{&x,&y,&z,&w};
            *vector[0] = X;
            *vector[1] = Y;
            *vector[2] = Z;
            *vector[3] = W;
        }
    }

    ~Evector(){
        std::cout << "FLAG!{}\n";
        if (vector != nullptr){
            std::cout << "FLAG!{Deleting}\n";
            delete[] vector;
            vector = nullptr;
        }
    }

	void input() {
        std::cin >> x >> y >> z >> w;
	}

    
	void printvector() {
		std::cout << "(" << x << ", " << y << ", " << z << ", " << w << ")" << "\n";
	}

	float dotproduct(Evector inputvctr) {
		return (x * inputvctr.x) + (y * inputvctr.y) + (z * inputvctr.z);
	}

	float angle(Evector inputvctr) {
		float Product = dotproduct(inputvctr);
		float Magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) * sqrt(pow(inputvctr.x, 2) + pow(inputvctr.y, 2) + pow(inputvctr.z, 2));
		return acos(Product / Magnitude) * (180 / PI);
	}

	Evector resultant(Evector inputvctr) {
		Evector resultVector;
		resultVector.x = sqrt(pow(x, 2) + pow(inputvctr.x, 2));
		resultVector.y = sqrt(pow(y, 2) + pow(inputvctr.y, 2));
		resultVector.z = sqrt(pow(z, 2) + pow(inputvctr.z, 2));
		return resultVector;
	}

	Evector scale(float scale) {
		Evector resultVector;
		resultVector.x = x * scale;
		resultVector.y = y * scale;
		resultVector.z = z * scale;
		resultVector.w = w * scale;

		return resultVector;
	}

	Evector scale(Matrix4x4 mtrx) {
		Evector resultVector;
		resultVector.x = x * mtrx.matrix[0][0];
		resultVector.y = y * mtrx.matrix[1][1];
		resultVector.z = z * mtrx.matrix[2][2];
		resultVector.w = w * mtrx.matrix[3][3];
		return resultVector;
	}

	Evector rotate(Matrix4x4 mtrx) { // not functioning correctly, mathematics is probably incorrect
		Evector resultVector = { 0, 0, 0, 0 };
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

	Evector testrotate(Matrix4x4 mtrx) { // not functioning correctly, mathematics is probably incorrect
		Evector resultVector;
		resultVector.x = (mtrx.matrix[0][0] * x) + (mtrx.matrix[0][1] * y) + (mtrx.matrix[0][2] * z);
		resultVector.y = (mtrx.matrix[1][0] * x) + (mtrx.matrix[1][1] * y) + (mtrx.matrix[1][2] * z);
		resultVector.z = (mtrx.matrix[2][0] * x) + (mtrx.matrix[2][1] * y) + (mtrx.matrix[2][2] * z);
		resultVector.w = w;
		return resultVector;
	}

	Evector translate(Matrix4x4 mtrx) {
		Evector resultVector;
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
