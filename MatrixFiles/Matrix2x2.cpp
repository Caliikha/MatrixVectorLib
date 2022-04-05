#include "Matrix2x2.h"

Matrix2x2::Matrix2x2(
        const float& a0, const float& a1, 
        const float& a2, const float& a3
        )
{
    this->matrix[0][0] = a0; this->matrix[0][1] = a1;
    this->matrix[1][0] = a2; this->matrix[1][1] = a3;
}

Matrix2x2 Matrix2x2::identity() {
    return Matrix2x2
    {
        1, 0, 
        0, 1
    };
}

void Matrix2x2::printmtrx() const {
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

void Matrix2x2::showResult(const Matrix2x2& inputmtrx) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cout << inputmtrx.matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Matrix2x2::input(Matrix2x2& inputmtrx) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cin >> inputmtrx.matrix[i][j];
        }
    }
}

float Matrix2x2::determinant() const noexcept {
    return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
}

Matrix2x2 Matrix2x2::inverse() const noexcept {
    const float Constant = 1 / determinant();
    return Matrix2x2
    {
        Constant * matrix[1][1], Constant * -matrix[0][1],
        Constant * -matrix[1][0], Constant * matrix[0][0] 
    };
}

Matrix2x2 Matrix2x2::transpose() const noexcept {
    Matrix2x2 resultMtrx;

    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            resultMtrx.matrix[j][i] = matrix[i][j];
        }
    }

    return resultMtrx;
}

float Matrix2x2::trace() const noexcept {
    return (matrix[0][0] + matrix[1][1]);
}

Matrix2x2 Matrix2x2::scale(const float& scale) const noexcept {
    Matrix2x2 resultMtrx;

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            resultMtrx.matrix[i][j] = (scale * matrix[i][j]);
        }
    }

    return resultMtrx;
}

Matrix2x2 Matrix2x2::multiply(const Matrix2x2& inputmtrx) const noexcept {
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

Matrix2x2 Matrix2x2::divide(const Matrix2x2& inputmtrx) const noexcept {
    return multiply(inputmtrx.inverse());
}

Matrix2x2 Matrix2x2::add(const Matrix2x2& inputmtrx) const noexcept {
    Matrix2x2 resultMtrx;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultMtrx.matrix[i][j] = { matrix[i][j] + inputmtrx.matrix[i][j] };
        }
    }

    return resultMtrx;
}

Matrix2x2 Matrix2x2::subtract(const Matrix2x2& inputmtrx) const noexcept {
    Matrix2x2 resultMtrx;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultMtrx.matrix[i][j] = { matrix[i][j] - inputmtrx.matrix[i][j] };
        }
    }

    return resultMtrx;
}

Matrix2x2 Matrix2x2::operator*(const Matrix2x2& right) const noexcept {
    return this->multiply(right);
}

Matrix2x2& Matrix2x2::operator*=(const Matrix2x2& right) noexcept {
    return *this = this->multiply(right);
}

Matrix2x2 Matrix2x2::operator/(const Matrix2x2& right) const noexcept {
    return this->divide(right);
}

Matrix2x2& Matrix2x2::operator/=(const Matrix2x2& right) noexcept {
    return *this = this->divide(right);
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2& right) const noexcept {
    return this->add(right);
}

Matrix2x2& Matrix2x2::operator+=(const Matrix2x2& right) noexcept {
    return *this = this->add(right);
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& right) const noexcept {
    return this->subtract(right);
}

Matrix2x2& Matrix2x2::operator-=(const Matrix2x2& right) noexcept {
    return *this = this->subtract(right);
}

const float* Matrix2x2::operator[](const int& index) const {
    return this->matrix[index];
}
