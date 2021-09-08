#include "Matrix4x4.h"
#include "Matrix3x3.h"
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

Matrix4x4 Matrix4x4::identity() {
    Matrix4x4 resultMtrx = {};
    resultMtrx.matrix[0][0] = 1;
    resultMtrx.matrix[1][1] = 1;
    resultMtrx.matrix[2][2] = 1;
    resultMtrx.matrix[3][3] = 1;

    return resultMtrx;
}

void Matrix4x4::printmtrx() {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

//template <typename TYPE> // Templated functions must reside in header file
//void Matrix4x4::showResult(TYPE input){ std::cout << input << '\n'; }

void Matrix4x4::showResult(Matrix4x4 inputmtrx) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cout << inputmtrx.matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Matrix4x4::input(Matrix4x4 inputmtrx) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cin >> inputmtrx.matrix[i][j];
        }
    }
}

Matrix3x3 Matrix4x4::minormtrx(int ith_row, int jth_col){
    Matrix3x3 resultMtrx;
    
    int i_2 = 0;
    for (int i = 0; i < Rows; i++){
        int j_2 = 0;
        for (int j = 0; j < Cols; j++){
            if (i == ith_row || j == jth_col){
                continue;
            }
            else {
                resultMtrx.matrix[i_2][j_2++] = matrix[i][j];
                if (j_2 == 3){
                    i_2++;
                }
            }
        }
    }
    
    return resultMtrx;
}

float Matrix4x4::minor(int ith_row, int jth_col){
    return minormtrx(ith_row, jth_col).determinant();
}

Matrix3x3 Matrix4x4::cofactormtrx(int ith_row, int jth_col){
    return minormtrx(ith_row, jth_col).scale(pow(-1, ith_row + jth_col));
}

float Matrix4x4::cofactor(int ith_row, int jth_col){
    return pow(-1, ith_row + jth_col) * minormtrx(ith_row, jth_col).determinant();
}

float Matrix4x4::determinant(){
    float sum = 0;
    for (int i = 0; i < Cols; i++){
        sum += matrix[0][i]*cofactor(0, i);
    }
    return sum;
}

Matrix4x4 Matrix4x4::inverse(){
    if (determinant() == 0){
        std::cerr << "ERROR: Matrix4x4 inverse() will return undefined value due to determinant = 0" << std::endl;
    }
    Matrix4x4 matrix_of_cofactors;
   
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            matrix_of_cofactors.matrix[i][j] = cofactor(i, j);
        }
    }
    
    return matrix_of_cofactors.transpose().scale(1/determinant());
}

Matrix4x4 Matrix4x4::transpose(){
    Matrix4x4 resultMtrx;

    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            resultMtrx.matrix[j][i] = matrix[i][j];
        }
    }

    return resultMtrx;
}

float Matrix4x4::trace() {
    return (matrix[0][0] + matrix[1][1] + matrix[2][2] + matrix[3][3]);
}

Matrix4x4 Matrix4x4::scale(float scale) {
    Matrix4x4 resultMtrx;

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = (scale * matrix[i][j]);
        }
    }

    return resultMtrx;
}

Matrix4x4 Matrix4x4::multiply(Matrix4x4 inputmtrx) {
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

//	Matrix4x4 Matrix4x4::divide(Matrix4x4 inputmtrx) {
// TODO:Complete when determinant and inverse function exists 

//      return multiply(inputmtrx.inverse());
//	}

Matrix4x4 Matrix4x4::add(Matrix4x4 inputmtrx) {
    Matrix4x4 resultMtrx;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = { matrix[i][j] + inputmtrx.matrix[i][j] };
        }
    }

    return resultMtrx;
}

Matrix4x4 Matrix4x4::subtract(Matrix4x4 inputmtrx) {
    Matrix4x4 resultMtrx = { };

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = { matrix[i][j] - inputmtrx.matrix[i][j] };
        }
    }

    return resultMtrx;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& right) {
    return multiply(right);
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& right) {
    Matrix4x4 resultMtrx = multiply(right);
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& right) {
    return add(right);
}

Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& right) {
    Matrix4x4 resultMtrx = add(right);
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& right) {
    return subtract(right);
}

Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& right) {
    Matrix4x4 resultMtrx = subtract(right);
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}
