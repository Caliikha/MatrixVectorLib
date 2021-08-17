#include "Matrix2x2.h"

Matrix2x2 Matrix2x2::identity() {
    Matrix2x2 resultMtrx = {};
    resultMtrx.matrix[0][0] = 1;
    resultMtrx.matrix[1][1] = 1;
    return resultMtrx;
}

void Matrix2x2::printmtrx() {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

//template <typename TYPE> // templated functions must reside in header file
//void Matrix2x2::showResult(TYPE input) { std::cout << input << '\n'; }

void Matrix2x2::showResult(Matrix2x2 inputmtrx) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cout << inputmtrx.matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Matrix2x2::input(Matrix2x2 inputmtrx) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cin >> inputmtrx.matrix[i][j];
        }
    }
}

float Matrix2x2::determinant() {
    return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
}

Matrix2x2 Matrix2x2::inverse() {
    Matrix2x2 InvMat;
    float Const = 1 / determinant();

    InvMat.matrix[0][0] = { Const * matrix[1][1] };
    InvMat.matrix[0][1] = { Const * -matrix[0][1] };
    InvMat.matrix[1][0] = { Const * -matrix[1][0] };
    InvMat.matrix[1][1] = { Const * matrix[0][0] };

    return InvMat;
}

Matrix2x2 Matrix2x2::transpose() {
    Matrix2x2 resultMtrx;

    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            resultMtrx.matrix[j][i] = matrix[i][j];
        }
    }

    return resultMtrx;
}

float Matrix2x2::trace() {
    return (matrix[0][0] + matrix[1][1]);
}

Matrix2x2 Matrix2x2::scale(float scale) {
    Matrix2x2 resultMtrx;

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = (scale * matrix[i][j]);
        }
    }

    return resultMtrx;
}

Matrix2x2 Matrix2x2::multiply(Matrix2x2 inputmtrx) {
    Matrix2x2 resultMtrx = {};

    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            for (int k = 0; k < Rows; k++){
                resultMtrx.matrix[i][j] += matrix[i][k] * inputmtrx.matrix[k][j];
            }
        }
    }

    return resultMtrx;
}

Matrix2x2 Matrix2x2::divide(Matrix2x2 inputmtrx) {
    return multiply(inputmtrx.inverse());
}

Matrix2x2 Matrix2x2::add(Matrix2x2 inputmtrx) {
    Matrix2x2 resultMtrx = { };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultMtrx.matrix[i][j] = { matrix[i][j] + inputmtrx.matrix[i][j] };
        }
    }

    return resultMtrx;
}

Matrix2x2 Matrix2x2::subtract(Matrix2x2 inputmtrx) {
    Matrix2x2 resultMtrx = { };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultMtrx.matrix[i][j] = { matrix[i][j] - inputmtrx.matrix[i][j] };
        }
    }

    return resultMtrx;
}

Matrix2x2 Matrix2x2::operator*(const Matrix2x2& right) {
    return multiply(right);
}

Matrix2x2& Matrix2x2::operator*=(const Matrix2x2& right) {
    Matrix2x2 resultMtrx = multiply(right);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}

Matrix2x2 Matrix2x2::operator/(const Matrix2x2& right) {
    return divide(right);
}

Matrix2x2& Matrix2x2::operator/=(const Matrix2x2& right) {
    Matrix2x2 resultMtrx = divide(right);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2& right) {
    return add(right);
}

Matrix2x2& Matrix2x2::operator+=(const Matrix2x2& right) {
    Matrix2x2 resultMtrx = add(right);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& right) {
    return subtract(right);
}

Matrix2x2& Matrix2x2::operator-=(const Matrix2x2& right) {
    Matrix2x2 resultMtrx = subtract(right);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrix[i][j] = resultMtrx.matrix[i][j];
        }
    }
    return *this;
}
