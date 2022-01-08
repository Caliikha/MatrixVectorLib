//#pragma GCC push_options
//#pragma GCC optimize("O0")
#include <iostream>
#include <chrono>
#include <fstream>
#include "../MatrixFiles/Matrix4x4.h"
#include "../MatrixFiles/Matrix3x3.h"
#include "../MatrixFiles/Matrix2x2.h"
#include "../MatrixFiles/Experimental/dyn_matrix.cpp"
#include "../VectorFiles/Vector2.h"
#include "../VectorFiles/Vector3.h"
#include "../VectorFiles/Vector4.h"
#include "../VectorFiles/Quaternion.h"

int max(const int& a, const int& b){
    switch (a > b){
        case true:
            return a;
        case false:
            return b;
    }
}
inline constexpr int test_max(const int& a, const int& b){
    switch (a > b){
        case true:
            return a;
        case false:
            return b;
    }
}

int main()
{
    std::cout << "Progress:\n";
    //std::ofstream outputfile("./Profiling/profile_data.txt");
    //assert(outputfile);
    //if (!outputfile) {std::cerr << "error while outputting to file\n";}
    const int test_cases = 500;
    for (int i = 0; i < test_cases; i++){
        unsigned long int limit = 10000000;//10000000;

        Vector3 v1 = {1, 3, 3};
        Vector3 axis = {1, 4, 6};
        Quaternion test_base = {1, 2, 3, 4};

        float angle = 0;//90*(PI/180);
        float theta = 2*PI;

        constexpr int test_cases = 30;
        for (int t = 1; t <= test_cases; t++){
            angle = i*(theta/t);
            auto start = std::chrono::high_resolution_clock::now();
            for (unsigned long int i = 0; i < limit; i++){
                max(2, 3);
                //v1.rotate(axis, angle);
                //M4_d * M4_d;
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> duration = end - start;

            auto dynamic = duration.count();

            start = std::chrono::high_resolution_clock::now();
            for (unsigned long int j = 0; j < limit; j++){
                test_max(2, 3);
                //v1.rodrigues_rotate(axis, angle);
                //v1.subtract(axis.scale(v1.dotproduct(axis))).scale(cos(angle)).add(axis.crossproduct(v1).scale(sin(angle))).add(axis.scale(axis.dotproduct(v1)));

                //M4 * M4;
            }
            end = std::chrono::high_resolution_clock::now();

            duration = end - start;

            auto stat = duration.count(); 

            //std::cout << "hamilton product time: " << dynamic << "\nnew method time: " << stat << "\nHamilton product is " << dynamic / stat << " times slower than new method\n";
            std::cout << "old product time: " << dynamic << "\nnew method time: " << stat << "\nold product is " << dynamic / stat << " times slower than new method\n";
            //outputfile << angle << '\n' << dynamic << '\n' << stat << '\n' << dynamic / stat << "\n\n";
            if (i % 150 == 0) { 
                std::cout << '.' << std::flush;
            }
        }
    }
    //outputfile.close();
    std::cout << "\nEnded process\n";
}
//    Matrix4x4 classic;
//
//    Matrix<4, 4> dynamic;
//
//    int array[16];
//
//    for (int i = 0; i < 16; i++){
//        array[i] = rand() % 10;
//    }
//
//    dynamic.define(array);
//    for (int i = 0; i < 4; i++){
//        for (int j = 0; j < 4; j++){
//            classic.matrix[i][j] = dynamic.matrix[i][j];
//        }
//    }
//
//    auto start = std::chrono::high_resolution_clock::now();
//    for (unsigned long int i = 0; i < limit; i++){
//        classic.multiply(classic);
//    }
//    auto end = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<float> duration = end - start;
//
//    float classic_time = duration.count();
//
//    start = std::chrono::high_resolution_clock::now();
//    for (unsigned long int i = 0; i < limit ; i++){
//        dynamic.multiply(dynamic);
//    }
//    end = std::chrono::high_resolution_clock::now();
//    duration = end - start;
//
//    float dynamic_time = duration.count();
//
//    std::cout << "Classic time: " << classic_time << "\nDynamic time: " << dynamic_time << "\nDynamic is " << dynamic_time / classic_time << " slower than classic\n";
//#pragma GCC pop_options
