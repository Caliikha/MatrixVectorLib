#include <iostream>
#include "../MatrixFiles/Matrix4x4.h"
#include "Vector4.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342
#include <cmath>
#include <chrono>

class Evector4 {
public:
	float x = 0, y = 0, z = 0, w = 0;
    float **vector = new (std::nothrow) float*[size]{&x,&y,&z,&w};
    int size = 4;

    ~Evector4(){
        delete[] vector;
        vector = nullptr;
    }

	void input() {
        for (int i = 0; i < size; i++){
            std::cin >> *vector[i];
        }
	}

	void printvector() {
        std::cout << '(';
        for (int i = 0; i < size-1; i++){
            std::cout << *vector[i] << ", ";
        }
        std::cout << *vector[size-1] << ')' << '\n';
	}

	float dotproduct(Evector4 &inputvctr) {
        float result = 0;
        for (int i = 0; i < size-1; i++){
            result += *vector[i] * (*inputvctr.vector[i]); 
        }
        return result;
	}

    static float radians(float angle){
        return angle * (PI/180);
    }

	float angle(Evector4 &inputvctr) {
		float Product = dotproduct(inputvctr);
        float local_magnitude = 0;
        float input_magnitude = 0;
        for (int i = 0; i < size; i++){
            local_magnitude += pow(*vector[i], 2);
            input_magnitude += pow(*inputvctr.vector[i], 2);
        }
        local_magnitude = sqrt(local_magnitude);
        input_magnitude = sqrt(input_magnitude);
//		float Magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) * sqrt(pow(inputvctr.x, 2) + pow(inputvctr.y, 2) + pow(inputvctr.z, 2));
		return acos(Product / (local_magnitude * input_magnitude)) * (180 / PI);
	}

	Evector4 resultant(Evector4 &inputvctr) {
		Evector4 resultVector = {0, 0, 0, 0};
        for (int i = 0; i < size; i++){
            *resultVector.vector[i] = sqrt(pow(*vector[i], 2) + pow(*inputvctr.vector[i], 2));
        }
//		resultVector.x = sqrt(pow(x, 2) + pow(inputvctr.x, 2));
//		resultVector.y = sqrt(pow(y, 2) + pow(inputvctr.y, 2));
//		resultVector.z = sqrt(pow(z, 2) + pow(inputvctr.z, 2));
//      resultVector.w = sqrt(pow(w, 2) + pow(inputvctr.w, 2));
		return resultVector;
	}

	Evector4 scale(float scale) {
		Evector4 resultVector;
        for (int i = 0; i < size; i++){
            *resultVector.vector[i] = *vector[i] * scale;
        }
		return resultVector;
	}

	Evector4 scale(Matrix4x4 mtrx) {
		Evector4 resultVector;
        for (int i = 0; i < size; i++){
            *resultVector.vector[i] = *vector[i] * mtrx.matrix[i][i];
        }
//		resultVector.x = x * mtrx.matrix[0][0];
//		resultVector.y = y * mtrx.matrix[1][1];
//		resultVector.z = z * mtrx.matrix[2][2];
//		resultVector.w = w * mtrx.matrix[3][3];
		return resultVector;
	}

	Evector4 rotate(Matrix4x4 mtrx) { // not functioning correctly, mathematics is probably incorrect
	    Evector4 resultVector = { 0, 0, 0, 0 };
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

	Evector4 testrotate(Matrix4x4 mtrx) { // not functioning correctly, mathematics is probably incorrect
		Evector4 resultVector = { 0, 0, 0, 0 };
        for (int i = 0; i < size - 1; i++){
            for (int j = 0; j < 4; j++){
                *resultVector.vector[i] += mtrx.matrix[i][j] * *vector[i];
            }
        }
//		resultVector.x = (mtrx.matrix[0][0] * x) + (mtrx.matrix[0][1] * y) + (mtrx.matrix[0][2] * z);
//		resultVector.y = (mtrx.matrix[1][0] * x) + (mtrx.matrix[1][1] * y) + (mtrx.matrix[1][2] * z);
//		resultVector.z = (mtrx.matrix[2][0] * x) + (mtrx.matrix[2][1] * y) + (mtrx.matrix[2][2] * z);
//		resultVector.w = w;
		return resultVector;
	}

	Evector4 translate(Matrix4x4 mtrx) {
		Evector4 resultVector;
        for (int i = 0; i < size-1; i++){
            *resultVector.vector[i] = *vector[i] + mtrx.matrix[i][3];
        }
//		resultVector.x = x + mtrx.matrix[0][3];
//		resultVector.y = y + mtrx.matrix[1][3];
//		resultVector.z = z + mtrx.matrix[2][3];
		if (mtrx.matrix[3][3] == 1) {
			resultVector.w = w;
		}
		else {
			resultVector.w = w + mtrx.matrix[3][3];
		}
		return resultVector;
	}

//    Evector4 product(Evector4 inputvctr){
//        Evector4 resultVector;
//
//        resultVector.x = (y * inputvctr.z) - (inputvctr.y * z); // 2*7 - 6*3
//        resultVector.y = (z * inputvctr.x) - (inputvctr.x * z); // 3*5 
//        resultVector.z = (x * inputvctr.y) - (inputvctr.y * x);
//        resultVector.w = w;
//
//        return resultVector;
//    }
};

int main(int argc, char **argv)
{
    Evector4 Evec = {1, 0, 0, 0};
    Evector4 Evec1 ={0, 1, 0, 0};

    // TODO: Investigate error in this area
    // Evec = Evec.scale(5);

    std::cout<< Evec.dotproduct(Evec) << std::endl;
    std::cout<< Evec.angle(Evec1) << std::endl;
    Evector4 newVec = Evec.resultant(Evec1);
    std::cout<< Evec.angle(newVec) << std::endl;
    std::cout << Evec.resultant(Evec1).angle(Evec1) << std::endl;
}
