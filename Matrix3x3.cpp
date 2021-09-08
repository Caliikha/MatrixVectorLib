#include "Matrix3x3.h"
#include "Matrix2x2.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

Matrix3x3 Matrix3x3::identity() {
    Matrix3x3 resultMtrx = {};
    resultMtrx.matrix[0][0] = 1;
    resultMtrx.matrix[1][1] = 1;
    resultMtrx.matrix[2][2] = 1;

    return resultMtrx;
}

void Matrix3x3::printmtrx() {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

//template <typename TYPE> // Templated functions must reside in header file
//void Matrix3x3::showResult(TYPE input) { std::cout << input << '\n'; }

void Matrix3x3::showResult(Matrix3x3 inputmtrx) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cout << inputmtrx.matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Matrix3x3::input(Matrix3x3 inputmtrx) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cin >> inputmtrx.matrix[i][j];
        }
    }
}

Matrix2x2 Matrix3x3::minormtrx(int ith_row, int jth_col) {
    Matrix2x2 resultMtrx;
    
    int i_2 = 0;
    for (int i = 0; i < Rows; i++){
        int j_2 = 0;
        for (int j = 0; j < Cols; j++){
            if (i == ith_row || j == jth_col){
                continue;
            }
            else {
                resultMtrx.matrix[i_2][j_2++] = matrix[i][j];
                if (j_2 == 2){
                    i_2++;
                }
            }
        }
    }
    
    return resultMtrx;
}

float Matrix3x3::minor(int ith_row, int jth_col){
    return minormtrx(ith_row, jth_col).determinant();
}

Matrix2x2 Matrix3x3::cofactormtrx(int ith_row, int jth_col){
    return minormtrx(ith_row, jth_col).scale(pow(-1, ith_row + jth_col));
}

float Matrix3x3::cofactor(int ith_row, int jth_col){
    return pow(-1, ith_row + jth_col) * minormtrx(ith_row, jth_col).determinant();
}

float Matrix3x3::determinant() { 
    float sum = 0;
    for (int i = 0; i < Cols; i++){
        sum += matrix[0][i]*cofactor(0, i);
    }
    return sum;
}

Matrix3x3 Matrix3x3::inverse() {
    if (determinant() == 0){
        std::cerr << "ERROR: Matrix3x3 inverse() will return undefined value due to determinant = 0" << std::endl;
    }
    Matrix3x3 matrix_of_cofactors;
    
    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            matrix_of_cofactors.matrix[i][j] = cofactor(i, j);
        }
    }
    
    return matrix_of_cofactors.transpose().scale(1/determinant());
}

Matrix3x3 Matrix3x3::transpose() { 
    Matrix3x3 resultMtrx;

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[j][i] = matrix[i][j];
        }
    }

    return resultMtrx;
}

float Matrix3x3::trace() { 
    return (matrix[0][0] + matrix[1][1] + matrix[2][2]);
}

Matrix3x3 Matrix3x3::scale(float scale) {
    Matrix3x3 resultMtrx;

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = (scale * matrix[i][j]);
        }
    }

    return resultMtrx;
}

Matrix3x3 Matrix3x3::multiply(Matrix3x3 inputmtrx) {
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

//	Matrix3x3 Matrix3x3::divide(Matrix3x3 inputmtrx) {
// TODO:Complete when determinant and inverse function exists 

//      return multiply(inputmtrx.inverse());
//    }

Matrix3x3 Matrix3x3::add(Matrix3x3 inputmtrx) {
    Matrix3x3 resultMtrx;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = { matrix[i][j] + inputmtrx.matrix[i][j] };
        }
    }

    return resultMtrx;
}

Matrix3x3 Matrix3x3::subtract(Matrix3x3 inputmtrx) {
    Matrix3x3 resultMtrx = { };

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = { matrix[i][j] - inputmtrx.matrix[i][j] };
        }
    }

    return resultMtrx;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& right) {
    return multiply(right);
}

Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& right) {
    Matrix3x3 resultMtrx = multiply(right);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& right) {
    return add(right);
}

Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& right) {
    Matrix3x3 resultMtrx = add(right);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& right) {
    return subtract(right);
}

Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& right) {
    Matrix3x3 resultMtrx = subtract(right);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}
