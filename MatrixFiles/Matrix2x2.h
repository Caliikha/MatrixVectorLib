// header file for Matrix2x2 object
// check Matrix2x2.cpp for implmenetations
#pragma once
#include <iostream>

class Vector2;

class Matrix2x2 {
private:
	static constexpr const int Rows = 2;
	static constexpr const int Cols = 2;
public:
	float matrix[Rows][Cols];

    inline Matrix2x2(
            const float& a0 = 0, const float& a1 = 0,
            const float& a2 = 0, const float& a3 = 0
            );

    inline static Matrix2x2 identity();
	void printmtrx() const;
    template <typename TYPE>
        static void showResult(const TYPE& input) { std::cout << input << '\n'; }
	static void showResult(const Matrix2x2& inputmtrx);
	static void input(Matrix2x2& inputmtrx);
	inline float determinant() const noexcept;
	inline Matrix2x2 inverse() const noexcept;
    inline Matrix2x2 transpose() const noexcept;
    inline float trace() const noexcept;
	inline Matrix2x2 scale(const float& scale) const noexcept;
	inline Matrix2x2 multiply(const Matrix2x2& inputmtrx) const noexcept;
	inline Matrix2x2 divide(const Matrix2x2& inputmtrx) const noexcept;
	inline Matrix2x2 add(const Matrix2x2& inputmtrx) const noexcept;
	inline Matrix2x2 subtract(const Matrix2x2& inputmtrx) const noexcept;
    inline Matrix2x2 operator*(const Matrix2x2& right) const noexcept;
    inline Matrix2x2& operator*=(const Matrix2x2& right) noexcept;
    inline Matrix2x2 operator/(const Matrix2x2& right) const noexcept;
    inline Matrix2x2& operator/=(const Matrix2x2& right) noexcept;
    inline Matrix2x2 operator+(const Matrix2x2& right) const noexcept;
    inline Matrix2x2& operator+=(const Matrix2x2& right) noexcept;
    inline Matrix2x2 operator-(const Matrix2x2& right) const noexcept;
    inline Matrix2x2& operator-=(const Matrix2x2& right) noexcept;
    inline const float* operator[](const int& index) const;
};
