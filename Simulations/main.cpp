#include <iostream>
#include "./CelestialBody.hpp"
#include "../VectorFiles/Vector2.hpp"
#include "../VectorFiles/Vector3.hpp"
#include "../VectorFiles/Vector4.hpp"
#include "../VectorFiles/Quaternion.hpp"
#include "../MatrixFiles/Matrix2x2.h"
#include "../MatrixFiles/Matrix3x3.h"
#include "../MatrixFiles/Matrix4x4.h"
#include <fstream>
#include <time.h>
#include <chrono>

template <class VectorType = Vector3>
std::ofstream& printV(std::ofstream& outputfile, const VectorType& vectordata) {
    if (!outputfile) { std::cerr << "error while outputting to file\n"; }
    static int num_calls = 0;
    num_calls++;
    if constexpr (std::is_same<VectorType, Vector3>::value){
        outputfile << num_calls << ", " << vectordata.x << ", " << vectordata.y << ", " << vectordata.z << '\n';
    }
    else if constexpr (std::is_same<VectorType, Vector2>::value) { 
        outputfile << vectordata.x << ", " << vectordata.y << ", " << 0 << '\n';
    }
    return outputfile;
}

template <class VectorDimension = Vector3>
std::ofstream& printP(std::ofstream& outputfile, const CelestialBody<VectorDimension>& planetdata) {
    if (!outputfile) { std::cerr << "error while outputting to file\n"; }
    if constexpr (std::is_same<VectorDimension, Vector3>::value) {
        outputfile << planetdata.position.x << ", " << planetdata.position.y << ", " << planetdata.position.z << " ID: " << planetdata.mass << '\n';
    }
    else if constexpr (std::is_same<VectorDimension, Vector4>::value) {
        outputfile << planetdata.position.x << ", " << planetdata.position.y << ", " << 0 << " ID: " << planetdata.mass << '\n';
    }
    return outputfile;
}


int main()
{
    constexpr const uint32_t num_of_planets = 2;
    CelestialBody<Vector3> Planets[num_of_planets] = {
        CelestialBody<Vector3>(6, Vector3(0.8, 0.8, 0.2), Vector3(0.03,-0.03,0)),
        //CelestialBody<Vector3>(8, Vector3(-0.8,-0.8,-0.2), Vector3(-0.03,0.03,0)),
        //CelestialBody<Vector3>(12, Vector3(0.6, 0.8, -0.2), Vector3(0.03, 0, -0.03)),
        //CelestialBody<Vector3>(18, Vector3(0.6, -0.8, 1), Vector3(0,0,0.03)),
        CelestialBody<Vector3>(100)
    };


    std::ofstream outputfile("OrbitalSimulation.csv");
    //outputfile << num_of_planets << '\n';

    outputfile << "count, x, y, z\n";
    constexpr const uint32_t steps = 1000;
    for (uint32_t i = 0; i < num_of_planets; i++) {
        printV(outputfile, Planets[i].position);
    }


    int num = 0;
    bool is_collided = false;
    for (uint32_t s = 0; s < steps; s++) {
        for (uint32_t i = 0; i < num_of_planets; i++) {
            for (uint32_t j = 0; j < num_of_planets; j++) {
                if (i != j) {
                    Planets[i].acceleration += Planets[i].phy_update_pairwise_force_interaction(Planets[j]);
                    is_collided |= Planets[i].phy_evaluate_pairwise_collision_factor(Planets[j]);
                }
            }
            if (is_collided == false && Planets[i].mass < 100) {
                CelestialBody<Vector3>::phy_update_pos(Planets[i]);
            }
            is_collided = false;
            if (s % 3 == 0) { 
                printV<Vector3>(outputfile, Planets[i].position);
                num++;
            }
        }
    }
    std::cout << num << '\n';
    outputfile.close();
}
