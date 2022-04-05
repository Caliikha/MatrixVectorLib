#include "Matrix4x4.h"
#include "Matrix3x3.h"
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342

Matrix4x4::Matrix4x4(
        const float& a0, const float& a1, const float& a2, const float& a3,
        const float& a4, const float& a5, const float& a6, const float& a7,
        const float& a8, const float& a9, const float& a10, const float& a11,
        const float& a12, const float& a13, const float& a14, const float& a15
        )
{
    this->matrix[0][0] = a0; this->matrix[0][1] = a1; this->matrix[0][2] = a2; this->matrix[0][3] = a3;
    this->matrix[1][0] = a4; this->matrix[1][1] = a5; this->matrix[1][2] = a6; this->matrix[1][3] = a7;
    this->matrix[2][0] = a8; this->matrix[2][1] = a9; this->matrix[2][2] = a10; this->matrix[2][3] = a11;
    this->matrix[3][0] = a12; this->matrix[3][1] = a13; this->matrix[3][2] = a14; this->matrix[3][3] = a15;
}

Matrix4x4 Matrix4x4::identity() {
    return Matrix4x4
    {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
}

void Matrix4x4::printmtrx() const {
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

void Matrix4x4::showResult(const Matrix4x4& inputmtrx) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cout << inputmtrx.matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Matrix4x4::input(Matrix4x4& inputmtrx) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cin >> inputmtrx.matrix[i][j];
        }
    }
}

Matrix3x3 Matrix4x4::minormtrx(const int& ith_row, const int& jth_col) const noexcept {
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

// TODO add [gh]
float Matrix4x4::minor(const int& ith_row, const int& jth_col) const noexcept {
    return minormtrx(ith_row, jth_col).determinant();
}

// TODO add [gh]
Matrix3x3 Matrix4x4::cofactormtrx(const int& ith_row, const int& jth_col) const noexcept {
    return minormtrx(ith_row, jth_col).scale(pow(-1, ith_row + jth_col));
}

// TODO add [gh]
float Matrix4x4::cofactor(const int& ith_row, const int& jth_col) const noexcept {
    return pow(-1, ith_row + jth_col) * minormtrx(ith_row, jth_col).determinant();
}

// TODO add [gh]
float Matrix4x4::determinant() const noexcept {
    float sum = 0;
    for (int i = 0; i < Cols; i++){
        sum += matrix[0][i]*cofactor(0, i);
    }
    return sum;
}

Matrix4x4 Matrix4x4::inverse() const noexcept {
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

Matrix4x4 Matrix4x4::transpose() const noexcept {
    Matrix4x4 resultMtrx;

    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            resultMtrx.matrix[j][i] = matrix[i][j];
        }
    }

    return resultMtrx;
}

float Matrix4x4::trace() const noexcept {
    return (matrix[0][0] + matrix[1][1] + matrix[2][2] + matrix[3][3]);
}

Matrix4x4 Matrix4x4::scale(const float& scale) const noexcept {
    Matrix4x4 resultMtrx;

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = (scale * matrix[i][j]);
        }
    }

    return resultMtrx;
}

Matrix4x4 Matrix4x4::multiply(const Matrix4x4& inputmtrx) const noexcept {
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

Matrix4x4 Matrix4x4::add(const Matrix4x4& inputmtrx) const noexcept {
    Matrix4x4 resultMtrx;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = { matrix[i][j] + inputmtrx.matrix[i][j] };
        }
    }

    return resultMtrx;
}

Matrix4x4 Matrix4x4::subtract(const Matrix4x4& inputmtrx) const noexcept {
    Matrix4x4 resultMtrx;

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = { matrix[i][j] - inputmtrx.matrix[i][j] };
        }
    }

    return resultMtrx;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& right) const noexcept {
    return this->multiply(right);
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& right) noexcept {
    return *this = this->multiply(right);
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& right) const noexcept {
    return this->add(right);
}

Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& right) noexcept {
    return *this = this->add(right);
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& right) const noexcept {
    return this->subtract(right);
}

Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& right) noexcept {
    return *this = this->subtract(right);
}

const float* Matrix4x4::operator[](const int& index) const {
    return this->matrix[index];
}
