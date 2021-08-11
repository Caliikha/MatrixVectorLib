/*
				This main function will only hold variables and objects for you to test the functionality
				of each method/feature in each class. If you are looking for a place to start understanding
				this wonky and badly made codebase, i'll be making an addition on the README file soon

		A mini-tutorial will be included at the bottom of the main() function if you need a refresher on different types of matricies
					Some resources on the mathematics behind matricies will also be provided

					for now, enjoy messing with the values and try to break my code

				I'd wish you good luck, but i know it's super easy to break this/find problems
*/

#include "Matrix4x4.h"
#include "Matrix3x3.h"
#include "Matrix2x2.h"
#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"

//          Keep in mind that C++17 is required to build this library 

//			If you wish to test each showcase individually, i recommend commenting out the rest of the code in main() and going through it part-by-part
//			running this will just output a bunch of vectors and matricies, so it won't make sense unless you comment out the parts you're not focussing on


int main()
{
	float ROTATION_ANGLE = PI / 2;
	float TRANSLATION_MAGNITUDE = 10.0f;
	float SCALE_MAGNITUDE = 2.0f;
	
	Vector4 _Vctr1 = { 1, 2, 3, 4 }; // assign the values of your vector here
	Vector4 Vctr2 = { 1, 2, 3, 4 }; // second vector for you to test some vector methods
    	Vector2 Vctr_2d = { 1, 2 };
	Vector2 Vctr_2d_2 = {2, 1};
	Vector3 Vctr_3d = {1, 2, 3};
	Vector3 Vctr_3d_2 = {0, 1, 0};

	//					beginning matrix + vector related operations

	Matrix4x4 Xmtrx = {
		1,		0,		0,		0,
		0, cos(ROTATION_ANGLE), -sin(ROTATION_ANGLE),	0,
		0, sin(ROTATION_ANGLE), cos(ROTATION_ANGLE),	0,
		0,		0,		0,		1
	};
	// You can repeat all of this with a rotation about X, Y, or Z, if you want to test those out, example matricies are listed under the main() function
	// Rotating _Vctr1 about the X axis given the angle set by the variable ROTATION_ANGLE, change the varible's value if you want to change the angle
	
	//_Vctr1.rotate(Xmtrx).printvector(); // DISCLAIMER: all rotate functions are bugged, it will be worked on
    	// Underneath is an example of how to use the rotate() function for 2D Vectors
    	Matrix2x2 Rotationmtrx_2D = {
        	cos(ROTATION_ANGLE),-sin(ROTATION_ANGLE),
        	sin(ROTATION_ANGLE), cos(ROTATION_ANGLE)
    	};
	
	// you can assign the value of the rotated vector to your original vector, like this _Vctr1 = _Vctr1.rotate(Xmtrx);, then you can _Vctr1.printvector(); in a new line

	Matrix4x4 Translatemtrx = { // matrix to translate X, Y, Z, and W values of vector
		1,	0,	0,	TRANSLATION_MAGNITUDE,
		0,	1,	0,	TRANSLATION_MAGNITUDE,
		0,	0,	1,	TRANSLATION_MAGNITUDE,
		0,	0,	0,	TRANSLATION_MAGNITUDE
	};

	_Vctr1.translate(Translatemtrx).printvector(); // 

	Matrix4x4 Scalemtrx = { // matrix to scale the vector given the scale magnitude
		SCALE_MAGNITUDE,	0,	0,	1,
		0,	SCALE_MAGNITUDE,	0,	1,
		0,	0,	SCALE_MAGNITUDE,	1,
		0,	0,	0,	SCALE_MAGNITUDE
	};

	_Vctr1.scale(Scalemtrx).printvector(); // DISCLAIMER: there are two scale functions, one using a matrix, another where you can pass in a float value to increase all components of the vector by that scale
	_Vctr1.scale(5.0f); // second way of calling the scale() method


	//					Beginning purely vector operations

	_Vctr1 = { 1, 0, 0, 0 }; // new initializations to illustrate vector functions
	Vctr2 = { 0, 1, 0, 0 }; 

	// using cout for now, but will make a printing function in the future
	std::cout << _Vctr1.dotproduct(Vctr2) << "\n"; // the function returns the dot product of these two vectors
	// or you can use the showResult() function for this
    	Vector4::showResult(_Vctr1.dotproduct(Vctr2)); // show result can be used for any type, including custom Vector and Matrix types
	// with the default initializations above, you expect the value 1 here
    
	Vector4::showResult(_Vctr1.magnitude()); // function that returns the magnitude of the local vector

	std::cout << _Vctr1.angle(Vctr2) << "\n"; // the function returns the angle between the two vectors using the dot product
	// with the default initializations above, you expect the value 90.0f here, (returns in degrees)
    		
	_Vctr1.resultant(Vctr2).printvector(); // and you can call resultant() to find the resultant of the local and inputted vectors
	
    	_Vctr1.add(Vctr2).printvector(); // here is an addition function that will simply add each of the values of the components of each vector

    	_Vctr1.subtract(Vctr2).printvector(); // likewise, here is a subtraction function that will subtract each value of the components of each vector

    	_Vctr1.translate(Translatemtrx).printvector(); // additionally, here is a translation function, for basic translation of vector bases with defined Translation matricies

	Vector3::showResult(Vctr_2d.crossproduct(Vctr_2d_2)); // this is a function that calculates the cross product of the local vector x the input vector, and returns a 3D vector
	
	Vctr_3d.crossproduct(Vctr_3d_2).printvector(); // this function returns the result of the cross product of the local x input vectors, also returns a 3D vector
	
	_Vctr1.unitvector().printvector(); // this function returns the unit vector in the direction of the local vector
	// you can also do the same for 3d or 2d vectors
	    
	// operators can also be used to represent vector-matrix multiplication, however for it to work you must have the vector on the left and matrix on the right
    
	Matrix4x4 ProductMtrx_4x4 = { // matrix to show the vector matrix product
		2, 3, -4, 3,
		11, 8, 7, 4,
		2, 5, 3, 2,
		1, 3, 6, 2
	};
	_Vctr1 = {3, 7, 5, 4}; // reassigned values for ease of reference when testing with online calculators
	Vector4::showResult(_Vctr1 * ProductMtrx_4x4); // this can also be done for 3D*3x3 and 2D*2x2
	    
	// you can also commplete vector addition and subtraction using + and operators
	Vector4::showResult(_Vctr1 * _Vctr1); // the same as result = _Vctr1.crossproduct(_Vctr1);
	Vector4::showResult(_Vctr1 + _Vctr1); // the same as result = _Vctr1.add(_Vctr1);
	Vector4::showResult(_Vctr1 - _Vctr1); // the same as result = _Vctr1.subtract(_Vctr1);
	// keep in mind that the * operator for Vector4 objects can be confusing since there is quaternion multiplication and vector cross product, this might be changed in the future

	// you can also use *= += -= operators on these objects 
	// however DISCLAIMER! the Vector2 type does not have *= crossproduct equator since the returned value is a Vector3 type, it cannot be converted automatically without the user explicitly equating a V3 with a V2 * V2 line, something like V3 = V2 * V2
	_Vctr1 += _Vctr1;
	_Vctr1.printvector(); // the same as _Vctr1 = _Vctr1.add(_Vctr1);
	_Vctr1 -= _Vctr1;
	_Vctr1.printvector(); // the same as _Vctr1 = _Vctr1.subtract(_Vctr1);
	_Vctr1 *= _Vctr1;
	_Vctr1.printvector(); // the same as _Vctr1 = _Vctr1.crossproduct(_Vctr1);
    
	_Vctr1 = {3, 7, 5, 4}; // reassigned values for ease of reference when testing with online calculators
	// a standard "power" operation can also be used, with the special case that ^(-1) is interpreted as the inverse of the function
	// keep in mind that the inverse is only focused on quaternions, not vectors
	Vector4::showResult(_Vctr1^(3)); // same as taking the power to 3 of all components
	Vector4::showResult(_Vctr1^(-1));
	
	// some other functions you can use are:
    	//Vector4::input(_Vctr1); // allows inputting values during run-time

	
	    //                          VERY LARGE DISCLAIMER!!!!!!!!!
    /* 
     * You may already know that there are a number of operations that would
     * normally be done on 2D vectors that are still not ready yet for this
     * library, that would be because of many mathematical issues with such
     * operations on 4D and 3D vectors
     *
     * There is a mathematical concept/field called 'Quaternions', these
     * quaternions are the basis of how many of these operations can be
     * completed, such as with rotation of a 3D vector, it can only be done
     * correctly with quaternions
     *
     * Quaternions are modeled as a real number + 3 imaginary numbers, such as
     * R + i + j + k
     * you may recognize this as your basic ijk vectors from physics, but with
     * an additional real number
     *
     * In this library, the Vector4 class can be modeled as both a normal 4D
     * vector, or as a quaternion where the R real number is the W axis
     * of the vector, so i j k R corresponds with x y z w respectively
     *
     * Now underneath, i will show you how you can specifically make operations
     * on only the i j k aka imaginary part of the quaternion, without
     * affecting the real part for 3D vector operations (as specific to your
     * operation)
     *
     * This is all using templates and C++17 and above specific concepts, so
     * you will need to have C++17 to compile this with no errors or warnings
     * */

    
	//					Beginning Quaternion/Vector4 related operations/classifications 

    	Vector4 Quaternion = {1, 2, 3, 1}; // i = x = 1 | j = y = 2 | k = z = 3 | w = R/Real = 1
    	Vector4 NormalVector_4D = {1, 2, 3, 1}; // x, y, z, w | normal 4D vector
    	Vector3 NormalVector_3D = {1, 2, 3}; // x, y, z | normal 3D vector

    	// This quaternion is modeled as a 3D vector + a real number, therefore,
    	// whenever you try to for example, rotate the quaternion, you would be
    	// doing that operation on the 3D vector portion, not affecting the Real
    	// portion. Otherwise, if you WANT to affect the real portion, then you
    	// could model it as a 4D vector and use it just like any other class in
    	// this library
    
    	// Vector4::input(Quaternion); // you can use this input function just like other classes   

    	Vector4::showResult(Quaternion.w); // showResult function works like any other, you can input any type, including vectors and matricies
    	Vector4::showResult(Quaternion);
    
    	Vector4::showResult(NormalVector_4D.dotproduct(NormalVector_4D)); // this is just the normal way to call dotproduct() on a 4D vector
    	Vector4::showResult(Quaternion.dotproduct<Vector3>(NormalVector_3D)); // this call ONLY ACTS ON THE 3D VECTOR PORTION OF THE QUATERNION/4DVECTOR
    	// to only affect the 3D portion, you should put the <Vector3> template infront of the function
    
    	// so, basically to only affect the ijk portion of the quaternion, add <Vector3> infront of the function name when calling
	    
	// to display your quaternion in the mathematical/normal format that most people are used to, you can also use .printquaternion()
	Quaternion.printquaternion();

    	// you can also input a 3D vector (if you are only affecting ijk or the Vector portion of the Quaternion, like shown below

    	Vector4::showResult(Quaternion.magnitude<Vector3>()); // only calculates magnitude of 3D vector portion
    	Vector4::showResult(NormalVector_4D.magnitude()); // calculates magnitude of whole 4D vector
    
    	// This goes on for angle(), resultant(), add(), subtract() and so on

    	// The only difference from here is the interactions with matricies

    	Matrix3x3 Scalemtrx_3x3 = {
        	SCALE_MAGNITUDE, 0, 0,
        	0, SCALE_MAGNITUDE, 0,
        	0, 0, SCALE_MAGNITUDE
    	};

    	Matrix4x4 Scalemtrx_4x4 = {
        	SCALE_MAGNITUDE, 0, 0, 0,
        	0, SCALE_MAGNITUDE, 0, 0,
        	0, 0, SCALE_MAGNITUDE, 0,
        	0, 0, 0, SCALE_MAGNITUDE
    	};

    	Vector4::showResult(Quaternion.scale<Vector3>(Scalemtrx_3x3)); // this will scale the 3D vector portion only
    	Vector4::showResult(NormalVector_4D.scale(Scalemtrx_4x4)); // this will scale like any normal 4D vector

    	// this is also the same for translate(), where you can separate the real portion with the vector portion

    	Matrix4x4 Translatemtrx_4x4 = {
        	1, 0, 0, TRANSLATION_MAGNITUDE,
        	0, 1, 0, TRANSLATION_MAGNITUDE,
        	0, 0, 1, TRANSLATION_MAGNITUDE,
        	0, 0, 0, TRANSLATION_MAGNITUDE
    	};

    	Matrix3x3 Translatemtrx_3x3 = {
        	1, 0, TRANSLATION_MAGNITUDE,
        	0, 1, TRANSLATION_MAGNITUDE,
        	0, 0, TRANSLATION_MAGNITUDE
    	};

    	Vector4::showResult(Quaternion.translate<Vector3>(Translatemtrx_3x3));
    	Vector4::showResult(NormalVector_4D.translate(Translatemtrx_4x4));
    
	_Vctr1.crossproduct(Vctr2).printvector(); // this function will return the cross product of local x input
	// since 4D vectors don't really have cross products, the actual result is a 3D vector
	// however this does not mean that the return type is a 3D vector
	// since you can deal with quaterinions, if you use 4D only, you will return a quaternion with the same Real value as your local vector but the cross product of the returned 3D vector portion    
	// underneath is a showcase of the different call methods

	_Vctr1.crossproduct(Vctr_3d).printvector(); // returns only Vector3 cross product
	_Vctr1.crossproduct(Vctr2).printvector(); // returns quaterinion with result as 3D vector portion of the quaternion, and Real value of local vector4
	// you can also use a template to make it more clear
	_Vctr1.crossproduct<Vector3>(Vctr_3d).printvector();
	
	_Vctr1.multiply(Quaternion).printquaternion(); // completes quaternion multiplication with all components
	_Vctr1.multiply<Vector3>(Quaternion).printquaternion(); // completes quaternion multiplication with only ijk components
	
	// you can also call functions to return the conjugate and inverse of the relevant quaternion (remember that this operation would only make sense on quaternions
	_Vctr1.conjugate().printquaternion();
	_Vctr1.inverse().printquaternion();
	// if you want to keep the R/Real/Scalar value of the quaternion the same as the origina, then you can add a Vector3 template argument like below
	_Vctr1.inverse<Vector3>().printquaternion();
	
	_Vctr1.unitvector().printvector(); // you can return the unit vector with this call
	// however, if you only want to affect the 3d Vector within (ijk) and not the scalar, add a Vector3 template argument
	_Vctr1.unitvector<Vector3>().printvector();
	
	// or you can simply call unitquaternion if you prefer that syntax over the default unitvector() function
	_Vctr1.unitquaternion().printquaternion(); // == _Vctr1.unitvector();

    	// that is a basic showcase of the Quaternion/4D Vector differences in this
    	// library, i definitely do recommend searching and learning more about
    	// Quaternions because it is not possible to summarize all its properties
    	// in documentation

	
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
	_Mtrx1_4x4 =_Mtrx1_4x4.identity();
	_Mtrx1_4x4.printmtrx();

	// if you are performing an operation that is not necassarily based on a matrix object, you can also use this call to print the matrix
	Matrix4x4::showResult(_Mtrx1_4x4);

	// you can input at run time using this call
    	//Matrix4x4::input(_Mtrx1_4x4);
	
    	Matrix2x2::showResult(_Mtrx1_2x2.determinant()); // function that calculated the determinant of the matrix, and the printvalue function is just a standard cout based function that accepts typename datatypes

	_Mtrx1_2x2.inverse().printmtrx(); // function that returns the inverse of the matrix

	_Mtrx1_4x4.scale(5.0f).printmtrx(); // scales all values of the mtrx by the passed float value

    	_Mtrx1_4x4.transpose().printmtrx(); // transposes the local matrix (aka flipping values by the diagonal)

    	Matrix4x4::showResult(_Mtrx1_4x4.trace()); // returns the trace of the local matrix (aka adds up the diagonal values of the matrix)

	Matrix4x4::showResult(_Mtrx1_4x4.multiply(Mtrx2_4x4)); // DISCLAIMER: you should know that matrixA x matrixB is not the same as matrixB x matrixA, so this function uses the object as A and passed matrix as B, so it is OBJECT x INPUT
	Matrix2x2::showResult(_Mtrx1_2x2.divide(Mtrx2_2x2)); // If you are wondering about division, it just takes the inverse of the input, and multiplies OBJECT x INVERSE_INPUT
	Matrix4x4::showResult(_Mtrx1_4x4.add(Mtrx2_4x4)); // just adds the values of the vectors
	Matrix4x4::showResult(_Mtrx1_4x4.subtract(Mtrx2_4x4)); // simple matrix subtraction
	
	// in relation to the past few functions you can use your standard c++ operators to call certain functions, for example
	Matrix4x4::showResult(_Mtrx1_4x4 * Mtrx2_4x4); // this acts the same as result = _Mtrx1_4x4.multiply(Mtrx2_4x4);
	Matrix4x4::showResult(_Mtrx1_4x4 + Mtrx2_4x4); // acts the same as result = _Mtrx1_4x4.add(Mtrx2_4x4);
	Matrix4x4::showResult(_Mtrx1_4x4 - Mtrx2_4x4); // acts the same as result = _Mtrx1_4x4.subtract(Mtrx2_4x4);
	// you can also use division but only for Matrix2x2 for now since the inverse() function is not ready yet for 3x3 and 4x4 matricies
	Matrix2x2::showResult(_Mtrx1_2x2 / Mtrx2_2x2); // acts the same as result = _Mtrx1_2x2.divide(Mtrx2_2x2);
	
	// additionally, just like with vectors, you can also use *=, /=, +=, and -= operators on your matricies
	// keep in mind, that for now only Matrix2x2 objects may use the division operator
	_Mtrx1_4x4 += Mtrx2_4x4;
	_Mtrx1_4x4.printmtrx(); // the same as _Mtrx1_4x4 = _Mtrx1_4x4.add(Mtrx2_4x4);
	_Mtrx1_4x4 -= Mtrx2_4x4;
	_Mtrx1_4x4.printmtrx(); // the same as _Mtrx1_4x4 = _Mtrx1_4x4.subtract(Mtrx2_4x4);
	_Mtrx1_4x4 *= Mtrx2_4x4;
	_Mtrx1_4x4.printmtrx(); // the same as _Mtrx1_4x4 = _Mtrx1_4x4.multiply(Mtrx2_4x4);
	// and for only Matrix2x2 for now
	_Mtrx1_2x2 /= Mtrx2_2x2;
	_Mtrx1_2x2.printmtrx(); // the same as _Mtrx1_2x2 = _Mtrx1_2x2.divide(Mtrx2_2x2);

	
	//			You can repeat all of these operations with the 2x2, 3x3, or 4x4  matrix libarary, i will not list them here as it is just a showcase
    	//			Keep in mind that there are a few functions that are not yet developed in the 3x3 and 4x4 classes, such as determinant() or inverse()	
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
