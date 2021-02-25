# MatrixVectorLib
This is a collection of files for a beginner project i am trying to develop

The worst attempt of making a Matrix and Vector library that you've ever seen. For learning purposes

If you are interested in breaking things, you can go ahead and test the functions in the various classes

You can take a look at the main.cpp file for a walk-through on what you can do with this library


# Known Issues/Bugs

Matrix4x4::determinant() function is not fully developed, will return incorrect values

Matrix4x4::inverse() function is not fully developed, will return incorrect values

Matrix4x4::divide() function is not fully developed, will return incorrect values

vector4::rotate() incorrect mathematics used, will return incorrect values

vector4::testrotate() incorrect mathematics used, will return incorrect values


# Future Implementation

-> Implementing a trace() and transpose() function on all Matrix classes

-> Implementing a 3x3 Matrix class with basic functionality to be able to compute the determinant of the 4x4 matrix

-> After completing the determinant function for Matrix4x4, the determinant(), inverse(), and divide() functions will work correctly


# Additions since uploading Library

Added dotproduct() function to Vector4 class
    -> dotproduct(vector4 inputvctr) -> call on a vector4 object and input a second vector to return their dot product (returns float type)

Added angle() function to Vector4 class
    -> angle(vector4 inputvctr) -> call on a vector4 object and input a second vector to return the angle between them (returns float type) -> in degrees
    
Added reultant() function to Vector4 class
    -> resultant(vector4 inputvctr) -> call on a vector4 object and input a second vector to return the resultant vector (returns vector4 type)
    
Added Walk-through/Documentation main.cpp file for a clearer understand of how the library works
