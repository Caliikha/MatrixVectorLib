#include <iostream>
#include "./MatrixFiles/Matrix2x2.h"
#include "./MatrixFiles/Matrix3x3.h"
#include "./MatrixFiles/Matrix4x4.h"
//#include "./MatrixFiles/Dyn_Matrix.h"
#include "./VectorFiles/Vector4.h"
#include "./VectorFiles/Vector3.h"
#include "./VectorFiles/Vector2.h"
//#include "./VectorFiles/Dyn_Vector.h"
//#include "./VectorFiles/vector-experiment.h"
//#include <chrono>
//#include "DynVector.cpp"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342
#include <cmath>
#include <fstream>
#include "./VectorFiles/Quaternion.h"

template <class vectype = Vector3>
std::ofstream& printV(std::ofstream& outputfile, const vectype outputvector){
    if (!outputfile) { std::cerr << "error while outputting to file\n";}
    static int num_calls = 0;
    num_calls++;
    outputfile << outputvector.x<<", "<<outputvector.y<<", "<<outputvector.z<<'\n';
    //std::cout << num_calls << '_';
    return outputfile;
}

int main()
{
    Quaternion ex = {1, 2, 3, 4};
    //Quaternion::showResult(ex.dotproduct(Vector4(1, 1, 0, 0)));
    //Vector4* ptr = &ex;
    //Quaternion::showResult(ptr->dotproduct(Vector4(1, 1, 0, 0)));
    Quaternion::showResult(ex.dotproduct(ex));
    std::cout << "================================================\n";
    Quaternion A = Quaternion{0, 1, 1, 0}.unitquaternion();
    A.printquaternion();
    Quaternion E = {0, 3, 0, 0};

    Quaternion::showResult(A * E * A.inverse());
    std::cout << "--------\n";

    std::ofstream outputfile("./pygraphing/testgraphing.txt");

    Vector3 Vq = Vector3{0, 0, 1}.unitvector();
    Vector3 v = Vector3{1, -2, 1}.unitvector();
    float theta = 3*PI;
    
    Vector3::showResult(Vq.crossproduct(v).crossproduct(Vq.scale(-1)));
    Vector3::showResult(Vq.scale(-1*Vq.dotproduct(v))
                       .subtract(
                        Vq.scale(v.dotproduct(Vq.scale(-1)))));


    A = Vq;
    E = v;
    Vector3::showResult(static_cast<Vector3>(A.crossproduct<Vector3>(E).crossproduct<Vector3>(A.inverse())));
    Vector3::showResult(static_cast<Vector3>(
                A.inverse().scalef(A.dotproduct<Vector3>(E)))
            .subtract(
                A.scalef(A.inverse().dotproduct<Vector3>(E))));

    outputfile.close();
    outputfile = std::ofstream("interpolation.txt");

    Quaternion Vq_q;
    Quaternion v_q = v;
    int steps = 50;
//    for (int i = 0; i < steps; i++){
//        float temp_angle = i*(theta/steps);
//        Vq_q = Quaternion(-sin(temp_angle/2), Vq.unitvector().scale(cos(temp_angle/2)));
//        Vector3 data = Vq_q * v_q * Vq_q.inverse();
//        printV(outputfile, data);
//    }
    for (int i = 0; i < steps; i++){
        float temp_angle = i*(theta/steps);
        //Vector3 data = (Vq.crossproduct(v).crossproduct(Vq.scale(-1)).add(Vq.scale(Vq.dotproduct(v)))).scale(cos(temp_angle)*cos(temp_angle)).add((v.crossproduct(Vq).scale(2*sin(temp_angle)*cos(temp_angle)))).add(v.scale(sin(temp_angle)*sin(temp_angle)));
        //Vector3 data = (Vq.crossproduct(v).crossproduct(Vq.scale(-1))).add(Vq.scale(Vq.dotproduct(v))).scale(cos(temp_angle)*cos(temp_angle)).add((v.crossproduct(Vq).scale(2*sin(temp_angle)*cos(temp_angle)))).add(v.scale(sin(temp_angle)*sin(temp_angle)));
        Vector3 data = {temp_angle-1.5*PI, sin(temp_angle), 0};
        printV(outputfile, data);
    }

    //Vector3::showResult((Vq.crossproduct(v).crossproduct(Vq.scale(-1))
    //                      + Vq.scale(Vq.dotproduct(v))).scale(cos(theta)*cos(theta))
    //                      + Vq.crossproduct(v).scale(2*sin(theta)*cos(theta))
    //                      + v.scale(sin(theta)*sin(theta)));


    //Vector3 Basis[3] = {Vector3(1, 1, 1), Vector3(0, 1, 1), Vector3(0, 0, 2)};
    //Vector3 O[3];
    //Matrix3x3 mat = {
    //    Basis[0].x, Basis[0].y, Basis[0].z,
    //    Basis[1].x, Basis[1].y, Basis[1].z,
    //    Basis[2].x, Basis[2].y, Basis[2].z,
    //};
    //std::cout << "determinant test results in: " << mat.determinant() << "\n";
    //for (int i = 0; i < 3; i++){
    //    O[i] = Basis[i];
    //    for (int j = 0; j < i; j++){
    //        O[i] -= O[j].scale(Basis[i].dotproduct(O[j])/O[j].dotproduct(O[j]));
    //    }
    //    O[i] = O[i].unitvector();
    //}

    //std::cout << "Basis:\n";
    //for (int i = 0; i < 3; i++){
    //    Basis[i].printvector();
    //    printV(outputfile, Basis[i]);
    //}
    //std::cout << "O:\n";
    //for (int i = 0; i < 3; i++){
    //    O[i].printvector();
    //    printV(outputfile, O[i]);
    //}
    //outputfile.close();
}
//	Matrix4x4 Translatemtrx; /*= {
//		1,	0,	0,	10,
//		0,	1,	0,	10,
//		0,	0,	1,	10,
//		0,	0,	0,	1
//	};*/
//	Matrix4x4 Scalemtrx = {
//		2,	0,	0,	1,
//		0,	2,	0,	1,
//		0,	0,	2,	1,
//		0,	0,	0,	1
//	};
//
//	Matrix2x2 X2x2; /*{
//		cos(PI), -sin(PI),
//		sin(PI), cos(PI)
//	};*/
//
//	Matrix3x3 X3x3{
//		1, 0, 0,
//		0, 1, 0,
//		0, 0, 1
//	};

