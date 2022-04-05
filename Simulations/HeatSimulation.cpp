#include <iostream>
#include "HeatEquation.hpp"

int main()
{
    const constexpr uint64_t length = 10;
    const constexpr uint64_t resolution = 1;
    MaterialBody<Vector3, length, resolution> Aluminium;
    MaterialBody<Vector3, length, resolution> old;
    Aluminium.Material.printmtrx();
    const constexpr int steps = 10;
    for (int s = 0; s < steps; s++) {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                old.Material[i][j] = Aluminium.Material[i][j];
            }
        }
        for (int i = 1; i < length -1; i++) {
            for (int j = 1; j < length -1; j++) {
                Aluminium.Material[i][j] +=
                    old.Material[i+1][j] + old.Material[i-1][j] - 2*old.Material[i][j]
                   +old.Material[i][j+1] + old.Material[i][j-1] - 2*old.Material[i][j]
                   +old.Material[i][j] - Aluminium.Material[i][j];
            }
        }
        Aluminium.Material.printmtrx();
    }
}
