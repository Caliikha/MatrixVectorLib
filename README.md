# MatrixVectorLib
This is a collection of files for a beginner project i am trying to develop

The worst attempt of making a Matrix and Vector library that you've ever seen. For learning purposes

If you are interested in breaking things, you can go ahead and test the functions in the various classes

You can take a look at the main.cpp file for a walk-through on what you can do with this library

# How to run
You will need to compile in a standard no older than C++17 

If you are using a linux terminal. Use the following command:

    g++ -std=c++17 -g -o run Main.cpp ./Vector2.cpp ./Vector3.cpp ./Vector4.cpp ./Matrix2x2.cpp ./Matrix3x3.cpp ./Matrix4x4.cpp && ./run && rm run 
    
If the terminal does not run the command, try installing or updating g++

    sudo apt install build-essential

If you are using a separate IDE (e.g Visual Studio). Follow these steps:

    -> Copy all files to a newly made project folder (where Main.cpp or Source.cpp resides)
    -> Check all files for possible erros with includes or preprocessor macros, 
         If errors exist: ~edit accordingly to follow windows directory standard
    -> Run the program using your own start file

# Known Issues/Bugs

Matrix4x4::determinant() function is not fully developed, will return incorrect values

Matrix4x4::inverse() function is not fully developed, will return incorrect values

Matrix4x4::divide() function is not fully developed, will return incorrect values

vector4::rotate() incorrect mathematics used, will return incorrect values

vector4::testrotate() incorrect mathematics used, will return incorrect values



# Future Implementation

-> Adding vector addition and subtraction operations

-> Adding vector cross product operation

-> Adapting existing code for a new Matrix3x3 class with existing Matrix4x4 class operations

-> Adapting existing code for a new Vector3 class with existing Vector4 class operations

-> Adapting existing code for a new Vector2 class with existing Vector3 class operations

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
