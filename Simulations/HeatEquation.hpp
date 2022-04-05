#pragma once
#include <iostream>
#include "../VectorFiles/Vector3.hpp"
#include <cmath>
#include "../MatrixFiles/Experimental/Dynamic_Matrix.hpp"

#define DBL_EPSILON sqrt(10e-8)

template <auto expr>
constexpr const auto compiler_evaluation() { return expr; }

template <class VectorDimension = Vector3>
struct NumericConstants {
    static constexpr const VectorDimension Epislon_Difference = VectorDimension(DBL_EPSILON, DBL_EPSILON, DBL_EPSILON);
    static constexpr const uint32_t Aluminium_Diffusivity = 97;
};

template <class VectorDimension = Vector3, uint32_t Side_Length = 200, uint32_t Point_Density_Resolution = 1>
class MaterialBody {
public:
    Matrix<Side_Length, Side_Length> Material;

    constexpr MaterialBody() {
        this->Material[Side_Length-2][Side_Length-2] = 200;
    }

    static inline float phy_update_temp(MaterialBody<Vector3, Side_Length, Point_Density_Resolution>& input, const uint32_t& x_coord, const uint32_t& y_coord) {
        static MaterialBody<Vector3, Side_Length, Point_Density_Resolution> original = input;
        const float temperature_difference = pow(NumericConstants<Vector3>::Aluminium_Diffusivity, 2)
                                                        *(input.Material[x_coord + Point_Density_Resolution][y_coord]
                                                                - input.Material[x_coord - Point_Density_Resolution][y_coord]
                                                                - input.Material[x_coord][y_coord + Point_Density_Resolution]
                                                                - input.Material[x_coord][y_coord - Point_Density_Resolution]
                                                                - input.Material[x_coord + Point_Density_Resolution][y_coord + Point_Density_Resolution]
                                                                - input.Material[x_coord + Point_Density_Resolution][y_coord - Point_Density_Resolution]
                                                                - input.Material[x_coord - Point_Density_Resolution][y_coord + Point_Density_Resolution]
                                                                - input.Material[x_coord - Point_Density_Resolution][y_coord - Point_Density_Resolution]
                                                                + 2*input.Material[x_coord][y_coord]
                                                         );
        //return input.Material[x_coord][y_coord] -= temperature_difference;

//        return input.Material[x_coord][y_coord] += (input.Material[x_coord + Point_Density_Resolution][y_coord]
//                                                                + input.Material[x_coord - Point_Density_Resolution][y_coord]
//                                                                + input.Material[x_coord][y_coord + Point_Density_Resolution]
//                                                                + input.Material[x_coord][y_coord - Point_Density_Resolution]
//                                                                //- input.Material[x_coord + Point_Density_Resolution][y_coord + Point_Density_Resolution]
//                                                                //- input.Material[x_coord + Point_Density_Resolution][y_coord - Point_Density_Resolution]
//                                                                //- input.Material[x_coord - Point_Density_Resolution][y_coord + Point_Density_Resolution]
//                                                                //- input.Material[x_coord - Point_Density_Resolution][y_coord - Point_Density_Resolution]
//                                                                - 2*input.Material[x_coord][y_coord]);
        return
            input.Material[x_coord][y_coord] +=
            input.Material[x_coord + 1][y_coord] - 2*input.Material[x_coord][y_coord] + input.Material[x_coord - 1][y_coord]
           +input.Material[x_coord][y_coord+1] - 2*input.Material[x_coord][y_coord] + input.Material[x_coord][y_coord - 1]
           -original.Material[x_coord][y_coord];
    }

    MaterialBody<VectorDimension, Side_Length, Point_Density_Resolution> operator=(MaterialBody<VectorDimension, Side_Length, Point_Density_Resolution>& right) {
        for (int i = 0; i < Side_Length; i++) {
            for (int j = 0; j < Side_Length; j++) {
                this->Material[i][j] = right.Material[i][j];
            }
        }
    }
};


//template <const uint32_t x_coord, const uint32_t y_coord, class VectorDimension = Vector3, uint32_t Side_Length = 200, uint32_t Point_Density = 50>
//constexpr Vector3 MaterialBody<VectorDimension, Side_Length, Point_Density>::phy_update_temp(MaterialBody<VectorDimension, Side_Length, Point_Density>& input) {
//    const constexpr Vector3 temperature_difference = Vector3();
//}
