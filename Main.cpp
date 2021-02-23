/*
				This main function will only hold variables and objects for you to test the functionality
				of each method/feature in each class. If you are looking for a place to start understanding
				this wonky and badly made codebase, i'll be making an addition on the README file soon

		A mini-tutorial will be included at the bottom of the main() function if you need a refresher on different types of matricies
					Some resources on the mathematics behind matricies will also be provided

					for now, enjoy messing with the values and try to break my code

				I'd wish you good luck, but i know it's super easy to break this/find problems
*/

#include "Matrix4x4.cpp"
#include "Matrix2x2.cpp"
#include "Vector4.cpp"
#define PI 3.1415926535

//			If you wish to test each showcase individually, i recommend commenting out the rest of the code in main() and going through it part-by-part
//			running this will just output a bunch of vectors and matricies, so it won't make sense unless you comment out the parts you're not focussing on

int main()
{
	float ROTATION_ANGLE = PI / 2;
	float TRANSLATION_MAGNITUDE = 10.0f;
	float SCALE_MAGNITUDE = 2.0f;

	vector4 _Vctr1= { 1, 2, 3, 4 }; // assign the values of your vector here
	vector4 Vctr2 = { 1, 2, 3, 4 }; // second vector for you to test some vector methods
	
	//					beginning matrix + vector related operations

	Matrix4x4 Xmtrx = {
		1,		0,		0,		0,
		0, cos(ROTATION_ANGLE), -sin(ROTATION_ANGLE),	0,
		0, sin(ROTATION_ANGLE), cos(ROTATION_ANGLE),	0,
		0,		0,		0,		1
	};
	// You can repeat all of this with a rotation about X, Y, or Z, if you want to test those out, example matricies are listed under the main() function
	// Rotating _Vctr1 about the X axis given the angle set by the variable ROTATION_ANGLE, change the varible's value if you want to change the angle
	
	_Vctr1.rotate(Xmtrx).printvector(); // DISCLAIMER: all rotate functions are bugged, it will be worked on
	
	// you can assign the value of the rotated vector to your original vector, like this _Vctr1 = _Vctr1.rotate(Xmtrx);, then you can _Vctr1.printvector(); in a new line

	Matrix4x4 Translatemtrx = { // matrix to translate X, Y, and Z values of vector
		1,	0,	0,	TRANSLATION_MAGNITUDE,
		0,	1,	0,	TRANSLATION_MAGNITUDE,
		0,	0,	1,	TRANSLATION_MAGNITUDE,
		0,	0,	0,	1
	};

	_Vctr1.translate(Translatemtrx).printvector(); // 

	Matrix4x4 Scalemtrx = { // matrix to scale the vector given the scale magnitude
		SCALE_MAGNITUDE,	0,	0,	1,
		0,	SCALE_MAGNITUDE,	0,	1,
		0,	0,	SCALE_MAGNITUDE,	1,
		0,	0,	0,	1
	};

	_Vctr1.scale(Scalemtrx).printvector(); // DISCLAIMER: there are two scale functions, one using a matrix, another where you can pass in a float value to increase all components of the vector by that scale
	_Vctr1.scale(5.0f); // second way of calling the scale() method


	//					Beginning purely vector operations

	_Vctr1 = { 1, 0, 0, 0 }; // new initializations to illustrate vector functions
	Vctr2 = { 0, 1, 0, 0 }; 

	// using cout for now, but will make a printing function in the future
	std::cout << _Vctr1.dotproduct(Vctr2) << "\n"; // the function returns the dot product of these two vectors
	// with the default initializations above, you expect the value 1 here


	std::cout << _Vctr1.angle(Vctr2) << "\n"; // the function returns the angle between the two vectors using the dot product
	// with the default initializations above, you expect the value 90.0f here, (returns in degrees)
	

	_Vctr1.resultant(Vctr2).printvector(); // the function returns the resultant vector of the object the method is called from, and the input vector


	// since the default values of the vectors are only in 2D for illustration, the resultant will be at a 45 degree angle, and we can check if everything works correctly with this call:
	std::cout << _Vctr1.angle(_Vctr1.resultant(Vctr2));
	// with the default initializations above, you expect this to take the angle of the resultant of those two vectors, which would be 45 degrees


	// some other functions you can use are:
	// _Vctr1.input(); // allows inputting values during run-time


	//					Beginning purely Matrix related operations


	Matrix2x2 _Mtrx1_2x2 = {
		1, 2,
		3, 4
	};

	Matrix2x2 Mtrx2_2x2 = {
		1, 2,
		3, 4
	};
	
	Matrix4x4 _Mtrx1_4x4 = {
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16
	};

	Matrix4x4 Mtrx2_4x4 = {
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16
	};

	// you can define a matrix to be the identity matrix using this call:
	_Mtrx1_4x4.identity();
	_Mtrx1_4x4.printmtrx();

	// if you are performing an operation that is not necassarily based on a matrix object, you can also use this call to print the matrix
	Matrix4x4::showResult(_Mtrx1_4x4);

	// you can input at run time using this call
	// _Mtrx1_4x4.input();
	_Mtrx1_4x4.printvalue(_Mtrx1_4x4.determinant()); // function that calculated the determinant of the matrix, and the printvalue function is just a standard cout based function that accepts typename datatypes

	_Mtrx1_4x4.inverse().printmtrx(); // function that returns the inverse of the matrix

	_Mtrx1_4x4.scale(5.0f).printmtrx(); // scales all values of the mtrx by the passed float value

	Matrix4x4::showResult(_Mtrx1_4x4.multiply(Mtrx2_4x4)); // DISCLAIMER: you should know that matrixA x matrixB is not the same as matrixB x matrixA, so this function uses the object as A and passed matrix as B, so it is OBJECT x INPUT
	Matrix4x4::showResult(_Mtrx1_4x4.divide(Mtrx2_4x4)); // If you are wondering about division, it just takes the inverse of the input, and multiplies OBJECT x INVERSE_INPUT
	Matrix4x4::showResult(_Mtrx1_4x4.add(Mtrx2_4x4)); // just adds the values of the vectors
	Matrix4x4::showResult(_Mtrx1_4x4.subtract(Mtrx2_4x4)); // simple matrix subtraction


	//				You can repeat all of these operations with the 2x2 matrix libarary, i will not list them here as it is just a showcase
}

