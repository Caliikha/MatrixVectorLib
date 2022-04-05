#include "Matrix3x3.h"
#include "Matrix2x2.h"
#include "../VectorFiles/Vector3.hpp"
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

Matrix3x3::Matrix3x3(
        const float& a0, const float& a1, const float& a2,
        const float& a3, const float& a4, const float& a5,
        const float& a6, const float& a7, const float& a8
        )
{
    this->matrix[0][0] = a0; this->matrix[0][1] = a1; this->matrix[0][2] = a2;
    this->matrix[1][0] = a3; this->matrix[1][1] = a4; this->matrix[1][2] = a5;
    this->matrix[2][0] = a6; this->matrix[2][1] = a7; this->matrix[2][2] = a8;
}

Matrix3x3 Matrix3x3::identity() {
    return Matrix3x3
    {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    };
}

void Matrix3x3::printmtrx() const {
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

void Matrix3x3::showResult(const Matrix3x3& inputmtrx) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cout << inputmtrx.matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Matrix3x3::input(Matrix3x3& inputmtrx) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cin >> inputmtrx.matrix[i][j];
        }
    }
}

// TODO YOU WERE HERE OMAAAAAAAAAAR
// TODO add [gh]
Matrix2x2 Matrix3x3::minormtrx(const int& ith_row, const int& jth_col) const noexcept {
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

// TODO add [gh]
float Matrix3x3::minor(const int& ith_row, const int& jth_col) const noexcept {
    return minormtrx(ith_row, jth_col).determinant();
}

// TODO add [gh]
Matrix2x2 Matrix3x3::cofactormtrx(const int& ith_row, const int& jth_col) const noexcept {
    return minormtrx(ith_row, jth_col).scale(pow(-1, ith_row + jth_col));
}

float Matrix3x3::cofactor(const int& ith_row, const int& jth_col) const noexcept {
    return pow(-1, ith_row + jth_col) * minormtrx(ith_row, jth_col).determinant();
}

// TODO add [gh]
float Matrix3x3::determinant() const noexcept {
    float sum = 0;
    for (int i = 0; i < Cols; i++){
        sum += matrix[0][i]*cofactor(0, i);
    }
    return sum;
}

Matrix3x3 Matrix3x3::inverse() const noexcept {
    if (this->determinant() == 0){
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

//	Matrix3x3 Matrix3x3::inverse() { // incorrect mathematics not developed
// todo: will complete soon after completing determinant() function 
//	}

Matrix3x3 Matrix3x3::transpose() const noexcept {
    Matrix3x3 resultMtrx;

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[j][i] = matrix[i][j];
        }
    }

    return resultMtrx;
}

float Matrix3x3::trace() const noexcept {
    return (matrix[0][0] + matrix[1][1] + matrix[2][2]);
}

Matrix3x3 Matrix3x3::scale(const float& scale) const noexcept {
    Matrix3x3 resultMtrx;

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = (scale * matrix[i][j]);
        }
    }

    return resultMtrx;
}

Matrix3x3 Matrix3x3::multiply(const Matrix3x3& inputmtrx) const noexcept {
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

Matrix3x3 Matrix3x3::add(const Matrix3x3& inputmtrx) const noexcept {
    Matrix3x3 resultMtrx;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = { matrix[i][j] + inputmtrx.matrix[i][j] };
        }
    }

    return resultMtrx;
}

Matrix3x3 Matrix3x3::subtract(const Matrix3x3& inputmtrx) const noexcept {
    Matrix3x3 resultMtrx;

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = { matrix[i][j] - inputmtrx.matrix[i][j] };
        }
    }

    return resultMtrx;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& right) const noexcept {
    return this->multiply(right);
}

Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& right) noexcept {
    Matrix3x3 resultMtrx = this->multiply(right);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& right) const noexcept {
    return this->add(right);
}

Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& right) noexcept {
    Matrix3x3 resultMtrx = this->add(right);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& right) const noexcept {
    return this->subtract(right);
}

Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& right) noexcept {
    Matrix3x3 resultMtrx = this->subtract(right);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}

const float* Matrix3x3::operator[](const int& index) const {
    return this->matrix[index];
}