/*std::cout << vctr.dotproduct(vctr.resultant(vctr1)) << "\n";

  std::cout << vctr.angle(vctr.resultant(vctr1));*/
//
// add walkthrough with rotate() for 2x2 
//
//
//
//CML::Matrix2x2 Matrix1;
//
//Matrix1.define(1, 2, 3, 4);
//
//auto Tstart = std::chrono::high_resolution_clock::now();
//Matrix1.multiply(Matrix1);
//auto Tend = std::chrono::high_resolution_clock::now();
//std::chrono::duration<float> duration = Tend - Tstart;
//auto NEWrate = 1 / duration.count();
//std::cout << "New: " << duration.count() << "\n\n";
//
//Matrix Matrix2;
//
//Matrix2.define(1, 2, 3, 4);
//
//Tstart = std::chrono::high_resolution_clock::now();
//Matrix2.multiply(Matrix2);
//Tend = std::chrono::high_resolution_clock::now();
//duration = Tend - Tstart;
//auto OGrate = 1 / duration.count();
//std::cout << "Old: " << duration.count() << "\n\n";
//
//std::cout << "Rate improvement Old/New: " << ((OGrate / NEWrate) * 100) - 100 << "%";
//
//
//for (int i = 0; i < 10; i++) {
//	CML::Matrix2x2 mtrx;
//
//	mtrx.define(1, 2, 3, 4);
//
//	auto start = std::chrono::high_resolution_clock::now();
//	mtrx.multiply(mtrx);
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<float> duration = end - start;
//	float RATE2 = 1 / duration.count();
//
//	std::cout << duration.count() * 1000.0f << "ms  " << RATE2 << "ms^-1" << "\n\n";
//
//	CML::Matrix4x4 mtrx4 = {
//		1, 2, 3, 4,
//		5, 6, 7, 8,
//		9, 10, 11, 12,
//		13, 14, 15, 16
//	};
//
//	start = std::chrono::high_resolution_clock::now();
//	mtrx4.multiply(mtrx4);
//	end = std::chrono::high_resolution_clock::now();
//	duration = end - start;
//	float RATE4 = 1 / duration.count();
//
//	std::cout << duration.count() * 1000.0f << "ms  " << RATE4 << "s^-1" << "\n\n";
//
//	std::cout << ((RATE2 / RATE4) * 100) - 100 << "%" << "\n\n";
//}