//					For testing the calculations of these functions, i recommend using this website to see if all the operations make sense: https://academo.org/demos/3d-vector-plotter/

/*
	Types of translation matricies (acting on Vectors):


		Rotation matrix about the X axis: 

	Matrix4x4 Xmtrx = {
		1,		0,		0,		0,
		0, cos(ANGLE_RADIANS), -sin(ANGLE_RADIANS),	0,
		0, sin(ANGLE_RADIANS), cos(ANGLE_RADIANS),	0,
		0,		0,		0,		1
	};

			Rotation matrix about the Y axis:
	Matrix4x4 Ymtrx = {
		cos(ANGLE_RADIANS), 0, sin(ANGLE_RADIANS), 0,
		0,		1,		0,		0,
		-sin(ANGLE_RADIANS), 0, cos(ANGLE_RADIANS), 0,
		0,		0,		0,		1
	};

			Rotation matrix about the Z axis:

	Matrix4x4 Zmtrx = {
		cos(ANGLE_RADIANS), -sin(ANGLE_RADIANS), 0, 0,
		sin(ANGLE_RADIANS), cos(ANGLE_RADIANS), 0, 0,
		0,		0,		1,		0,
		0,		0,		0,		1
	};

			Translation matrix:

	Matrix4x4 Translatemtrx = {
		1,	0,	0,	X_DIFFERENCE,
		0,	1,	0,	Y_DIFFERENCE,
		0,	0,	1,	Z_DIFFERENCE,
		0,	0,	0,	1
	};

			Scaling matrix:
		
	Matrix4x4 Scalemtrx = {
		X_SCALE, 0,		0,	1,
		0,	Y_SCALE,	0,	1,
		0,	0,		Z_SCALE,1,
		0,	0,			0,	1
	};


				RESOURCES ON VECTOR/MATRIX MATHEMATICS:

http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/#scaling-matrices

http://ksuweb.kennesaw.edu/~plaval/math4490/rotgen.pdf

http://www.opengl-tutorial.org/assets/faq_quaternions/index.html#Q27

https://academo.org/demos/3d-vector-plotter/

https://hepweb.ucsd.edu/ph110b/110b_notes/node2.html

http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/

http://www.opengl-tutorial.org/intermediate-tutorials/tutorial-17-quaternions/

phys.libretexts.org/Courses/University_of_California_Davis/UCD%3A_Physics_9HB__Special_Relativity_and_Thermal_Statistical_Physics/3%3A_Spacetime/3.1%3A_Vector_Rotations

https://static.lwn.net/images/pdf/LDD3/ch01.pdf
*/
