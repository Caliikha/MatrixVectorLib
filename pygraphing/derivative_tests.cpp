#include <iostream>
#include "../MatrixFiles/Matrix2x2.h"
#include "../MatrixFiles/Matrix3x3.h"
#include "../MatrixFiles/Matrix4x4.h"
//#include "./MatrixFiles/Dyn_Matrix.h"
#include "../VectorFiles/Vector4.hpp"
#include "../VectorFiles/Vector3.hpp"
#include "../VectorFiles/Vector2.hpp"
//#include "./VectorFiles/Dyn_Vector.h"
//#include "./VectorFiles/vector-experiment.h"
//#include <chrono>
//#include "DynVector.cpp"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342
#include <cmath>
#include <fstream>
#include "../VectorFiles/Quaternion.hpp"

#define cross crossproduct
#define dot dotproduct

template <class vectype = Vector3>
std::ofstream& printV(std::ofstream& outputfile, const vectype outputvector){
    if (!outputfile) { std::cerr << "error while outputting to file\n";}
    static int num_calls = 0;
    num_calls++;
    outputfile << outputvector.x<<", "<<outputvector.y<<", "<<outputvector.z<<'\n';
    //std::cout << num_calls << '_';
    return outputfile;
}

inline constexpr Vector3 eth(const float& angle, Vector3 v, Vector3 q) {
    const float magn = v.magnitude();
    v = v.unitvector(); q = q.unitvector();
    return v.subtract(q.scale(q.dotproduct(v))).scale(cos(angle)).add(q.crossproduct(v).scale(sin(angle))).add(q.scale(q.dotproduct(v))).scale(magn);
    //return (v .subtract ( q.scale(v .dot (q) ).scale(cos(angle)) .add ( q .cross (v) ).scale(sin(angle)) .add ( q.scale(q .dot (v)) )) ) ;
}

inline Vector3 deth(const float& angle, Vector3 v, Vector3 q) {
    //const float magn = v.magnitude();
    v = v.unitvector(); q = q.unitvector();

    return (q .cross (v)).scale(2*cos(2*angle)) .add ((q.scale(v .dot (q)) .subtract (v)).scale(2*sin(2*angle)));
}

int main()
{
    std::ofstream outputfile = std::ofstream("interpolation.txt");

    //Quaternion Vq_q = Quaternion(1, 0, 0);
    //Quaternion v_q = Quaternion(0, 0, 1);
    Vector3 v = {0, 1, 0};
    Vector3 q = {0, 1, 1};
    const float constexpr theta = PI;
    printV(outputfile, v);
    printV(outputfile, q);
    v.rodrigues_rotate(q, theta).printvector();
    eth(theta, v, q).printvector();
    deth(theta, v, q).printvector();
    printV(printV(outputfile, eth(theta, v, q)), deth(theta, v, q));
    std::cout << "----------------------------------------------------\n";
    Vector3::showResult(eth(theta, v, q));
    Vector3::showResult(q.cross(v));
    Vector3::showResult(q.dot(v));
    Vector3::showResult(cos(theta ));
    Vector3::showResult(sin(theta ));
    std::cout << "angle\n";Vector3::showResult(eth(theta, v, q).angle(v));
    int steps = 100;
    for (int i = 0; i < steps; i++){
        float temp_angle = i*(theta/steps);
        Vector3 data = eth(temp_angle, v, q);
        printV(outputfile, data);
    }
    for (int i = 0; i < steps; i++){
        float temp_angle = i*(theta/steps);
        Vector3 data = deth(temp_angle, v, q);
        printV(outputfile, data);
    }
    Vector3 newv = v;
    for (int i = 0; i < steps; i++){
        float temp_angle = i*(theta/steps);
        newv = deth(temp_angle + theta/steps, v, q);
        printV(outputfile, newv.unitvector());
    }
}
