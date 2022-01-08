#include <iostream>
#include <assert.h>

template <int Rows, int Cols>
class Matrix{
public:
    float **matrix = new (std::nothrow) float*[Rows]{};

    Matrix(){
        for (int i = 0; i < Rows; i++){
            matrix[i] = new (std::nothrow) float[Cols]{};
        }
    }

    Matrix(std::initializer_list<float> input) {
        assert(input.size() <= Rows*Cols);
        int index_j = 0;
        int index_i = 0;
        for (auto i : input){
            matrix[index_i][index_j] = i;
            if (index_j == Cols - 1){
                index_j = 0;
                index_i++;
            }
            if (index_i == Rows - 1){
                index_i = 0;
            }
        }
    }

    void input(){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                std::cin >> matrix[i][j];
            }
        }
    }

    template<typename TYPE>
        void define(TYPE inputSet[]){ // definitely not working
            //        int length = sizeof(inputSet) / sizeof(inputSet[0]);
            //        if ((Rows * Cols) > length){
            //            std::cout << Rows*Cols << "  " << length << "\n";
            //            std::cout << "Error, array input must be of minimum size [Rows * Cols] of matrix object\n";
            //            return;
            //        }
            if (typeid(TYPE).name() == typeid(int).name() || typeid(TYPE).name() == typeid(float).name() || typeid(TYPE).name() == typeid(double).name()){
                int inputSize = 0;
                for (int i = 0; i < Rows; i++){
                    for (int j = 0; j < Cols; j++){
                        matrix[i][j] = inputSet[inputSize];
                        inputSize++;
                    }
                }
            }
            else {
                std::cerr << "Error, array input must be of type INT, FLOAT, or DOUBLE\n";
                return;
            }
        }

    void identity(){
        if (Rows != Cols){
            std::cerr << "Error, identity() must only be used with square matrices\n";
            return;
        }
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                matrix[i][j] = 0;
            }
            matrix[i][i] = 1;
        }
    }

    template<typename TYPE>
    void printvalue(TYPE &value){
        std::cout << value << '\n';
    }

    void printmtrx(){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << '\n';
    }

    template<typename TYPE>
    static void showResult(TYPE &input){
        std::cout << input << "\n";
    }

    static void showResult(Matrix<Rows, Cols> &mtrx){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                std::cout << mtrx.matrix[i][j] << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    Matrix<Rows, Cols> scale(float &scale){
        Matrix<Rows, Cols> resultMtrx;

        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                resultMtrx.matrix[i][j] = scale * matrix[i][j];
            }
        }
        return resultMtrx;
    }

    Matrix<Rows, Cols> multiply(Matrix<Rows, Cols> &inputmtrx){
        Matrix<Rows, Cols> resultMtrx = {};

        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                for (int k = 0; k < Rows; k++){
                     resultMtrx.matrix[i][j] += matrix[i][k] * inputmtrx.matrix[k][j];
                }
            }
        }
		return resultMtrx;
	}

    Matrix<Rows, Cols> add(Matrix<Rows, Cols> &inputmtrx){
        Matrix<Rows, Cols> resultMtrx;
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                resultMtrx.matrix[i][j] = matrix[i][j] + inputmtrx.matrix[i][j];
            }
        }
        return resultMtrx;
    }

    Matrix<Rows, Cols> subtract(Matrix<Rows, Cols> &inputmtrx){
        Matrix<Rows, Cols> resultMtrx;
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                resultMtrx.matrix[i][j] = matrix[i][j] - inputmtrx.matrix[i][j];
            }
        }
        return resultMtrx;
    }

    Matrix<Rows, Cols> transpose(){
        Matrix<Rows, Cols> resultMtrx;

        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                resultMtrx.matrix[j][i] = matrix[i][j];
            }
        }
        return resultMtrx;
    }

    Matrix<Rows, Cols> operator*(Matrix<Rows, Cols>& right) {
        return multiply(right);
    }

    ~Matrix(){
        for (int i = 0; i < Rows; i++){
               delete[] matrix[i];
        }
        delete[] matrix;
    }
};

//int main()
//{
//    const int rows = 10, cols = 10;
//    Matrix<rows, cols> mtrx;
//    int array[(rows * cols)];
//    int length = sizeof(array) / sizeof(array[0]);
//
//    std::cout << length << "\n";
//    for (int i = 0; i < length; i++){
//        array[i] = i;
//    }
//    mtrx.define(array);
//    mtrx.printmtrx();
//    mtrx.transpose().printmtrx();
//
//

//    const int rows = 5, cols = 5;
//    int array[rows*cols];
//
//    for (int i = 0; i < rows*cols; i++){
//        array[i] = rand() % 200 + 1;
//    }
//    Matrix<rows, cols> mtrx;
//    mtrx.define(array);
//    mtrx.multiply(mtrx).printmtrx();

//    for (int i = 0; i < 20; i++){
//        for (int j = 0; j < 20; j++){
//            mtrx.matrix[i][j] = 0;
//        }
//    }
//    
//    mtrx.printmtrx();
//
//    int offset = 0;
//    for (int i = 0; i < 1; i++){
//        for (int j = 0; j < 1; j++){
//           mtrx.matrix[i + offset][j + offset] = 1;
//           offset++; 
//        }
//    }
//}
