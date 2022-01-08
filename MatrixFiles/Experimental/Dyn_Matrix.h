#pragma once
#include <iostream>

template <int Rows, int Cols>
class Matrix{
public:
    float **matrix = new (std::nothrow) float*[Rows]{};

    Matrix(){
        for (int i = 0; i < Rows; i++){
            matrix[i] = new (std::nothrow) float[Cols]{};
        }
    }

    void input(){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                std::cin >> matrix[i][j];
            }
        }
    }

    void identity(){
        if (Rows != Cols){
            perror("Must be a square Matrix");
            return;
        }
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                matrix[i][j] = 0;
            }
            matrix[i][i] = 1;
        }
    }

    void showmtrx(){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    ~Matrix(){
        for (int i = 0; i < Rows; i++){
               delete[] matrix[i];
        }
        delete[] matrix;
    }
};
