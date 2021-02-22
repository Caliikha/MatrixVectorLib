#include <iostream>
#include "Matrix2x2.cpp"
#include "Matrix4x4.cpp"
#include "Vector4_Temp.cpp"
//#include <chrono> 
#define PI 3.1415926535

int main()
{
	vector4 vctr = { 1, 2, 3, 4 };

	Matrix4x4 Xmtrx = { // Rotation matrix about X axis
		1,		0,		0,		0,
		0, cos(PI/2), 		-sin(PI/2),		0,
		0, sin(PI/2), 		cos(PI/2),		0,
		0,		0,		0,		1
	};
	Matrix4x4 Ymtrx = { // Rotation matrix about Y axis
		cos(PI / 2), 0, sin(PI / 2), 			0,
		0,		1,		0,		0,
		-sin(PI / 2), 0, cos(PI / 2), 			0,
		0,		0,		0,		1
	};
	Matrix4x4 Zmtrx = { // Rotation matrix about Z axis
		cos(PI / 2), -sin(PI / 2), 	0, 		0,
		sin(PI / 2), cos(PI / 2), 	0, 		0,
		0,		0,		1,		0,
		0,		0,		0,		1
	};
	Matrix4x4 Translatemtrx = { // Translation matrix
		1,	0,	0,	10,
		0,	1,	0,	10,
		0,	0,	1,	10,
		0,	0,	0,	1
	};
	Matrix4x4 Scalemtrx = { // Scale matrix
		2,	0,	0,	1,
		0,	2,	0,	1,
		0,	0,	2,	1,
		0,	0,	0,	1
	};

	//Matrix4x4 Trans = Xmtrx.multiply(Ymtrx.multiply(Zmtrx));

	vctr.translate(Translatemtrx).printvector();
}
