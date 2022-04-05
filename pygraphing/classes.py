from __future__ import annotations
import numpy as np

class Matrix2x2:
    def __init__(self, a, b, c, d):
        self.matrix = np.array([[a, b], [c, d]], dtype=float)

    def determinant(self):
        return (self.matrix[0][0] * self.matrix[1][1]) - (self.matrix[0][1] * self.matrix[1][0])


class Vector3:
    def __init__(self, X, Y, Z):
        self.x = X
        self.y = Y
        self.z = Z

    def crossproduct(self, rhs: Vector3):
        i_matrix = Matrix2x2(self.y, self.z, rhs.y, rhs.z)
        j_matrix = Matrix2x2(self.x, self.z, rhs.x, rhs.z)
        k_matrix = Matrix2x2(self.x, self.y, rhs.x, rhs.y)

        return Vector3(i_matrix.determinant(), -j_matrix.determinant(), k_matrix.determinant())

    def scale(self, value: float):
        return Vector3(value*self.x, value*self.y, value*self.z)

    def dotproduct(self, rhs: Vector3):
        return self.x*rhs.x + self.y*rhs.y + self.z*rhs.z

    def subtract(self, rhs: Vector3):
        return Vector3(self.x - rhs.x, self.y - rhs.y, self.z - rhs.z)

    def magnitude(self):
        return np.sqrt(self.x*self.x + self.y*self.y + self.z*self.z)

    def angle(self, rhs: Vector3):
        magnitudes = self.magnitude() * rhs.magnitude()
        print(float(np.arccos(self.dotproduct(rhs) / magnitudes)) * (180/np.pi))
        return float(np.arccos(self.dotproduct(rhs) / magnitudes))

    def unitvector(self):
        Result = Vector3(self.x/self.magnitude(), self.y/self.magnitude(), self.z/self.magnitude())
        print(Result.x)
        print(Result.y)
        print(Result.z)
        return Result
